/* BAAZIZ Majdi
   QUERNEC Thomas  */
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <graph.h>
#include "image.h"
#include "menu.h"
#include "autre.h"

void remplir_struct(struct melang_img* m, int l, int h, int x, int y, char* file)
/* Cette fonction a pour but de remplir la variable de type structure melang_img mise 
en paramètre afin de préparer au mélange, en effet elle va prendre en paramètres la largeur, la hauteur,
le nombre de colonnes et de lignes et le nom de l'image voulue. Cela va permettre d'avoir
les coordonnées de chaque morceaux de l'image(à l'aide de la boucle). Elle permet de plus
de mettre en commun le nom de l'image et sa taille*/ 
{
	int i, j;
	for (j=0 ; j<y ; j++)
	{
		for (i=0 ; i<x ; i++)
		{

			m->img=file;
			m->x=5;
			m->y=5;
			m->xx= i*(l/x);
			m->yy= j*(h/y);
			m->l= l/x;
			m->h= h/y;    
		}
	}
}

void struc_imag(struct melang_img mel, int x, int y)
/* Cette fonction a pour but d'afficher l'image choisie morceau par morceau
à partir des coordonnées qui ont été remplies par la fonction remplir_struct*/
{
	couleur c = CouleurParComposante(0,0,0); /* Pour afficher le rectangle, de couleur noir */
	EffacerEcran(c);
	ChoisirCouleurDessin(c);
	int i, j;
	for (j=0 ; j<y ; j++)
	{
		for (i=0 ; i<x ; i++)
		{
			if (i==0 && j==0)
			{

				RemplirRectangle(i*(mel.x+mel.l),j*(mel.y+mel.h),mel.l,mel.h);
			}
			else
			{
				ChargerImage(mel.img,i*(mel.x+mel.l),j*(mel.y+mel.h),i*mel.l,j*mel.h,mel.l,mel.h);
			}
		}
	}
}
void melange_image(struct melang_img mel, int x, int y)
/* Cette fonction correspond à la fonction de mélange du tableau qui va induire le mélange des tuiles
ici : -  i et j reprénsentent les coordonnées dans le tableau de la valeur 0
	  -  p va être utilisé pour stocké la valeur du 0 récupéré aux coordonnées j et i
	  -  z correspondra au nombre de fois que nous voulons mélanger le tableau
	  -  r va être la valeur aléatoire qui nous permettra de savoir ou déplacer la 
	  valeur 0 ::::: 0 pour déplacer à droite (i+1)
	  				 1 pour déplacer en dessous (j+1)
	  				 2 pour déplacer à gauche (i-1)	
	  				 3 pour déplacer au dussus (j-1)
	  	Explication en détail dans le rapport */	
{					 	
	int i, j, z = 0, r;
	i=0;
	j=0;
	for (z=0 ; z<100000 ; z++)
	{
		r=rand()%4;
		if ((r==0) && ((i+1)<x) && mel.tab[j][i]==0)
		{
			mel.tab[j][i]=mel.tab[j][i+1];
			mel.tab[j][i+1]=0;
			CopierZone(0,1,(i+1)*(mel.x+mel.l),j*(mel.y+mel.h),mel.l,mel.h,0,0);
			RemplirRectangle((i+1)*(mel.x+mel.l),j*(mel.y+mel.h),mel.l,mel.h);
			CopierZone(1,0,0,0,mel.l,mel.h,(i)*(mel.x+mel.l),j*(mel.y+mel.h));			

		}
		else if ((r==1) && ((j+1)<y) && mel.tab[j][i]==0)
		{
			mel.tab[j][i]=mel.tab[j+1][i];
			mel.tab[j+1][i]=0;
			CopierZone(0,1,i*(mel.x+mel.l),(j+1)*(mel.y+mel.h),mel.l,mel.h,0,0);
			RemplirRectangle((i)*(mel.x+mel.l),(j+1)*(mel.y+mel.h),mel.l,mel.h);
			CopierZone(1,0,0,0,mel.l,mel.h,i*(mel.x+mel.l),(j)*(mel.y+mel.h));

		}
		else if ((r==2) && ((i-1)>=0) && mel.tab[j][i]==0)
		{
			mel.tab[j][i]=mel.tab[j][i-1];
			mel.tab[j][i-1]=0;
			CopierZone(0,1,(i-1)*(mel.x+mel.l),j*(mel.y+mel.h),mel.l,mel.h,0,0);
			RemplirRectangle((i-1)*(mel.x+mel.l),j*(mel.y+mel.h),mel.l,mel.h);
			CopierZone(1,0,0,0,mel.l,mel.h,(i)*(mel.x+mel.l),j*(mel.y+mel.h));

		}
		else if ((r==3) && ((j-1)>=0) && mel.tab[j][i]==0)
		{
			mel.tab[j][i]=mel.tab[j-1][i];
			mel.tab[j-1][i]=0;
			CopierZone(0,1,i*(mel.x+mel.l),(j-1)*(mel.y+mel.h),mel.l,mel.h,0,0);
			RemplirRectangle((i)*(mel.x+mel.l),(j-1)*(mel.y+mel.h),mel.l,mel.h);
			CopierZone(1,0,0,0,mel.l,mel.h,i*(mel.x+mel.l),(j)*(mel.y+mel.h));
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
void remplir_struct_img(struct info_img* mel)
/* Cette fonction a pour but de récupérer la hauteur et la largeur de l'image
selon la valeur renvoyé par le choix de l'image dans le menu */
{
	if ((mel->id_image)==1)
	{
		mel->hauteur=500;
		mel->largeur=800;
	}
	else if((mel->id_image)==2)
	{
		mel->hauteur=466;
		mel->largeur=700;
	}
	else if((mel->id_image)==3)
	{
		mel->hauteur=563;
		mel->largeur=900;
	}
	else if((mel->id_image)==4)
	{
		mel->hauteur=640;
		mel->largeur=960;
	}
	else if((mel->id_image)==5)
	{
		mel->hauteur=680;
		mel->largeur=850;
	}
	else if((mel->id_image)==6)
	{
		mel->hauteur=473;
		mel->largeur=750;
	}
	else if ((mel->id_image)==7)
	{
		mel->hauteur=500;
		mel->largeur=800;
	}
}
void concordance(int a, struct melang_img* mel, int largeur, int hauteur, int x, int y)
/* Cette fonction a pour but de lier la valeur renvoyé par le choix de l'image aux 
images (fichiers), avec en plus en paramètre la stucture qui sera remplie des coordonnés de chacunes
des tuiles, la largeur de l'image, sa hauteur puis le nombre de colonnes et de lignes 
Elle va alors permettre de remplir mel avec les bonnes images */
{
	if(a==1)
	{
		remplir_struct(mel,largeur, hauteur,x,y,"Images/canyon.png");
		
	}
	else if (a==2)
	{
		remplir_struct(mel,largeur, hauteur,x,y,"Images/rialto.png");

	}
	else if (a==3)
	{
		remplir_struct(mel,largeur, hauteur,x,y,"Images/singapore.png");

	}
	else if (a==4)
	{
		remplir_struct(mel,largeur, hauteur,x,y,"Images/iut.png");
	}
	else if (a==5)
	{
		remplir_struct(mel,largeur, hauteur,x,y,"Images/marsupilami-com-08.png");
	}
	else if(a==6)
	{
		remplir_struct(mel,largeur, hauteur,x,y,"Images/joconde.png");
	}
	else if(a==7)
	{
		remplir_struct(mel,largeur, hauteur,x,y,"Images/simpson.png");
	}
}
void petite_image(int id_image)
/* Cette fonction a pour but d'afficher la petite image sur le côté
du jeu, elle va prendre en paramètre la valeur rendue par le choix de l'image
(que j'appelle "identifiant de l'image)  (renvoyé par la fonction ecran_accueil()
à travers la fonction choix_image()). */
{
	if (id_image==1)
	{
		ChargerImage("Images/canyon_petit.png",900,400,0,0,350,230);
	}
	else if (id_image==2)
	{
		ChargerImage("Images/rialto_petit.png",900,400,0,0,350,230);
	}
	else if (id_image==3)
	{
		ChargerImage("Images/singapore_petit.png",940,400,0,0,350,230);
	}
	else if(id_image==4)
	{
		ChargerImage("Images/iut_petit.png",940,670,0,0,350,230);
	}
	else if(id_image==5)
	{
		ChargerImage("Images/marsupilami_petit.png",900,400,0,0,350,280); //Agrandir sur la 2eme vue du jeu <3
	}
	else if(id_image==6)
	{
		ChargerImage("Images/joconde_petit.png",900,400,0,0,350,230);
	}
	else if(id_image==7)
	{
		ChargerImage("Images/simpson_petit.png",900,400,0,0,350,230);
	}
}