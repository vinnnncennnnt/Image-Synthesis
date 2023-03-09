# M1-Projet-APA

You will need ```libtiff``` and ```libxt```.

To build the project :

```
$ make tp
```

How to use it :
```
$ ./tp --help
```
```
Accepte jusqu'a 6 parametres :
 fichier image, defaut : gravier.tif
 numero de l'algorithme, defaut : 0
 racine du nombre de blocs, defaut : 3
 taille de la zone de recouvrement, defaut : 20
 largeur de l'image de sortie, defaut : 600
 hauteur de l'image de sortie, defaut : 600

Algorithmes :
 0 : bloc au hasard, raccord simple
 1 : bloc au hasard avec le permuteur, raccord simple
 2 : meilleur bloc, raccord simple
 3 : raccord avec coupe optimale (recursif naif)
 4 : raccord avec coupe optimale (recursif utilisable)
 5 : raccord avec coupe optimale (iteratif)
```

