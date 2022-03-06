# Projet de Synthèse

## Premier Pas vers l'Ingénierie du Logiciel

---

JEAN Thiebault, TEITER Hugo

### Environement de développement

Ce projet a été conçu pour fonctionner sous Linux, plus particulièrement Ubuntu.
Le protocole TCP implémenté dans notre code ne pourra pas se lancer sous Windows car il n'utilise pas les mêmes bibliothèques.
De plus, la bibliothèque graphique du serveur Java n'a pas étés testé sous autre chose que Linux. 
Même si en principe cette bibliothèque (Swing) est cross-platform, nous ne pouvons pas garantir qu'elle fonctionnera comme sur notre machine de test.

### Compilation et lancement du projet

La compilation de la partie C++ de ce projet c'est faite grace à un fichier Makefile. 
Pour pouvoir compiler la partie C++ il suffit d'aller dans le dossier *Client* dans un terminal et de taper la commande : ```make```.
Pour pouvoir lancer le programme il faudra taper : ```make run```.
Enfin, pour pouvoir nettoyer les fichiers créés lors de la compilation il faudra utiliser : ```make clean```.

Pour la partie Java, nous avons utilisé l'IDE Eclipse pour la compilation et le lancement, il faudra donc ouvrir le dossier *Server* dans Eclipse et simplement Appuyer sur *Run*.

À noter que pour que la communication se fasse correctement il faudra ouvrir le serveur Java avant de lancer le moindre client C++, pour qu'il puisse se mettre à écouter les potentielles requêtes envoyées, puis le laisser tourner tant que l'on veut afficher des formes avec différents clients C++.

---

Compléments du rapport de Projet - JEAN Thiebault - TEITER Hugo
