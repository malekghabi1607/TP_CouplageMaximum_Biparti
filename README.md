
# Couplage Maximum - Graphe Biparti

Projet en C++ permettant de résoudre le problème du **couplage maximum dans un graphe biparti** à l'aide de l'algorithme de **Ford-Fulkerson**.

---

## 📌 Objectif

Déterminer le plus grand nombre d'arêtes disjointes entre deux ensembles de sommets (A et B), représentés sous forme de graphe biparti.

---

## ⚙️ Fonctionnalités

- Construction d’un réseau de flot à partir d’une matrice d’adjacence bipartie.
- Implémentation de l’algorithme de Ford-Fulkerson.
- Calcul automatique du couplage maximal.

---

## 📁 Structure du projet

- `main.cpp` : point d’entrée avec vos propres tests
- `utilities.cpp` : implémentation des fonctions principales
- `utilities.h` : déclaration des fonctions
- `README.md` : ce fichier

---

## ▶️ Exécution

```bash
g++ main.cpp utilities.cpp -o couplage
./couplage
```
