/* BAAZIZ Majdi
   QUERNEC Thomas  */
#ifndef AUTRE_H
#define AUTRE_H

void tableau(int** tab, int x, int y);
void tentatives_aff(char affichage[], int tentatives);
int verification(struct melang_img mel, int x, int y);
void aleatoire_tableau(int** tab, int x, int y);
void rectangle_autour_noir(int x, int y, int largeur, int longueur);
void rectangle_autour_cyan(int x, int y, int largeur, int longueur);

#endif