/* BAAZIZ Majdi
   QUERNEC Thomas  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include "image.h"
#include "menu.h"
#include "autre.h"

void tableau(int** tab, int x, int y)
/* Cette fonction a pour but de remplir un tableau à deux dimensions de telle
sorte à ce que la tab[j][i] = tab[j][i-1]+1 */
{
	int r = 0,i ,j;
	for (j=0 ; j<y ; j++)
	{
		for (i=0 ; i<x ; i++)
		{
			tab[j][i]= r;
			r++;
		}
	}
}



void tentatives_aff(char affichage[], int tentatives)
/* Cette fonction permet l'affichage du nombre de tentatives à chaque déplacement */
{
	couleur c = CouleurParComposante(255,255,255);
	ChoisirCouleurDessin(c);
	sprintf(affichage,"%d",tentatives);
	RemplirRectangle(1000,150,200,100);
	c=CouleurParComposante(0,0,0);
	ChoisirCouleurDessin(c);
	EcrireTexte(1010,200,"Tentatives",1);
	EcrireTexte(1120,200,affichage,2);
	
}

int verification(struct melang_img mel, int x, int y)
/* Cette fonction permet la vérification du tableau à chaque déplacement
du tableau, si la vérification est bonne, la fonction va renvoyé 0
sinon une autre valeur comprise entre 1 et (((x*y)-1) correspondant aux colonnes
* lignes) */
{
	int i, j, k = 0;
	int verif = 0;
	for (j=0 ; j<y ; j++)
	{
		for (i=0 ; i<x ; i++)
		{
			if (mel.tab[j][i]!=k)
			{
				verif++;
			}
			k++;
		}
	}
	return verif;
}

void aleatoire_tableau(int** tab, int x, int y)
/* Je n'utilise pas cette fonction mais celle-ci m'a permis de mettre
au point mon mélange de tableau que j'ai ensuite combiné avec le côté
graphique grâce à la structure pour pouvoir gérer les tuiles de mon image
*/
{
	int i, j, r, p, z =0;
	i =0;
	j=0;
	srand(time(NULL));
	for (z=0 ; z<1 ; z++)
	{
		r=rand()%4;
		p=tab[j][i];
		if ((r==0) && ((i+1)<x) && tab[j][i]==0)
		{
			tab[j][i]=tab[j][i+1];
			tab[j][i+1]=p;
		}
		else if ((r==1) && ((j+1)<y) && tab[j][i]==0)
		{
			tab[j][i]=tab[j+1][i];
			tab[j+1][i]=p;
		}
		else if ((r==2) && ((i-1)>=0) && tab[j][i]==0)
		{
			tab[j][i]=tab[j][i-1];
			tab[j][i-1]=p;
		}
		else if ((r==3) && ((j-1)>=0) && tab[j][i]==0)
		{
			tab[j][i]=tab[j-1][i];
			tab[j-1][i]=p;
		}
		i++;
		if (i==x)
		{
			i=0;
			j++;
			if (j==y)
			{
				j=0;
				i=0;
			}
		}

	}
}
void rectangle_autour_cyan(int x, int y, int largeur, int longueur)
/* Cette fonction permet la surbrillance de l'image séléctionnée par le joueur que ce soit au passage de la
souris ou au clavier, en effet, le joueur va alors voir un rectangle de couleur cyan apparaître autour de
l'image, un rectangle d'épaisseur 10px. Elle prend en paramètre la largeur et la hauteur de l'image que l'on
souhaite entourer  */
{
	couleur c=CouleurParComposante(0,255,255);
	ChoisirCouleurDessin(c);
	RemplirRectangle(x-10,y-10,10,longueur+20);
	RemplirRectangle(x,y-10,largeur,10);
	RemplirRectangle(x+largeur,y-10,10,longueur+20);
	RemplirRectangle(x,y+longueur,largeur,10);
}
void rectangle_autour_noir(int x, int y, int largeur, int longueur)
/* Cette fonction permet la "dé"-surbrillance de l'image "sélectionnée" avec un rectangle de couleur noir
autour de l'image permettant d'effacer le rectangle cyan autour de l'image qui a été selectionné précédemment*/
{
	couleur c=CouleurParComposante(0,0,0);
	ChoisirCouleurDessin(c);
	RemplirRectangle(x-10,y-10,10,longueur+20);
	RemplirRectangle(x,y-10,largeur,10);
	RemplirRectangle(x+largeur,y-10,10,longueur+20);
	RemplirRectangle(x,y+longueur,largeur,10);
}