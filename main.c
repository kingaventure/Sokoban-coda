#include "header.h"

void startPlateau(char plateau[10][10]) {
  for (int i = 0; i < 10; i++) { 
    for (int j = 0; j < 10; j++) { 
      if(i == 0 || i == 9){
        plateau[i][j]= '#';
      }
      else if(j == 0 || j == 9){
        plateau[i][j]= '#';
      }
      else {
        plateau[i][j] = ' ';
      }
    }
  }

}
void afficherPlateau(char plateau[10][10]) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%c", plateau[i][j]);
    }
    printf("\n");
  }
}
void spawnJoueur(char plateau[10][10], PositionJoueur* joueurPos) {
  int x, y;
  do {
    x = rand() % 6 + 2; 
    y = rand() % 6 + 2; 
  } while (plateau[x][y] != ' ');

  plateau[x][y] = 'o';  
  joueurPos->x = x;  
  joueurPos->y = y;  
}
void spawnBoite(char plateau[10][10], PositionBoite* boitePos) {
  int x, y;
  do {
    x = rand() % 6 + 2; 
    y = rand() % 6 + 2; 
  } while (plateau[x][y] != ' ');

  plateau[x][y] = 'X';  
  boitePos->x = x;  
  boitePos->y = y;  
}
void spawnEmplacement(char plateau[10][10], PositionEntre* entrePos) {
  int x, y;
  do {
    x = rand() % 6 + 2; 
    y = rand() % 6 + 2; 
  } while (plateau[x][y] != ' ');

  plateau[x][y] = '.';  
  entrePos->x = x;  
  entrePos->y = y;  
}
void spawn(char plateau[10][10], PositionJoueur* joueurPos, PositionBoite* boitePos, PositionEntre* entrePos) {
    spawnJoueur(plateau, joueurPos);
    spawnBoite(plateau, boitePos);
    spawnEmplacement(plateau, entrePos);
}
void joueurMouvement(char plateau[10][10], PositionJoueur* joueurPos,  PositionEntre* entrePos) {
  printf("Entrez un mouvement : Haut (z), Bas (s), Gauche (q), Droite (d) \n");
  scanf(" %c", &joueurPos->mouvement);
  int deplacement_x = joueurPos->x;
  int deplacement_y = joueurPos->y;

  if (joueurPos->mouvement == 'z') {
    deplacement_x--; 
  } else if (joueurPos->mouvement == 's') {
    deplacement_x++; 
  } else if (joueurPos->mouvement == 'q') {
    deplacement_y--; 
  } else if (joueurPos->mouvement == 'd') {
    deplacement_y++; 
  } else {
    printf("Mouvement non valide !\n");
    return;
  }

  if (plateau[deplacement_x][deplacement_y] == ' '|| plateau[deplacement_x][deplacement_y] == '.') {
    plateau[joueurPos->x][joueurPos->y] = ' ';
    plateau[deplacement_x][deplacement_y] = 'o';
    joueurPos->x = deplacement_x;
    joueurPos->y = deplacement_y;
  }
  if(plateau[entrePos->x][entrePos->y] == ' '){
    plateau[entrePos->x][entrePos->y] = '.';
  }
}
void boitemouvement(char plateau[10][10], PositionBoite* boitePos, PositionJoueur* joueurPos, PositionEntre* entrePos) {
  int deplacement_x = boitePos->x;
  int deplacement_y = boitePos->y;

  if (joueurPos->x == boitePos->x - 1 && joueurPos->y == boitePos->y && joueurPos->mouvement == 's') {
    deplacement_x++;
    if (plateau[deplacement_x][deplacement_y] == ' ' || '.') {
      plateau[boitePos->x][boitePos->y] = ' ';
      plateau[deplacement_x][deplacement_y] = 'X';
      boitePos->x = deplacement_x;
      plateau[joueurPos->x][joueurPos->y] = ' ';
      joueurPos->x++; 
      plateau[joueurPos->x][joueurPos->y] = 'o';
    } else {
      printf("Impossible de bouger la boîte vers le bas !\n");
    }
  }
  else if (joueurPos->x == boitePos->x + 1 && joueurPos->y == boitePos->y && joueurPos->mouvement == 'z') {
    deplacement_x--;
    if (plateau[deplacement_x][deplacement_y] == ' ' || '.') {
      plateau[boitePos->x][boitePos->y] = ' ';
      plateau[deplacement_x][deplacement_y] = 'X';
      boitePos->x = deplacement_x;
      plateau[joueurPos->x][joueurPos->y] = ' ';
      joueurPos->x--;
      plateau[joueurPos->x][joueurPos->y] = 'o';
    } else {
      printf("Impossible de bouger la boîte vers le haut !\n");
    }
  }
  else if (joueurPos->x == boitePos->x && joueurPos->y == boitePos->y - 1 && joueurPos->mouvement == 'd') {
    deplacement_y++;
    if (plateau[deplacement_x][deplacement_y] == ' ' || '.') {
      plateau[boitePos->x][boitePos->y] = ' ';
      plateau[deplacement_x][deplacement_y] = 'X';
      boitePos->y = deplacement_y;
      plateau[joueurPos->x][joueurPos->y] = ' ';
      joueurPos->y++;
      plateau[joueurPos->x][joueurPos->y] = 'o';
    } else {
      printf("Impossible de bouger la boîte vers la droite !\n");
    }
  }
  else if (joueurPos->x == boitePos->x && joueurPos->y == boitePos->y + 1 && joueurPos->mouvement == 'q') {
    deplacement_y--;
    if (plateau[deplacement_x][deplacement_y] == ' ' || '.') {
      plateau[boitePos->x][boitePos->y] = ' ';
      plateau[deplacement_x][deplacement_y] = 'X';
      boitePos->y = deplacement_y;
      plateau[joueurPos->x][joueurPos->y] = ' ';
      joueurPos->y--;
      plateau[joueurPos->x][joueurPos->y] = 'o';
    } else {
      printf("Impossible de bouger la boîte vers la gauche !\n");
    }
  } 
  if(boitePos->x == entrePos->x && boitePos->y == entrePos->y ){
    printf("Bravo vous avez gagnez !\n");
    exit(0);
  }

  if ((boitePos->x == 1 && boitePos->y == 1) || 
      (boitePos->x == 1 && boitePos->y == 8) || 
      (boitePos->x == 8 && boitePos->y == 1) || 
      (boitePos->x == 8 && boitePos->y == 8)) {
    printf("Vous avez perdu ! La boîte est coincée dans un coin.\n");
    exit(0);
     }
}
int main() {
  PositionJoueur joueurPos;
  PositionBoite boitePos;
  PositionEntre entrePos;
  srand(time(NULL));
  char plateau[10][10];
  startPlateau(plateau);
  spawn(plateau, &joueurPos, &boitePos, &entrePos);
  afficherPlateau(plateau);

  while (1) {
    system("clear");
    printf("Joueur : %d %d \nBoite : %d %d \nEmplacement : %d %d \n", joueurPos.x, joueurPos.y, boitePos.x, boitePos.y, entrePos.x, entrePos.y);
    afficherPlateau(plateau);
    joueurMouvement(plateau, &joueurPos, &entrePos); 
    boitemouvement(plateau, &boitePos, &joueurPos, &entrePos);  
    
    }

  return 0;
}