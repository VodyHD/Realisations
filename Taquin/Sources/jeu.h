/* BAAZIZ Majdi
   QUERNEC Thomas  */
#ifndef JEU_H
#define JEU_H

void deplacement(struct melang_img m, int j, int i, int i_max, int j_max);
int deplacement_img_souris(struct melang_img mel, int x, int y, int compteur);
int deplacement_img(struct melang_img mel, int x, int y, int compteur);
int jeu(struct melang_img mel, int x, int y);
int fin_retour_menuu();


#endif