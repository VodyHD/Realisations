/* BAAZIZ Majdi
   QUERNEC Thomas  */
#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "image.h"
#include "menu.h"
#include "autre.h"


int choix_lignes_souris()
{
	int a = 0;		/* cette variable représente la valeur de la ligne qui sera retourner dés que la personne va cliquer sur un chiffre*/
	if(_X>=10 && _X<161 && _Y>=10 && _Y<139) /*Toutes ces conditions représentent les coordonnées de chacunes des images des chiffres */
	{
		exit(0);
	}
	else if(_X>=900 && _X<985 && _Y>=150 && _Y<277)
	{
		a=3;
	}
	else if (_X>=990 && _X<1075 && _Y>=150 && _Y<277)
	{
		a=4;
	}
	else if(_X>=900 && _X<985 && _Y>=290 && _Y<412)
	{
		a=5;
	}
	else if(_X>=990 && _X<1075 && _Y>=290 && _Y<412)
	{
		a=6;
	}
	else if (_X>=900 && _X<985 && _Y>=430 && _Y<553)
	{
		a=7;
	}
	else if (_X>=990 && _X<1075 && _Y>=430 && _Y<553)
	{
		a=8;
	}
	return a;		
}
int choix_lignes() 
/* Cette fonction a pour but de mettre en commun le "mode clavier et souris" pour le choix des lignes"
Le début de la fonction va gérer le système de surbrillance. La variable "key" correspond au mouvement
des touches (il faut savoir que je l'ai initialisé à -1 de telle sorte à ce que le bouton quitter soit
pré-séléctionné dès le départ), la variable "touch" va contenir le code de la touche qui va modifié ou non "key" et a sera 
alors la valeur retournée dés que la touche "Entrée" sera appuyée ou dés qu'il y aura un clic". 
Le système de surbrillance sera expliqué en détail dans le rapport*/



{
	int key = -1, touch, a=0;
	ChargerImage("Images/Ecriture/3_b.png",900,150,0,0,85,122);
	ChargerImage("Images/Ecriture/4_b.png",990,150,0,0,85,122);
	ChargerImage("Images/Ecriture/5_b.png",900,290,0,0,85,122);
	ChargerImage("Images/Ecriture/6_b.png",990,290,0,0,85,122);
	ChargerImage("Images/Ecriture/7_b.png",900,430,0,0,85,122);
	ChargerImage("Images/Ecriture/8_b.png",990,430,0,0,85,122);
	ChargerImage("Images/Ecriture/Lignes.png",750,600,0,0,304,110);
	ChargerImage("Images/Ecriture/bouton_quitter_b.png",10,10,0,0,100,100);
	while(1)
	{
		while(!SourisCliquee())
			{
				SourisPosition();
				if(_X>=10 && _X<161 && _Y>=10 && _Y<139 ||key<0)
				{
					ChargerImage("Images/Ecriture/bouton_quitter_n.png",10,10,0,0,100,100);

				}
				else if(!(_X>=10 && _X<161 && _Y>=10 && _Y<139 || key<0))
				{
					ChargerImage("Images/Ecriture/bouton_quitter_b.png",10,10,0,0,100,100);
				}
				if(_X>=900 && _X<985 && _Y>=150 && _Y<278 || key==0)
				{
					ChargerImage("Images/Ecriture/3_r.png",900,150,0,0,85,122);
				}
				else if (!(_X>=900 && _X<985 && _Y>=150 && _Y<278 || key==0))
				{
					ChargerImage("Images/Ecriture/3_b.png",900,150,0,0,85,122);
				}
				if (_X>=990 && _X<1075 && _Y>=150 && _Y<278 || key==1)
				{
					ChargerImage("Images/Ecriture/4_r.png",990,150,0,0,85,122);
				}
				else if(!(_X>=990 && _X<1075 && _Y>=150 && _Y<278 || key==1))
				{
					ChargerImage("Images/Ecriture/4_b.png",990,150,0,0,85,122);
				}
				if(_X>=900 && _X<985 && _Y>=290 && _Y<412 || key==2)
				{
					ChargerImage("Images/Ecriture/5_r.png",900,290,0,0,85,122);
				}
				else if(!(_X>=900 && _X<985 && _Y>=290 && _Y<412 || key==2))
				{
					ChargerImage("Images/Ecriture/5_b.png",900,290,0,0,85,122);
				}
				if(_X>=990 && _X<1075 && _Y>=290 && _Y<412 ||key==3)
				{
					ChargerImage("Images/Ecriture/6_r.png",990,290,0,0,85,122);
				}
				else if(!(_X>=990 && _X<1075 && _Y>=290 && _Y<412 || key==3))
				{
					ChargerImage("Images/Ecriture/6_b.png",990,290,0,0,85,122);
				}
				if (_X>=900 && _X<985 && _Y>=430 && _Y<553 || key==4)
				{
					ChargerImage("Images/Ecriture/7_r.png",900,430,0,0,85,122);
				}
				else if(!(_X>=900 && _X<985 && _Y>=430 && _Y<553 || key==4))
				{
					ChargerImage("Images/Ecriture/7_b.png",900,430,0,0,85,122);
				}
				if (_X>=990 && _X<1075 && _Y>=430 && _Y<553 || key==5)
				{
					ChargerImage("Images/Ecriture/8_r.png",990,430,0,0,85,122);
				}
				else if (!(_X>=990 && _X<1075 && _Y>=430 && _Y<553 || key==5))
				{
					ChargerImage("Images/Ecriture/8_b.png",990,430,0,0,85,122);
				}
				if (ToucheEnAttente())
				{
					touch=Touche();
					if(touch==XK_Right && (key+1)<=5)
					{
						key+=1;
					}
					if (touch==XK_Down && (key+2)<=5)
					{
							key+=2;
					}
					if (touch==XK_Up && (key-2)>=-1)
					{
						key-=2;
					}
					if (touch==XK_Left && (key-1)>=-1)
					{
						key-=1;
					}
					
					if (touch==XK_Return && key==-1)
					{
						exit(0);
					}
					else if (touch==XK_Return && key==0)
					{
						a=3;
						return a;
					}
					else if(touch==XK_Return && key==1)
					{
						a=4;
						return a;
					}
					else if(touch==XK_Return && key==2)
					{
						a=5;
						return a;
					}
					else if(touch==XK_Return && key==3)
					{
						a=6;
						return a;
					}
					else if(touch==XK_Return && key==4)
					{
						a=7;
						return a;
					}
					else if(touch==XK_Return && key==5)
					{
						a=8;
						return a;
					}
				}
			}
			a=choix_lignes_souris();
			if(a!=0)
			{
				return a;
			}
	}

}
int choix_colonnes_souris()
/* Même principe que pour le choix des lignes*/
{
	int a=0;
	if(_X>=10 && _X<161 && _Y>=10 && _Y<139)
	{
		exit(0);
	}
	else if(_X>=100 && _X<186 && _Y>=150 && _Y<277)
	{
		a=3;
	}
	else if (_X>=190 && _X<276 && _Y>=150 && _Y<277)
	{
		a=4;
	}
	else if(_X>=100 && _X<186 && _Y>=290 && _Y<412)
	{
		a=5;
	}
	else if(_X>=190 && _X<276 && _Y>=290 && _Y<412)
	{
		a=6;
	}
	else if (_X>=100 && _X<186 && _Y>=430 && _Y<553)
	{
		a=7;
	}
	else if (_X>=190 && _X<276 && _Y>=430 && _Y<553)
	{
		a=8;
	}
	return a;
}
int choix_colonnes_n()
/* Même principe que pour le choix des lignes */
{
	int a=0, key = -1, touch;
	ChargerImageFond("Images/Ecriture/colonnes_et_lignes_choix.png");
	ChargerImage("Images/Ecriture/3_b.png",100,150,0,0,85,122);
	ChargerImage("Images/Ecriture/4_b.png",190,150,0,0,85,122);
	ChargerImage("Images/Ecriture/5_b.png",100,290,0,0,85,122);
	ChargerImage("Images/Ecriture/6_b.png",190,290,0,0,85,122);
	ChargerImage("Images/Ecriture/7_b.png",100,430,0,0,85,122);
	ChargerImage("Images/Ecriture/8_b.png",190,430,0,0,85,122);
	ChargerImage("Images/Ecriture/colonnes.png",30,600,0,0,470,110);
	ChargerImage("Images/Ecriture/bouton_quitter_b.png",10,10,0,0,100,100);
	while(1)
	{
		while(!SourisCliquee())
		{
			SourisPosition();
			if(_X>=10 && _X<161 && _Y>=10 && _Y<139 ||key<0)
			{
				ChargerImage("Images/Ecriture/bouton_quitter_n.png",10,10,0,0,100,100);
			}
			else if(!(_X>=10 && _X<161 && _Y>=10 && _Y<139 || key<0))
			{
				ChargerImage("Images/Ecriture/bouton_quitter_b.png",10,10,0,0,100,100);
			}
			if(_X>=100 && _X<186 && _Y>=150 && _Y<277 || key==0)
			{
				ChargerImage("Images/Ecriture/3_r.png",100,150,0,0,85,122);
			}
			else if (!(_X>=100 && _X<186 && _Y>=150 && _Y<277 || key==0))
			{
				ChargerImage("Images/Ecriture/3_b.png",100,150,0,0,85,122);
			}
			if (_X>=190 && _X<276 && _Y>=150 && _Y<277 || key==1)
			{
				ChargerImage("Images/Ecriture/4_r.png",190,150,0,0,85,122);
			}
			else if(!(_X>=190 && _X<276 && _Y>=150 && _Y<277 || key==1))
			{
				ChargerImage("Images/Ecriture/4_b.png",190,150,0,0,85,122);
			}
			if(_X>=100 && _X<186 && _Y>=290 && _Y<412 || key==2)
			{
				ChargerImage("Images/Ecriture/5_r.png",100,290,0,0,85,122);
			}
			else if(!(_X>=100 && _X<186 && _Y>=290 && _Y<412 || key==2))
			{
				ChargerImage("Images/Ecriture/5_b.png",100,290,0,0,85,122);
			}
			if(_X>=190 && _X<276 && _Y>=290 && _Y<412 || key==3)
			{
				ChargerImage("Images/Ecriture/6_r.png",190,290,0,0,85,122);
			}
			else if(!(_X>=190 && _X<276 && _Y>=290 && _Y<412 || key==3))
			{
				ChargerImage("Images/Ecriture/6_b.png",190,290,0,0,85,122);
			}
			if (_X>=100 && _X<186 && _Y>=430 && _Y<553 || key==4)
			{
				ChargerImage("Images/Ecriture/7_r.png",100,430,0,0,85,122);
			}
			else if(!(_X>=100 && _X<186 && _Y>=430 && _Y<553 || key==4))
			{
				ChargerImage("Images/Ecriture/7_b.png",100,430,0,0,85,122);
			}
			if (_X>=190 && _X<276 && _Y>=430 && _Y<553 || key==5)
			{
				ChargerImage("Images/Ecriture/8_r.png",190,430,0,0,85,122);
			}
			else if (!(_X>=190 && _X<276 && _Y>=430 && _Y<553 || key==5))
			{
				ChargerImage("Images/Ecriture/8_b.png",190,430,0,0,85,122);
			}
			if(ToucheEnAttente())
			{
				touch=Touche();
				if(touch==XK_Right && (key+1)<=5)
				{
					key+=1;
				}
				if (touch==XK_Down && (key+2)<=5)
				{
						key+=2;
				}
				if (touch==XK_Up && (key-2)>=-1)
				{
					key-=2;
				}
				if (touch==XK_Left && (key-1)>=-1)
				{
					key-=1;
				}
					
				if (touch==XK_Return && key==-1)
				{
					exit(0);
				}
				else if (touch==XK_Return && key==0)
				{
					a=3;
					return a;
				}
				else if(touch==XK_Return && key==1)
				{
					a=4;
					return a;
				}
				else if(touch==XK_Return && key==2)
				{
					a=5;
					return a;
				}
				else if(touch==XK_Return && key==3)
				{
					a=6;
					return a;
				}
				else if(touch==XK_Return && key==4)
				{
					a=7;
					return a;
				}
				else if(touch==XK_Return && key==5)
				{
					a=8;
					return a;
				}
			}
		}
		a=choix_colonnes_souris();
		if(a!=0)
		{
			return a;
		}
	}
		

}


int choix_image_clic()
/* Même principe que le choix des colonnes, lignes*/
{
	int a = 0, r;
	if (_X>=10 && _X<161 && _Y>=10 && _Y<139)
	{
		exit(0);
	}
	else if(_X>=50 && _X<451 && _Y>=300 && _Y<551)
	{
		a=1;
	}
	else if(_X>=650 && _X<1051 && _Y>=300 && _Y<568)
	{
		a=2;
	}
	else if (_X>=50 && _X<451 && _Y>=650 && _Y<902)
	{
		a=3;
	}
	else if(_X>=650 && _X<1051 && _Y>=650 && _Y<902)
	{
		r=rand()%4;
		if (r==0)
		{
			a=4;
		}
		else if (r==1)
		{
			a=5;
		}
		else if (r==2)
		{
			a=6;
		}
		else if (r==3)
		{
			a=7;
		}
	}
	return a;
}
int choix_image()
/* Même système de choix que les colonnes et lignes + un affichage de la résolution de chaque image 
au survol de celle-ci sauf pour l'image mystère. La valeur retournée correspond 
au numero d'identification de l'image qui sera alors traité par une autre fonction*/
{
	srand(time(NULL));
	int a = 0, r, key = -1, touch;
	ChargerImageFond("Images/Ecriture/choix.png");
	ChargerImage("Images/Ecriture/bouton_quitter_b.png",10,10,0,0,100,100);
	ChargerImage("Images/canyon_choix.png",50,300,0,0,400,250);
	ChargerImage("Images/rialto_choix.png",650,300,0,0,400,267);
	ChargerImage("Images/singapore_choix.png",50,650,0,0,400,251);
	ChargerImage("Images/Ecriture/mystere_img.png",650,650,0,0,400,260);
	while(1)
	{
		while(!SourisCliquee())
		{
			SourisPosition();
			if(_X>=10 && _X<161 && _Y>=10 && _Y<139 || key<0)
			{
				ChargerImage("Images/Ecriture/bouton_quitter_n.png",10,10,0,0,100,100);
			}
			else if(!(_X>=10 && _X<161 && _Y>=10 && _Y<139 || key<0))
			{
				ChargerImage("Images/Ecriture/bouton_quitter_b.png",10,10,0,0,100,100);
			}
			if(_X>=50 && _X<451 && _Y>=300 && _Y<551 || key==0)
			{
				rectangle_autour_cyan(50,300,400,250);
				ChargerImage("Images/Ecriture/800x500.png",100,230,0,0,200,58);
			}
			else if (!(_X>=50 && _X<451 && _Y>=300 && _Y<551 || key==0))
			{
				rectangle_autour_noir(50,300,400,250);
				RemplirRectangle(100,230,200,58);
			}
			if(_X>=650 && _X<1051 && _Y>=300 && _Y<568 || key == 1)
			{
				rectangle_autour_cyan(650,300,400,267);
				ChargerImage("Images/Ecriture/700x466.png",700,230,0,0,200,58);
			}
			else if (!(_X>=650 && _X<1051 && _Y>=300 && _Y<568 || key == 1))
			{
				rectangle_autour_noir(650,300,400,267);
				RemplirRectangle(700,230,230,58);
			}
			if (_X>=50 && _X<451 && _Y>=650 && _Y<902 || key == 2)
			{
				rectangle_autour_cyan(50,650,400,251);
				ChargerImage("Images/Ecriture/900x563.png",100,580,0,0,200,59);
			}
			else if(!(_X>=50 && _X<451 && _Y>=650 && _Y<902 || key == 2))
			{
				rectangle_autour_noir(50,650,400,251);
				RemplirRectangle(100,580,200,59);
			}
			if(_X>=650 && _X<1051 && _Y>=650 && _Y<902 || key==3)
			{
				rectangle_autour_cyan(650,650,400,260);
			}
			else if (!(_X>=650 && _X<1051 && _Y>=650 && _Y<902 || key==3 ))
			{
				rectangle_autour_noir(650,650,400,260);
			}
			if(ToucheEnAttente())
			{
				touch=Touche();
				if(touch==XK_Right && (key+1)<=3)
				{
					key+=1;
				}
				if (touch==XK_Down && (key+2)<=3)
				{
						key+=2;
				}
				if (touch==XK_Up && (key-2)>=-1)
				{
					key-=2;
				}
				if (touch==XK_Left && (key-1)>=-1)
				{
					key-=1;
				}
					
				if (touch==XK_Return && key==-1)
				{
					exit(0);
				}
				else if (touch==XK_Return && key==0)
				{
					a=1;
					return a;
				}
				else if(touch==XK_Return && key==1)
				{
					a=2;
					return a;
				}
				else if(touch==XK_Return && key==2)
				{
					a=3;
					return a;
				}
				else if(touch==XK_Return && key==3)
				{
					r=rand()%4;
					if (r==0)
					{
						a=4;
						return a;
					}
					else if (r==1)
					{
						a=5;
						return a;
					}
					else if (r==2)
					{
						a=6;
						return a;
					}
					else if (r==3)
					{
						a=7;
						return a;
					}
				}
			}

		}
		a=choix_image_clic();
		if(a!=0)
		{
			return a;
		}
	}
		
}
void regles()
/* Cette fonction permet l'affichage des règles du jeu dès que l'on clique sur "Règles du jeu"
dans l'écran de démarrage on va alors utiliser dedans une variable qui va prendre la valeur 
correspondant à la touche du haut ou du bas ce qui va alors surbriller la case et elle sera
en attente de la touche entrée. Mode Clique/Souris présent aussi */
{
	int key = 0, touch;
	ChargerImage("Images/Ecriture/bouton_retour.png",10,10,0,0,150,150);
	ChargerImage("Images/Ecriture/règles_texte.png",300,150,3,0,700,599); //fait une capture d'ecran du doc texte regle
	ChargerImage("Images/Ecriture/regles_b.png",314,10,0,0,672,122);
	while(1)
	{
		while(!SourisCliquee())
		{
			SourisPosition();
			if(_X>=10 && _X<=160 && _Y>=10 && _Y<160 || key==0)
			{
				ChargerImage("Images/Ecriture/bouton_retour_r.png",10,10,0,0,150,150);
			}
			else if(!(_X>=10 && _X<=160 && _Y>=10 && _Y<160 || key==0))
			{
				ChargerImage("Images/Ecriture/bouton_retour.png",10,10,0,0,150,150);
			}
			if(ToucheEnAttente())
			{
				touch=Touche();
				if(touch==XK_Up && key-1>=0)
				{
					key-=1;
				}
				else if(touch==XK_Down && key+1<=1)
				{
					key+=1;
				}
				if(touch==XK_Return && key==0)
				{
					return;
				}
			}
		}
		if(_X>=10 && _X<=348 && _Y>=10 && _Y<348)
		{
			return;
		}

	}
}
int ecran_accueil()
/* Cette fonction gère l'interface d'entrée dans le jeu, elle va alors afficher les images
correspondants aux boutons "Jouer" et "Regles du jeu" qui vont surbriller au passage du curseur ou au passage du clavier.
Dès que le joueur va cliquer ou va appuyer sur entrée sur le bouton jouer, il va alors être
emmené vers l'écran des images(ici on pourra penser que la fonction fait trop de choses à la fois
mais si elle avait une utilité que pour afficher des images, elle ne sera pas pertinente)
Elle va alors retourner dans le "main" la valeur déja retourné par la fonction choix image. */
 {
 	int a=0, key=-1, touch;
 	couleur c = CouleurParComposante(0,0,0);
	ChoisirCouleurDessin(c);
	ChargerImageFond("Images/Ecriture/menu.png");
	while(1)
	{
		ChargerImage("Images/Ecriture/jouer_b.png",480,250,0,0,340,110);
		ChargerImage("Images/Ecriture/regles_b.png",314,450,0,0,672,122);
		ChargerImage("Images/Ecriture/bouton_quitter_b.png",10,10,0,0,100,100);
		while(!SourisCliquee())
		{
			SourisPosition();
			if(_X>=480 && _X<821 && _Y>=250 && _Y<361 || key==0)
			{
				ChargerImage("Images/Ecriture/jouer_r.png",480,250,0,0,340,110);
			}
			else if (!(_X>=480 && _X<821 && _Y>=250 && _Y<361 || key==0))
			{
				ChargerImage("Images/Ecriture/jouer_b.png",480,250,0,0,340,110);
			}
			if (_X>=314 && _X<987 && _Y>=450 && _Y<573 || key==1)
			{
				ChargerImage("Images/Ecriture/regles_r.png",314,450,0,0,672,122);
			}
			else if(!(_X>=314 && _X<987 && _Y>=450 && _Y<573 || key==1))
			{
				ChargerImage("Images/Ecriture/regles_b.png",314,450,0,0,672,122);
			}
			if(_X>=10 && _X<161 && _Y>=10 && _Y<139 || key<0)
			{
				ChargerImage("Images/Ecriture/bouton_quitter_n.png",10,10,0,0,100,100);
			}
			else if(!(_X>=10 && _X<161 && _Y>=10 && _Y<139|| key<0))
			{
				ChargerImage("Images/Ecriture/bouton_quitter_b.png",10,10,0,0,100,100);
			}
			if(ToucheEnAttente())
			{
				touch=Touche();
				
				if (touch==XK_Down && (key+1)<=1)
				{
						key+=1;
				}
				if (touch==XK_Up && (key-1)>=-1)
				{
					key-=1;
				}	
				if (touch==XK_Return && key==-1)
				{
					exit(0);
				}
				else if (touch==XK_Return && key==0)
				{
					a=choix_image();
					return a;
				}
				else if(touch==XK_Return && key==1)
				{
					EffacerEcran(c);
					regles();
					ChargerImageFond("Images/Ecriture/menu.png");
				}
			}
		}
		if (_X>=480 && _X<821 && _Y>=250 && _Y<361)
		{
			a=choix_image();
			return a;
		}
		else if(_X>=314 && _X<986 && _Y>=450 && _Y<572)
		{
			EffacerEcran(c);
			regles();
			ChargerImageFond("Images/Ecriture/menu.png");
		}
		else if((_X>=10 && _X<161 && _Y>=10 && _Y<139))
		{
			exit(0);
		}
	}
 }
