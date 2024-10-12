#ifndef HEADER_H
#define HEADER_H

#include <stdio.h> //Librairie utile
#include <stdlib.h>//Librairie utile
#include <time.h>//Librairie utile

typedef struct { //Declaration de la structure pour localiser le joueur et son mouvement
    int x;
    int y;
    char mouvement;
} PositionJoueur;

typedef struct { //Declaration de la structure pour localiser la boite
    int x;
    int y;
} PositionBoite;

typedef struct { //Declaration de la structure pour localiser l'emplacement
    int x;
    int y;
} PositionEntre;


#endif