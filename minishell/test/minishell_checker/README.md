
# Testeur Minishell

Ce dossier contient un testeur pour le projet Minishell. Suivez les étapes ci-dessous pour l'utiliser.

## Prérequis
- CMake installé sur votre machine.
- Le projet Minishell doit être compilé et fonctionnel.

## Instructions

1. Placez le dossier `test_minishell` à la racine de votre projet Minishell.
2. Compilez le testeur en utilisant CMake :
   ```sh
   mkdir build && cd build
   cmake ..
   make
   ```
3. Lancer les tests de la partie **obligatoire** :
   ```sh
   ./run_tests
   ```
4. Si tous les tests de la partie obligatoire passent, vous pouvez lancer les tests **bonus** :
   ```sh
   ./run_bonus_tests
   ```

### Résultats des tests
- Si tous les tests de la partie obligatoire passent, le projet est conforme pour la partie de base.
- Pour la partie bonus, un message indiquera si les bonus sont réalisés et complets.

## Notes
- Les tests sont basés sur des commandes simples pour vérifier les fonctionnalités demandées.
- En cas d'échec d'un test, vérifiez votre implémentation pour respecter les spécifications du sujet.
