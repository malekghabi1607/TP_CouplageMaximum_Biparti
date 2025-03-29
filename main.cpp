
#include <iostream>
#include "utilities.h"

using namespace std;

int main()
{
    cout << "test:" << endl;
    int na = 5; // car on a 5 sommets dans a
    int nb = 4; // car on a 4 sommets dans b

    int **ab = new int *[na]; // tableau de pointures
    int mat[5][4] = {
        {1, 2, 2, 1},
        {1, 0, 1, 0},
        {0, 1, 3, 1},
        {0, 0, 1, 1},
        {0, 0, 1, 0}};

    for (int i = 0; i < na; i++)
    {
        ab[i] = new int[nb]; // allocations d;une ligne
        for (int j = 0; j < nb; j++)
        {
            ab[i][j] = mat[i][j]; // copie des valeurs
        }
    }

    affichage_biparti(ab, na, nb);
    int max_couplage = couplagemax(ab, na, nb); // calcul du couplage maximum en utilisant la fonction couplagemax
    cout << "Le couplage maximum est : " << max_couplage << endl;

    for (int i = 0; i < na; i++)
        delete[] ab[i]; // supprimer chaque ligne
    delete[] ab;        // supp le tableau de pointeurs

    return 0;
}
