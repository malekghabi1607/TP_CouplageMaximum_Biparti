
#include <iostream>
#include <fstream>
#include <stack>
#include "utilities.h"

using namespace std;

/****************************************************/
/* Affichage de la matrice de capacité c            */
/* et de la matrice de flots f			    */
/****************************************************/
void affichage(int* c[], int* f[], int n)
{
	cout << "c = " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n-1); j++)
			cout << c[i][j] << "\t";
		cout << c[i][n-1] << endl;		
	}
	
	
	cout << endl << "f = " << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n-1); j++)
			cout << f[i][j] << "\t";
		cout << f[i][n-1] << endl;		
	}
}

/****************************************************/
/* Affichage de la matrice d'adjacence "ab"         */
/* du graphe biparti				    */
/****************************************************/
void affichage_biparti(int *ab[],int na, int nb)
{
	cout << "AB = " << endl;
	for(int i = 0; i < na; i++){
		for(int j = 0; j < (nb-1); j++)
			cout << ab[i][j] << "\t";
		cout << ab[i][nb-1] << endl;		
	}	
}

	
/****************************************************/
/* Entrées :                                        */
/* c : matrice des capacités des arcs du réseau     */
/* f : matrice des flots sur les arcs               */
/* n : nombre de noeuds du réseau                   */
/* s : sommet source                                */                            
/* t : sommet destination                           */
/* visite : tableau permettant de marquer les       */
/* sommets visites				    */
/****************************************************/
/* Sorties : 					    */
/* - ch : chaîne augmentante de s à t        	    */
/* (s'il en existe)                                 */
/* - La fonction renvoie vrai si une chaîne 	    */
/* augmentante a été trouvée et faux sinon	    */
/****************************************************/
/* A RECOPIER DE VOS ANCIENS CODES		    */
/****************************************************/
/****************************************************/
bool chaineaugmentante(int* c[], int* f[], int n, int ch[], int s, int t, bool visite[])
{
    visite[s] = true; // Marquer le point de départ comme visité

    if (s == t) return true; // Si on est déjà à l'arrivée, on a trouvé un chemin

    // Explorer tous les voisins du sommet s
    for (int v = 0; v < n; v++) 
    {
        int residuel = c[s][v] - f[s][v]; // Capacité disponible pour aller de s à v

        if (!visite[v] && residuel > 0) { // Si le sommet v n’a pas été visité et qu’il reste de la capacité
            visite[v] = true;     // On le marque comme visité
            ch[v] = s;            // On se souvient qu’on est arrivé à v depuis s
            if (chaineaugmentante(c, f, n, ch, v, t, visite)) // On continue la recherche à partir de v
                return true; // Si on trouve un chemin complet, on retourne vrai
        }
    }
	return false; // Aucun chemin trouvé depuis ce sommet
}
	
/****************************************************/
/* Entrées :                                        */
/* c : matrice des capacités des arcs du réseau     */
/* f : matrice des flots sur les arcs               */
/* n : nombre de noeuds du réseau                   */
/* s : sommet source                                */                            
/* t : sommet destination                           */
/* ch : chaîne augmentante de s à t                 */
/* Sortie : valeur d'augmentation du flot           */
/****************************************************/
/* A RECOPIER DE VOS ANCIENS CODES		    */
/****************************************************/
int increment(int* c[], int* f[], int n, int ch[], int s, int t)
{
    int flux = 1000000; // Valeur très grande pour commencer

    // Trouver la plus petite capacité disponible sur le chemin (goulot d'étranglement)
    for (int v = t; v != s; v = ch[v]) 
    {
        int u = ch[v];
        flux = min(flux, c[u][v] - f[u][v]);
    }

    // Mettre à jour les flots le long du chemin trouvé
    for (int v = t; v != s; v = ch[v])
    {
        int u = ch[v];
        f[u][v] += flux; // On augmente le flot dans le bon sens
        f[v][u] -= flux; // On diminue dans l'autre sens (utile pour le retour)
    }

	return flux; // Retourner combien on a ajouté au flot total
}
	
/****************************************************/
/* Entrées :                                        */
/* c : matrice des capacités des arcs du réseau     */
/* f : matrice des flots sur les arcs               */
/* n : nombre de noeuds du réseau                   */
/* s : sommet source                                */                            
/* t : sommet destination                           */
/* Sortie : Flot Max de s à t                       */
/****************************************************/
/* A RECOPIER DE VOS ANCIENS CODES		    */
/****************************************************/
int fordfulkerson(int* c[], int* f[], int n, int s, int t)
{
    int flot_max = 0;      // Variable pour stocker le flot total
    int ch[n];             // Tableau pour reconstruire le chemin
    bool visite[n];        // Tableau pour savoir quels sommets ont été visités

    while (true)  // Répéter tant qu’on trouve un chemin
    {
        // Réinitialiser les tableaux
        for (int i = 0; i < n; i++) {
            visite[i] = false;
            ch[i] = -1;
        }

        if (!chaineaugmentante(c, f, n, ch, s, t, visite)) 
            break; // Si plus de chemin possible, on s'arrête

        flot_max += increment(c, f, n, ch, s, t); // Ajouter le flux du nouveau chemin
    }

    cout << "\nFlot maximum : " << flot_max << endl;
    
	return flot_max; // Retourner le résultat final
}


/****************************************************/
/* Entrées :                                        */
/* - ab : matrice d'adjacence du graphe biparti	    */
/* Il contient na lignes et nb colonnes 	    */
/* - ab[i][j] = 1 si l'arête (i,j) existe où i 	    */
/* appartient à A et j appartient à B		    */
/****************************************************/
/* - na : nombre d'éléments du premier ensemble A   */
/* les sommets de A sont numérotés 0,...,na-1	    */
/* - nb : nombre d'éléments du premier ensemble B   */
/* les sommets de B sont numérotés 0,...,nb-1	    */
/* Sortie : Nombre maximum d'arêtes disjointes      */
/****************************************************/
/* A FAIRE					    */
/****************************************************/
/****************************************************/
int couplagemax(int *ab[], int na, int nb)
{
	int n = na + nb + 2; // Total de sommets (ensemble A + B + source + puits)
    int s = 0;           // La source (sommet 0)
    int t = n - 1;       // Le puits (dernier sommet)

    // Initialiser les matrices de capacité et de flot
    int** c = new int*[n];
    int** f = new int*[n];
    for (int i = 0; i < n; i++) {
        c[i] = new int[n]{0}; // Initialisé à 0
        f[i] = new int[n]{0}; // Initialisé à 0
    }

    // Ajouter des arcs entre la source et chaque sommet de A
    for (int i = 0; i < na; i++)
        c[s][1 + i] = 1;

    // Ajouter des arcs entre chaque sommet de B et le puits
    for (int j = 0; j < nb; j++)
        c[1 + na + j][t] = 1;

    // Ajouter des arcs entre les sommets de A et B s’il y a une liaison
    for (int i = 0; i < na; i++)
        for (int j = 0; j < nb; j++)
            if (ab[i][j] == 1)
                c[1 git add utilities.cpp
git commit -m "Implémentation complète de Ford-Fulkerson et Couplage Maximum - by Malek"
git push
+ i][1 + na + j] = 1;

    // Appeler fordfulkerson pour calculer le couplage maximum
    int result = fordfulkerson(c, f, n, s, t);

    // Libérer la mémoire
    for (int i = 0; i < n; i++) {
        delete[] c[i];
        delete[] f[i];
    }
    delete[] c;
    delete[] f;

    return result; // Retourner le couplage maximum
}
