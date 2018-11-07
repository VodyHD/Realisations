/* BAAZIZ Majdi
   QUERNEC Thomas  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include "menu.h"
#include "image.h"
#include "autre.h"
#include "jeu.h"
#include <math.h>



int main(int argc, char** argv)
{
	srand(time(NULL));
	int i , x, y, j, ressai = 1;
	int deplacement = 0, verif = 1, compteur = 0;
	InitialiserGraphique();
	char* essai = (char*) malloc(sizeof(char));
	CreerFenetre(0, 0, 1300,900);
	int reallocation = 1;
	ChoisirTitreFenetre("Le Taquin by M&T");
	ChoisirCurseur(3);
	struct melang_img mel;
	struct info_img inf;
	while(ressai!=0)
	{
		verif = 1;
		compteur = 0;
		deplacement=0;
		inf.id_image=ecran_accueil();
		x=choix_colonnes_n();
		y=choix_lignes();
		mel.tab = (int**) malloc(y* sizeof(int*));
		for (j=0 ; j<y ; j++)
		{
			mel.tab[j] = malloc(x* sizeof(int));
		}
		tableau(mel.tab, x, y);
		remplir_struct_img(&inf);
		concordance(inf.id_image,&mel,inf.largeur,inf.hauteur,x,y);
		struc_imag(mel, x, y);
		melange_image(mel,x,y);
		while(verif!=0 && deplacement!=2)
		{
			
			deplacement=jeu(mel,x,y);
			if (deplacement!=0)
			{
				compteur++;
				if(compteur>=pow(10.0,(double)reallocation))
				{
					essai=realloc(essai,(reallocation+1)*sizeof(char));  /* Ici j'ai opté pour un système de reallocation*/
					reallocation++;                                      /*dynamique de telle sorte à optimiser l'espace mémoire */
				}                                                        
				petite_image(inf.id_image);
				tentatives_aff(essai,compteur);
			}
			verif=verification(mel,x,y);
		}
		ressai=fin_retour_menuu();
		for(j=0;j<y;j++)
		{
			free(mel.tab[j]);
		}
		free(mel.tab);
	}
	return EXIT_SUCCESS;	
}



	
