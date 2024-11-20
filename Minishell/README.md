# 42 Minishell

Bienvenue dans le projet Minishell, une reproduction simplifiée du shell Unix, développée dans le cadre du cursus 42. Ce projet a pour objectif de comprendre les mécanismes internes d'un shell, tels que la gestion des processus, des signaux, des redirections et des pipelines.

## Fonctionnalités

- Exécution de commandes Unix simples et pipelines.
- Gestion des signaux (Ctrl-C, Ctrl-D, Ctrl-\).
- Gestion des redirections (`<`, `>`, `>>`).
- Variables d'environnement et gestion du `$PATH`.
- Implémentation des builtins : `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`.

## Compilation et Exécution

Pour compiler et exécuter Minishell :

```bash
make
./minishell
```


## Structure du Projet

- **Minishell/** : Contient le code source du shell.
- **Doc/** : Documentation et notes du projet.
- **test_minishell/** : Scripts de test pour vérifier le comportement du shell.

## Licence

Ce projet est sous licence MIT. Voir le fichier [LICENSE](LICENSE) pour plus de détails.

## Auteurs

- [Yoan Onieva](https://github.com/Yonieva)
- [Gauthier Esteve](https://github.com/gaesteve42)
- [Kévin Pourcel](https://github.com/Middle-555)
- [Adrien Cabarbaye](https://github.com/Demiaeuw)
