# Antman
Algorithme de compression de fichiers : Burrows-Willer transform combiné avec le Run-Length-Encoding

COMPILATION

    make

USAGE

    ./antman [fichier]
    ./giantman [fichier]

DESCRIPTION

    [fichier] fichier à compresser/décompresser

    antman -> compression
    giantman -> décompression

DETAILS

    Algorithmes : Burrows-Willer Transform et Run length Encoding
    
    Burrows Willer Transform est un algorithme de groupement de caractères par valeurs
    qui est réversible avec un seul caractère grâce à des propriétés de l'encodage.
    Il ne compresse pas mais permet de générer des fichiers plus facile à compresser.
    Il est ici combiné au Run-Length-Encoding, qui va compacter les longues suites du même caractère

Projet EPITECH réalisé par Edouard CHHANG et Ethan HARY

Répartition des tâches :

Edouard CHHANG : Recherche d'algorithme, Implémentation de Run-Length-encoding et du décoder Burrows-Willer Transform
Ethan HARY : Implémentation de l'encodeur Burrows-Willer Transform
