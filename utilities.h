
#ifndef _UTIL_H_
#define _UTIL_H_

void affichage(int* c[], int* f[], int n);
void affichage_biparti(int *ab[],int na, int nb);
bool chaineaugmentante(int* c[], int* f[], int n, int ch[],int s, int t, bool visite[]);
int increment(int* c[], int* f[], int n, int ch[], int s, int t);
int fordfulkerson(int* c[], int* f[], int n, int s, int t);
int couplagemax(int *ab[],int na, int nb);

#endif

