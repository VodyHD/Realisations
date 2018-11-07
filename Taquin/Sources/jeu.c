/* BAAZIZ Majdi
   QUERNEC Thomas  */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include "image.h"
#include "menu.h"
#include "jeu.h"


void deplacement(struct melang_img m, int j, int i, int i_max, int j_max)
/* Cette fonction a pour but de réaliser un déplacement dans un tableau
et dans les images entre la case situé soit à droite (i_max = i+1)
ou a gauche(i_max = i-1) et j_max vaudra tout le temps j ou si la personne souhaitera
se déplacer au dessus ou en dessous (j_max = j+1 ou j-1) et i_max vaudra i 

Plus de précision dans le rapport
Paramètres : j = ordonnée dans le tableau de la valeur du 0
			 i = abcisse dans le tableau de la valeur du 0
			 i_max = abcisse dans le tableau où l'on souhaite déplacer le 0
			 j_max = ordonnée " "  " "  " "   " "  " "  "  ""   "   "   
POSTCONDITION : Si i_max change de i alors j_max ne changera pas de j
				et si j_max change de j alors i_max ne changera pas de i */
{
	int p;
	p=m.tab[j_max][i_max];
	m.tab[j_max][i_max]=0;
	m.tab[j][i]=p;					
	CopierZone(0,1,(i)*(m.x+m.l),j*(m.y+m.h),m.l,m.h,0,0);                           /*J'envoie vers un autre ecran*/
	CopierZone(0,0,i_max*(m.x+m.l),j_max*(m.y+m.h),m.l,m.h,i*(m.x+m.l),j*(m.y+m.h)); /* Je duplique l'image vers la nouvelle position */
	CopierZone(1,0,0,0,m.l,m.h,i_max*(m.x+m.l),j_max*(m.y+m.h));					 /* Je récupère l'image pour la mettre
																					 vers l'ancienne position*/
}


int deplacement_img_souris(struct melang_img mel, int x, int y, int compteur)
/* Cette fonction gère le déplacement par la souris, elle renvoie 1 si une case a été déplacée
et 0 sinon */
{
	int i, j;
	compteur = 0;
	for (j=0;j<y;j++)
	{
		for (i=0;i<x;i++)
		{
			if (mel.tab[j][i]==0) /*Ici, cette condition me permet de récuper les coordonées de la valeur 0 dans le tableau */
			{		
				if (_X>=(i+1)*((mel.x+mel.l)) && _X<=(i+1)*((mel.x+mel.l))+mel.l)
				{
					if (_Y>=j*(mel.y+mel.h) && _Y<=(j)*(mel.y+mel.h)+mel.h && (i+1)<x)
					{
						deplacement(mel,j,i,i+1,j);
						compteur++;
					}
				}
				if(_X>=(i-1)*((mel.x+mel.l)) && _X<=(i-1)*((mel.x+mel.l))+mel.l)
				{
					if (_Y>=j*(mel.y+mel.h) && _Y<=(j)*(mel.y+mel.h)+mel.h && (i-1)>=0)
					{
						deplacement(mel,j,i,i-1,j);
						compteur++;
					}	
				}
				if(_X>=(i)*((mel.x+mel.l)) && _X<=(i)*((mel.x+mel.l))+mel.l)
				{
					if(_Y>=(j+1)*(mel.y+mel.h) && _Y<=(j+1)*(mel.y+mel.h)+mel.h && (j+1)<y)
					{
						deplacement(mel,j,i,i,j+1);
						compteur++;
					}
				}
				if (_X>=(i)*((mel.x+mel.l)) && _X<=(i)*((mel.x+mel.l))+mel.l)
				{
					if(_Y>=(j-1)*(mel.y+mel.h) && _Y<=(j-1)*(mel.y+mel.h)+mel.h && (j-1)>=0)
					{
						deplacement(mel,j,i,i,j-1);
						compteur++;
					}
				}
				return compteur;
			}
				
		}
	}
}
	

int deplacement_img(struct melang_img mel, int x, int y, int compteur)
/* Cette fonction gère le déplacement des cases par le clavier, elle renvoie 1 si une case
s'est déplacée ou 0 sinon */
{
	int key;
	int i, j;
	key = Touche();
	compteur=0;
	for (j=0 ; j<y ; j++)
	{
		for (i=0 ; i<x ; i++)
		{
			if(mel.tab[j][i]==0)
			{
				if (key==XK_Left && (i+1)<x)
				{
					deplacement(mel,j,i,i+1,j);
					i=x;
					j=y;
					compteur++;
				}
				else if(key==XK_Right && (i-1)>=0)
				{
					deplacement(mel,j,i,i-1,j);
					i=x;
					j=y;
					compteur++;
				}
				else if (key==XK_Up && (j+1)<y)
				{
					deplacement(mel,j,i,i,j+1);
					i=x;
					j=y;
					compteur++;
				}
				else if (key==XK_Down && (j-1)>=0)
				{
					deplacement(mel,j,i,i,j-1);
					i=x;
					j=y;
					compteur++;
				}
				return compteur;
			}
			
		}
	}
}
int jeu(struct melang_img mel, int x, int y)
/* Cette fonction a pour but de mettre en commun le déplacement par la souris
et par le clavier, celle ci revoie 2 si la personne clique sur le bouton menu
qui le fait quitter le système de jeu et l'envoie à l'écran de fin (voir main)
sinon elle renvoie 1 qui permet de continuer (voir main). Sinon on voit encore
le système de surbrillance pour le bouton menu */
{
	int compteur;
	SourisPosition();
	if(ToucheEnAttente())
	{
		compteur=deplacement_img(mel,x,y,compteur);
		return compteur;
	}
	else if (SourisCliquee())
	{
		if(_X>=1070 && _X<=1289 && _Y>=20 && _Y<=104)
		{
			return 2;
		}
		compteur=deplacement_img_souris(mel,x,y,compteur);
		return compteur;
	}
	else if(!SourisCliquee())
	{
		if(_X>=1000 && _X<=1219 && _Y>=20 && _Y<=104)
		{
			ChargerImage("Images/Ecriture/menu_r.png",1000,20,0,0,219,84);
		}
		else if(!(_X>=1000 && _X<=1219 && _Y>=20 && _Y<=104))
		{
			ChargerImage("Images/Ecriture/menu_b.png",1000,20,0,0,219,84);
		}
		return 0;
	}

}
int fin_retour_menuu()
/* Cette fonction a pour but de gérer l'écran de fin de jeu que ce soit en 
mode Clique/Souris ou au Clavier elle va renvoyer 0 si la personne souhaite quitter
ou elle va renvoyer 1 ce qui va relancer la boucle du menu*/
{
	int key = 0, touch;
	couleur c = CouleurParComposante(0,0,0);
	EffacerEcran(c);
	ChargerImage("Images/Ecriture/quitter.png", 458,100,0,0,384,110);
	ChargerImage("Images/Ecriture/rejouer_b.png",427,400,0,0,446,110);
	while(1)
	{
		while(!SourisCliquee())
		{
			SourisPosition();
			if (_X>=458 && _X<842 && _Y>=100 && _Y<=210 || key==0)
			{
				ChargerImage("Images/Ecriture/quitter_r.png", 458,100,0,0,384,110);
			}
			else if(!(_X>=458 && _X<=842 && _Y>=100 && _Y<=210 || key==0))
			{
				ChargerImage("Images/Ecriture/quitter.png", 458,100,0,0,384,110);
			}
			if (_X>=427 && _X<=873 && _Y>=400 && _Y<510 || key==1)
			{
				ChargerImage("Images/Ecriture/rejouer_r.png",427,400,0,0,446,110);
			}
			else if (!(_X>=427 && _X<=873 && _Y>=400 && _Y<510 || key==1))
			{
				ChargerImage("Images/Ecriture/rejouer_b.png",427,400,0,0,446,110);
			}
			if(ToucheEnAttente())
			{
				touch = Touche();
				if(touch == XK_Down && key+1<=1)
				{
					key+=1;
				}
				else if(touch == XK_Up && key-1>=0)
				{
					key-=1;
				}
				if(touch == XK_Return && key == 0)
				{
					return 0;
				}
				if(touch==XK_Return && key == 1)
				{
					return 1;
				}
			}
		}
		if (_X>=458 && _X<842 && _Y>=100 && _Y<=210)
		{
			return 0;
		}
		else if(_X>=427 && _X<=873 && _Y>=400 && _Y<510)
		{
			return 1;
		}	
	}
}
