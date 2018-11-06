/**
 * La classe JeuRun est utilis&eacute;e pour l'apparition des cases
 * l'algorithme de cascade
 * G&eacute;rer les cas de Victoire
 * G&eacute;rer les drapeaux
 * Peut reset les donn&eacute;es si l'utilisateur retourne dans le menu.
 *  
 * @version 0.1
 * @author Thomas Quernec
 */
public class JeuRun {
	/**
     * Action permet de g&eacute;rer l'interaction entre les joueurs et les cases
	 * False = le joueur ne pourra pas interagire avec cette case
	 * True = le joueur pourra interagire avec cette case
	 * 
     * @see Jeu#getAction()
     */
	private static boolean [][] action = new boolean [30][30];
	/**
     * MinePerdante permet de savoir quelle case &agrave; provou&eacute;e la d&eacute;faite afin de la metre en valeur.
     * 
     * @see Jeu#getMineP()
     */
	private static boolean [][] minePerdante = new boolean [30][30];
	/**
     * Lorsque la case en question est cach&eacute;e.
     * DrapT permet de savoir si la case est vide ou s'il elle contient le marqueur &eacute;toile.
     * False = la case est vide
     * True = la case contient le marqueur etoile
	 * 
     * @see Jeu#getDrapT()
     */
	private static boolean [][] drapT = new boolean[30][30];
	/**
	 * Lorsque la case en question est cachee
     * DrapP permet de savoir si la case contient le marqueurs ?
     * False = la case ne le contient pas
     * True = la case contient le marqueur ?
	 * 
     * @see Jeu#getDrapP()
     */
	private static boolean[][] drapP = new boolean[30][30];
	/**
     * Stock les coordonn&eacute;es de la case cliqu&eacute;e.
     * 
     * @see Jeu#getS()
     */
	private static int selection[] = new int [2];
	/**
	 * Permets d'acc&eacute;der &agrave; cette variable dans toutes les classes.
	 * 
	 * @return boolean[][] la coordonnee en x
	 */
	public static boolean[][] getAction() {
	    return action;
	}
	/**
	 * Permets d'acc&eacute;der &agrave; cette variable dans toutes les classes.
	 * 
	 * @return boolean[][] les coordonnees de la mine perdante
	 */
	public static boolean[][] getMineP() {
	    return minePerdante;
	}
	/**
	 * Permets d'acc&eacute;der &agrave; cette variable dans toutes les classes.
	 * 
	 * @return boolean[][] s'il y a un marqueur etoile
	 */
	public static boolean[][] getDrapT() {
		return drapT = drapT;
	}
	/**
	 * Permets d'acc&eacute;der &agrave; cette variable dans toutes les classes.
	 * 
	 * @return boolean[][] s'il y a une marqueur ?
	 */
	public static boolean[][] getDrapP() {
		return drapP = drapP;
	}
	/**
	 * Permets de stocker les coordonn&eacute;es de la case cliqu&eacute;e.
	 * 
	 * @return int [][] la coordonnee la case cliquee
	 */
	public static int[] getS() {
		return selection;
	}
	/**
	 * X et Y correspondent aux coordonn&eacute;s de la case cliqu&eacute;e.
	 * Si &agrave; cette case il y a une mine -> MineP = true afin de mettre en valeur la case perdante.
	 * Puis toutes les autres mines seront devoil&eacute;es et instaurent la d&eacute;faite -> victoire = 2.
	 * Si la case contient un indicateur la case sera revel&eacute;e.
	 * Si la case est vide l'algorithme de cascade sera lanc&eacute;.
	 */
	public static void apparition() {
		int X = getS()[0];
		int Y = getS()[1];
		//Si a cette case il y a une mine
		if (Jeu.getTab()[X][Y] == 10) {
			getMineP()[X][Y] = true;
			for(int i = 0; i < Jeu.getx(); i++){
				for (int h = 0; h < Jeu.gety(); h++){
					if (Jeu.getTab()[i][h] == 10) Jeu.getDec()[i][h] = true;
				}
			}
			Jeu.setVict(2);
		}
		//Si la case contient un indicateur la case sera revelee;
		if ((Jeu.getTab()[X][Y] >= 1) && (Jeu.getTab()[X][Y] < 9)) Jeu.getDec()[X][Y] = true;
		//Si la case est vide -> cascade avec les coordonees de la case de depart
		if (Jeu.getTab()[X][Y] == 0) cascade(X,Y);
	}
	/**
	 * R&eacute;currence de cascade afin de reveler toutes ses cases voisines
	 */
	public static void cascade(int x, int y){
		try {
			//Nord
			//Si ce n'est pas la ligne du haut et que la case juste au Nord de la case de depart et cachee
			if (y > 0 && !Jeu.getDec()[x][y-1]) {
				//La case au dessus sera revelee et les drapeaux enleve
				Jeu.getDec()[x][y-1] = true;
				getDrapT()[x][y-1] = false;
	            //S'il ni a pas d'indicateur la recurrence sera lancee avec la case au Nord de celle de depart
				if(Jeu.getTab()[x][y-1] == 0) cascade(x, y-1);
			}
			//Nord Ouest
			//Si ce n'est pas la colonne de droite et si ce n'est pas la ligne du haut et que la case juste au Nord Ouest de la case de depart et cachee
			if (x < Jeu.getx()-1 && y > 0 && !Jeu.getDec()[x+1][y-1]) {
				//La case au dessus sera revelee et les drapeaux enleve
				Jeu.getDec()[x+1][y-1] = true;
	            getDrapT()[x+1][y-1] = false;
	            //S'il ni a pas d'indicateur la recurrence sera lancee avec la case au Nord Ouest de celle de depart
	            if(Jeu.getTab()[x+1][y-1] == 0) cascade(x+1, y-1);
			}
			//Ouest
			//Si ce n'est pas la colonne de droite et que la case juste a l'Ouest de la case de depart et cachee
			if (x < Jeu.getx()-1 && !Jeu.getDec()[x+1][y]) {
				//La case au dessus sera revelee et les drapeaux enleve
				Jeu.getDec()[x+1][y] = true;
	            getDrapT()[x+1][y] = false;
	            //S'il ni a pas d'indicateur la recurrence sera lancee avec la case a l'Ouest de celle de depart
	            if(Jeu.getTab()[x+1][y] == 0) cascade(x+1, y);
			}
			//Sud Ouest
			//Si ce n'est pas la colonne de droite et si ce n'est pas la ligne du bas et que la case juste au Sud Ouest de la case de depart et cachee
			if (x < Jeu.getx()-1 && y < Jeu.gety()-1 && !Jeu.getDec()[x+1][y+1]) {
				//La case au dessus sera revelee et les drapeaux enleve
				Jeu.getDec()[x+1][y+1] = true;
	            getDrapT()[x+1][y+1] = false;
	            //S'il ni a pas d'indicateur la recurrence sera lancee avec la case au Sud Ouest de celle de depart
	            if(Jeu.getTab()[x+1][y+1] == 0) cascade(x+1, y+1);
			}
			//Sud
			//Si ce n'est pas la ligne du bas et que la case juste au Sud de la case de depart et cachee
			if (y < Jeu.gety()-1 && !Jeu.getDec()[x][y+1]) {
				//La case au dessus sera revelee et les drapeaux enleve
				Jeu.getDec()[x][y+1] = true;
	            getDrapT()[x][y+1] = false;
	            //S'il ni a pas d'indicateur la recurrence sera lancee avec la case au Sud de celle de depart
	            if(Jeu.getTab()[x][y+1] == 0) cascade(x, y+1);
			}
			//Sud Est
			//Si ce n'est pas la colonne de gauche et si ce n'est pas la ligne du bas et que la case juste au Sud Est de la case de depart et cachee
			if (x > 0 && y < Jeu.gety()-1 && !Jeu.getDec()[x-1][y+1]) {
				//La case au dessus sera revelee et les drapeaux enleve
				Jeu.getDec()[x-1][y+1] = true;
	            getDrapT()[x-1][y+1] = false;
	            //S'il ni a pas d'indicateur la recurrence sera lancee avec la case au Sud Est de celle de depart
	            if(Jeu.getTab()[x-1][y+1] == 0) cascade(x-1, y+1);
			}
			//Est
			//Si ce n'est pas la pas la colonne de gauche et que la case juste a l'Est de la case de depart et cachee
	        if (x > 0 && !Jeu.getDec()[x-1][y]) {
				//La case au dessus sera revelee et les drapeaux enleve
	        	Jeu.getDec()[x-1][y] = true;
	        	getDrapT()[x-1][y] = false;
	            //S'il ni a pas d'indicateur la recurrence sera lancee avec la case a l'Est de celle de depart
	            if(Jeu.getTab()[x-1][y] == 0) cascade(x-1, y);
	        }
			//Nord Est
			//Si ce n'est pas la colonne de gauche et si ce n'est pas la ligne du haut et que la case juste au dessus de la case de depart et cachee
	        if (x > 0 && y > 0 && !Jeu.getDec()[x-1][y-1]) {
				//La case au dessus sera revelee et les drapeaux enleve
	        	Jeu.getDec()[x-1][y-1] = true;
	            getDrapT()[x-1][y-1] = false;
	            //S'il ni a pas d'indicateur la recurrence sera lancee avec la case au Nord Est de celle de depart
	            if(Jeu.getTab()[x-1][y-1] == 0) cascade(x-1, y-1);
			}
		} catch (ArrayIndexOutOfBoundsException e) {}
	}
	/**
	* Elle v&eacute;rifie le nombre de case restante qui sont cach&eacute;s et stock cette valeur dans compte.
	* Si compte = nombre de mines -> victoire = 1.
    */
	public static void victoire() {
		int compteur = 0;
		for(int i = 0; i < Jeu.getx(); i++) {
			for (int h = 0; h < Jeu.gety(); h++) {
				//Nombre de cases encore cachee 
				if (Jeu.getDec()[i][h] == false) compteur++;
			}
		}
		//Si compte = nombre de mines -> victoire = 1
		if (compteur == Jeu.getBombs()) Jeu.setVict(1);
	}
	/**
     * X et Y correspondent aux coordonn&eacute;es de la case cliqu&eacute;e.
     * Comme expliqu&eacute; plus haut, selon les deux variables DrapT et DrapP,
     * elles ditinguent l'ancien contenu de la case pour le remplacer par le nouveau.
     * Tout en mettant &agrave; jour le nombre total de bombe sur le compteur.
     * Elle v&agrave;rifie la victoire par les drapeaux.
     */
	public static void drap() {
		int X, Y, decompte = Jeu.getBombs();
		X = getS()[0];
		Y = getS()[1];
		//S'il n'y a aucun marqueur -> etoile -> action = false
		if (!getDrapT()[X][Y] && !getDrapP()[X][Y]) {
			getDrapT()[X][Y] = true;
			getAction()[X][Y] = false;
			//Decrementation du nombre total de mines
			if (Jeu.getCompte() > 0) Jeu.setCompte(Jeu.getCompte() - 1);
		//S'il y a deja; le marqueur etoile -> ? -> action = true
		} else if (getDrapT()[X][Y] && !getDrapP()[X][Y]) {
			getDrapT()[X][Y] = false;
			getDrapP()[X][Y] = true;
			//Incrementation du nombre total de mines
			if (Jeu.getCompte() <= Jeu.getBombs()) Jeu.setCompte(Jeu.getCompte() + 1);
		//S'il y a deja le marqueur ? -> vide -> action = true
		} else if (!getDrapT()[X][Y] && getDrapP()[X][Y]) {
			getDrapP()[X][Y] = false;
			getDrapT()[X][Y] = false;
			getAction()[X][Y] = true;
		}
		//Gere la victoire grace aux drapeaux, si tous les draps sont sur des mines
		for(int i = 0; i < Jeu.getx(); i++) {
			for (int h = 0; h < Jeu.gety(); h++) {
				//Decrementation du nombre total de mines lorsque un drap est sur une bombe
				if (getDrapT()[i][h] && Jeu.getTab()[i][h] == 10) decompte--;
			}
		}
		//Si apres la decrementation on obtient 0, c'est que tous les draps sont sur des mines -> victoire = 1
		if (decompte == 0) Jeu.setVict(1);
	}
	/**
     * Remise a 0 de toutes les variables utiles au bon fonctionnement du jeu.
     * Redimension de la Frame
     * Affichage du Menu
     */
	public static void reset() {
		for(int i = 0; i < Jeu.getx(); i++) {
			for (int h = 0; h < Jeu.gety(); h++) {
				getAction()[i][h] = true;
				Jeu.getDec()[i][h] = false;
				Jeu.getTab()[i][h] = 0;
				getDrapT()[i][h] = false;
				getDrapP()[i][h] = false;
			}
		}
		Jeu.setBombs(0);
		Jeu.setCompte(0);
		Jeu.setVict(0);
		Jeu.setx(15);
		Jeu.sety(15);
		Demineur.menu.setSize(500,500);
		Demineur.menu.setContentPane(Menu.Panel);		
	}
}
