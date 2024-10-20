# Turbo Snake

Ce projet est une implémentation du jeu classique Snake dans un style simpliste en utilisant SDL2 pour le rendu graphique. Le jeu est écrit en C et utilise une structure de liste chaînée pour gérer les segments du serpent. 
Le jeu contient un petit objectif bonus le différenciant du Snake classique puisqu'en effet à chaque pomme mangée le serpent accélère donc la gestion de la vitesse est de plus en plus compliquée ! 

## Structure du projet

Le projet a la structure suivante :

## Fichiers

- **corps.c** : Contient les fonctions pour ajouter et enlever des segments du corps du serpent.
- **main.c** : Contient la fonction principale du programme.
- **makefile** : Fichier Makefile pour compiler le projet.
- **sdl.c** : Contient les fonctions d'initialisation et de nettoyage de SDL.
- **snake** : Exécutable du jeu.
- **snake.c** : Contient la logique principale du jeu.
- **snake.h** : Fichier d'en-tête contenant les déclarations de fonctions et les définitions de structures.

## Compilation

Pour compiler le projet, utilisez le fichier Makefile fourni. Assurez-vous d'avoir SDL2 et SDL2_image installés sur votre système.

```make```

## Exécution

Pour compiler le projet, utilisez le fichier Makefile fourni. Assurez-vous d'avoir SDL2 et SDL2_image installés sur votre système.

```./snake```

## Fonctionnalités

- **Déplacement** : Utilisez les touches `W`, `A`, `S`, `D` ou `Z`, `Q`, `S`, `D` selon votre clavier pour déplacer le serpent.
- **Collision avec les bords** : Le jeu se termine si le serpent entre en collision avec les bords de l'écran.
- **Collision avec le corps** : Le jeu se termine si le serpent entre en collision avec son propre corps.
- **Pomme** : Le serpent grandit lorsqu'il mange une pomme, et une nouvelle pomme est générée à une position aléatoire qui n'est pas occupée par le serpent.
- **Ajout de segments** : Un nouveau segment de corps est ajouté à la fin du serpent lorsque celui-ci mange une pomme.
- **Vitesse croissante** : La vitesse grandit au fur et à mesure que les pommes sont mangées par votre serpent

## Merci
