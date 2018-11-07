/* BAAZIZ Majdi
   QUERNEC Thomas  */
#ifndef IMAGE_H
#define IMAGE_H

struct melang_img {
	char* img;
	int x; /* Ecart en x entre chaques tuiles*/
	int y; /* Ecart en y entre chaques tuiles*/
	int xx;
	int yy;
	int l; /* Largeur de l'image*/
	int h; /* Hauteur de l'image*/
	int** tab;
};
struct info_img{
	int id_image;
	int hauteur;
	int largeur;
};
void remplir_struct(struct melang_img* m, int l, int h, int x, int y, char* file);
void struc_imag(struct melang_img mel, int x, int y);
void melange_image(struct melang_img mel, int x, int y);
void remplir_struct_img(struct info_img* mel);
void concordance(int a, struct melang_img* mel, int largeur, int hauteur, int x, int y);
void petite_image(int a);

#endif