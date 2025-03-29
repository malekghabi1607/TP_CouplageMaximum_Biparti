
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
bool chaineaugmentante(int* c[], int* f[], int n, int ch[],int s, int t, bool visite[])
{
	return(0);
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
	return(0);
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
	return(0);
	
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
int couplagemax(int *ab[],int na, int nb)
{
	return(0);
}


