
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

---

## 🔎 Résultats attendus

- Affichage de la matrice des liaisons bipartites (AB).
- Construction des matrices de capacité et de flot initialisées à 0.
- Calcul du flot maximum entre la source et le puits via Ford-Fulkerson.
- Affichage du couplage maximum (égal au flot maximum trouvé).
- Affichage des matrices finales après exécution.

### 📸 Capture d’écran du résultat :

<img width="328" alt="Capture d’écran 2025-03-29 à 10 41 36" src="https://github.com/user-attachments/assets/05000e0e-413a-479b-a754-30d073176498" />


---

## 👤 Auteur

**Malek** – Licence 2 Informatique  
Université d’Avignon – Année 2024/2025

