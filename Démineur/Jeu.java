import javax.swing.*;
/**
 * La classe Jeu est utilis&eacute;e pour g&eacute;n&eacute;rer les bombes.
 * Mettre les indicateurs selon le nombre de bombes qui entoure chaque case.
 *  
 * @version 0.1
 * @author Thomas Quernec
 */
public class Jeu extends JPanel {
	/**
     * Contenue de la case et de ses alentours.
     * 0 = vide.
	 * 1 = 1 bombe autour de celle-ci.
	 * ...
	 * 8 = 8 bombes autour de celle-ci.
	 * 10 = 1 bombe sur cette case.
	 * 
     * @see Jeu#getTab()
     */
	private static int tab [][] = new int[30][30];
	/**
     * D&eacute;couverte permet de savoir si la case en x et en y est d&eacute;couverte ou non par l'utilisateur.
     * True si la case est d&eacute;couverte.
	 * False si elle est cach&eacute;e.
	 * 
     * @see Jeu#getDec()
     */
	private static boolean [][] decouverte = new boolean [30][30];
	/**
     * Victoire permet de savoir l'avancement de la partie.
     * 0 = partie en cours.
     * 1 = victoire.
     * 2 = d&eacute;faite.
     * 
     * @see Jeu#getVict()
     * @see Jeu#setVict()
     */
	private static int victoire = 0;
	/**
     * x correspond &agrave; la coordonn&eacute;e.
     * 
     * @see Jeu#getx()
     * @see Jeu#setx()
     */
	private static int x;
	/**
     * y correspond &agrave; la coordonn&eacute;e.
     * 
     * @see Jeu#gety()
     * @see Jeu#sety()
     */
	private static int y;
	/**
     * Bombs correspond au nombre de bombes qu'a demand&eacute;es l'utilisateur.
     * 
     * @see Jeu#getBombs()
     * @see Jeu#setBombs()
     */
	private static int bombs;
	/**
     * Compte correspond au chiffre de l'indicateur.
     * 0 = aucune bombe autour de cette case.
     * 
     * @see Jeu#getCompte()
     * @see Jeu#setCompte()
     */
	private static int compte = 0;
	/**
	 * Permets d'acc&eacute;der &agrave; ce tableau dans toutes les classes.
	 * 
	 * @return int[][] le tableau multidimensionnel de int
	 */
	public static int[][] getTab() {
	    return tab;
	}
	/**
	 * Permets d'acc&eacute;der &agrave; ce tableau dans toutes les classes.
	 * 
	 * @return boolean[][] le tableau multidimensionnel de boolean
	 */
	public static boolean[][] getDec() {
	    return decouverte;
	}
	/**
	 * Permets d'acc&eacute;der &agrave; cette varaible dans toutes les classes.
	 * 
	 * @return int l'etat de la partie
	 */
	public static int getVict() {
	    return victoire;
	}
	/**
	 * Permets de modifier cette varaible dans toutes les classes.
	 */
	public static void setVict(int victoire) {
		Jeu.victoire = victoire;		
	}
	/**
	 * Permets d'acc&eacute;der &agrave; cette varaible dans toutes les classes.
	 * 
	 * @return int la coordonnee en x
	 */
	public static int getx() {
	    return x;
	}
	/**
	 * Permet de modifier cette varaible dans toutes les classes.
	 * 
	 * @param x
	 */
	public static void setx(int x) {
		Jeu.x = x;
	}
	/**
	 * Permets d'acc&eacute;der &agrave; cette varaible dans toutes les classes.
	 * 
	 * @return int la coordonnee en y
	 */
	public static int gety() {
	    return y;
	}
	/**
	 * Permet de modifier cette varaible dans toutes les classes.
	 * 
	 * @param y
	 */
	public static void sety(int y) {
		Jeu.y = y;
	}
	/**
	 * Permets d'acc&eacute;der &agrave; cette varaible dans toutes les classes.
	 * 
	 * @return int le nombre de bombes demande
	 */
	public static int getBombs() {
		return bombs;
	}
	/**
	 * Permet de modifier cette varaible dans toutes les classes.
	 * 
	 * @param bombs
	 */
	public static void setBombs(int bombs) {
		Jeu.bombs = bombs;
	}
	/**
	 * Permets d'acc&eacute;der &agrave; cette varaible dans toutes les classes.
	 * 
	 * @return int l'indicateur de bombes alentour
	 */
	public static int getCompte() {
	    return compte;
	}
	/**
	 * Permet de modifier cette varaible dans toutes les classes.
	 * 
	 * @param compte
	 */
	static void setCompte(int compte) {
		Jeu.compte = compte;
	}
	/**
	 * Feneration des bombes al&eacute;atoirement dans la grille.
	 * Une bombe ne pourra pas se superposer &agrave; une autre.
	 * Calcul de tous les indicateurs de bombes alentour.
	 * Initialisation du tableau Action
	 * Initialisation du tableau DrapT
	 * Initialisation du tableau DrapP
	 * Initialisation du tableau Dec  
	 */
	static void generationBombes() {
	int i, h, x1, x2;
	while (getCompte() != getBombs()) {
		x1=(int) (0 + (Math.random() * (getx() - 0)));
		x2=(int) (0 + (Math.random() * (gety() - 0)));
		//Afin d avoir le nombre exact de bombes
		if (getTab()[x1][x2] != 10) {
			getTab()[x1][x2] = 10;
			setCompte(getCompte() + 1);
		}
	}
	for(i = 0; i < getx(); i++) {
		for (h = 0; h < gety(); h++) {
			//initialisation du getTab() qui permet de prendre en compte le clic
			JeuRun.getAction()[i][h] = true;
			//D&eacute;fini tous les drapeaux &agrave; false -> aucun
			JeuRun.getDrapT()[i][h] = false;
			JeuRun.getDrapP()[i][h] = false;
			//D&eacute;fini que toutes les cases sont cachees
			getDec()[i][h] = false;
			if(getTab()[i][h] != 10) {
				int compteur = 0;
				//colonne gauche
				if(i == 0) {
					compteur=verif("Est", i, h, compteur);
					if(h == 0) {
						//coin haut gauche
						compteur=verif("Sud Est", i, h, compteur);
						compteur=verif("Sud", i, h, compteur);
					} else if(h == gety()-1) {
						//coin bas gauche
						compteur=verif("Nord", i, h, compteur);
						compteur=verif("Nord Est", i, h, compteur);
					} else {
						//reste de la colonne extrem gauche
						compteur=verif("Nord", i, h, compteur);
						compteur=verif("Nord Est", i, h, compteur);
						compteur=verif("Sud Est", i, h, compteur);
						compteur=verif("Sud", i, h, compteur);
					}
				//colonne droite
				} else if(i == getx()-1) {
					compteur=verif("Ouest", i, h, compteur);
					if(h == 0) {
						//coin haut droit
						compteur=verif("Sud", i, h, compteur);
						compteur=verif("Sud Ouest", i, h, compteur);
					} else if(h == gety()-1) {
						//coin bas droit
						compteur=verif("Nord", i, h, compteur);
						compteur=verif("Nord Ouest", i, h, compteur);
					} else {
						//reste de la colonne extrem droite
						compteur=verif("Nord", i, h, compteur);
						compteur=verif("Sud", i, h, compteur);
						compteur=verif("Sud Ouest", i, h, compteur);
						compteur=verif("Nord Ouest", i, h, compteur);
					}
				} else {
					compteur=verif("Ouest", i, h, compteur);
					if(h == 0) {
						//ligne du haut
						compteur=verif("Est", i, h, compteur);
						compteur=verif("Sud Est", i, h, compteur);
						compteur=verif("Sud", i, h, compteur);
						compteur=verif("Sud Ouest", i, h, compteur);
					} else if(h == gety()-1) {
						//ligne du bas
						compteur=verif("Nord", i, h, compteur);
						compteur=verif("Nord Est", i, h, compteur);
						compteur=verif("Est", i, h, compteur);
						compteur=verif("Nord Ouest", i, h, compteur);
					} else {
						//sans contraintes
						compteur=verif("Nord", i, h, compteur);
						compteur=verif("Nord Est", i, h, compteur);
						compteur=verif("Est", i, h, compteur);
						compteur=verif("Sud Est", i, h, compteur);
						compteur=verif("Sud", i, h, compteur);
						compteur=verif("Sud Ouest", i, h, compteur);
						compteur=verif("Nord Ouest", i, h, compteur);
					}
				}
				getTab()[i][h] = compteur;
				}
			}
		}
	}
	/**
	 * Incr&eacute;mente la variable compte en fonction du nombre de bombes autour de la case.
	 * 
	 *  @param orientation
	 *  @param X
	 *  @param Y
	 *  @param compteur
	 */
	public static int verif(String orientation,int X,int Y, int compteur){
		switch (orientation) {
			case "Est":
				if(getTab()[X+1][Y] == 10) compteur++;
				return compteur;	
			case "Ouest":
				if(getTab()[X-1][Y] == 10) compteur++;
				return compteur;
			case "Sud":
				if(getTab()[X][Y+1] == 10) compteur++;
				return compteur;
			case "Nord":
				if(getTab()[X][Y-1] == 10) compteur++;
				return compteur;
			case "Nord Est":
				if(getTab()[X+1][Y-1] == 10) compteur++;
				return compteur;
			case "Sud Est":
				if(getTab()[X+1][Y+1] == 10) compteur++;
				return compteur;
			case "Nord Ouest":
				if(getTab()[X-1][Y-1] == 10) compteur++;
				return compteur;
			case "Sud Ouest":
				if(getTab()[X-1][Y+1] == 10) compteur++;
				return compteur;
			default:
				return compteur;
		}
	}
}

