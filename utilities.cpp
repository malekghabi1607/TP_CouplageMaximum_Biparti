#include <iostream>
#include <fstream>
#include <stack>
#include "utilities.h"
#include <queue>   // Pour utiliser la file d'attente
#include <cstring> // Pour memset

using namespace std;

/***************************************************
 * Fonction pour afficher les matrices c (capacités)
 * et f (flots) pour visualiser le graphe.
 ***************************************************/
void affichage(int *c[], int *f[], int n)
{
    cout << "c = " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - 1); j++)
            cout << c[i][j] << "\t";
        cout << c[i][n - 1] << endl;
    }

    cout << endl
         << "f = " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - 1); j++)
            cout << f[i][j] << "\t";
        cout << f[i][n - 1] << endl;
    }
}

/****************************************************
 * Fonction pour afficher le graphe biparti ab.
 * C'est une matrice avec 1 si une liaison existe.
 ****************************************************/
void affichage_biparti(int *ab[], int na, int nb)
{
    cout << "AB = " << endl;
    for (int i = 0; i < na; i++)
    {
        for (int j = 0; j < (nb - 1); j++)
            cout << ab[i][j] << "\t";
        cout << ab[i][nb - 1] << endl;
    }
}

/****************************************************
 * Fonction qui cherche un chemin augmentant
 * entre le sommet s (départ) et t (arrivée).
 * Elle utilise un parcours en profondeur (DFS).
 ****************************************************/
bool chaineaugmentante(int *c[], int *f[], int n, int ch[], int s, int t, bool visite[])
{
    visite[s] = true;

    if (s == t)
        return true;

    for (int v = 0; v < n; v++)
    {
        int residuel = c[s][v] - f[s][v];
        if (!visite[v] && residuel > 0)
        {
            visite[v] = true;
            ch[v] = s;
            if (chaineaugmentante(c, f, n, ch, v, t, visite))
                return true;
        }
    }
    return false;
}

/****************************************************
 * Fonction qui met à jour le flux (f) sur le chemin
 * trouvé. Elle retourne la valeur du flux ajouté.
 ****************************************************/
int increment(int *c[], int *f[], int n, int ch[], int s, int t)
{
    int flux = 1000000;

    for (int v = t; v != s; v = ch[v])
    {
        int u = ch[v];
        flux = min(flux, c[u][v] - f[u][v]);
    }

    for (int v = t; v != s; v = ch[v])
    {
        int u = ch[v];
        f[u][v] += flux;
        f[v][u] -= flux;
    }

    return flux;
}

/****************************************************
 * Fonction principale de Ford-Fulkerson.
 * Utilise chaineaugmentante + increment.
 ****************************************************/
int fordfulkerson(int *c[], int *f[], int n, int s, int t)
{
    int flot_max = 0;
    int ch[n];
    bool visite[n];

    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            visite[i] = false;
            ch[i] = -1;
        }

        if (!chaineaugmentante(c, f, n, ch, s, t, visite))
            break;

        flot_max += increment(c, f, n, ch, s, t);
    }

    cout << "\nFlot maximum : " << flot_max << endl;
    return flot_max;
}

/****************************************************
 * Fonction pour résoudre le problème du couplage
 * maximum dans un graphe biparti.
 ****************************************************/
int couplagemax(int *ab[], int na, int nb)
{
    int n = na + nb + 2;
    int s = 0;
    int t = n - 1;

    int **c = new int *[n];
    int **f = new int *[n];
    for (int i = 0; i < n; i++)
    {
        c[i] = new int[n];
        f[i] = new int[n];
        memset(c[i], 0, n * sizeof(int));
        memset(f[i], 0, n * sizeof(int));
    }

    for (int i = 0; i < na; i++)
        c[s][1 + i] = 1;

    for (int j = 0; j < nb; j++)
        c[1 + na + j][t] = 1;

    for (int i = 0; i < na; i++)
        for (int j = 0; j < nb; j++)
            if (ab[i][j] == 1)
                c[1 + i][1 + na + j] = 1;

    int result = fordfulkerson(c, f, n, s, t);

    for (int i = 0; i < n; i++)
    {
        delete[] c[i];
        delete[] f[i];
    }
    delete[] c;
    delete[] f;

    return result;
}
