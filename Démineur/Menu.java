import java.io.*;
import javax.swing.*;

/**
 * La classe Menu est utilis&eacute;e pour cr&eacute;er la JFrame.
 * G&eacute;rer le lancement de la partie avec les param&egrave;tres voulus.
 * Pouvoir lire et &eacute;crire les donn&eacute;es d'une partie en cours.
 *  
 * @version 0.1
 * @author Thomas Quernec
 */
public class Menu extends JFrame {
	/**
     * LancementOS d&eacute;termine si le menu de lancement est On Sreen ou non.
     * 
     * @see Menu#getLancementOS()
     * @see Menu#setLancementOS()
     */
	private static boolean lancementOS = false;
	/**
     * MenuOS d&eacute;termine si le menu est On Sreen ou non.
     * 
     * @see Menu#getMenuOS()
     * @see Menu#setMenuOS()
     */
	private static boolean menuOS = true;
	/**
	 * Cr&eacute;ation du Panel.
	 * 
	 * @see Menu#Menu()
	 * @see Menu#partieSave()
	 */
	static Fenetre Panel = new Fenetre();
	/**
	 * Retourne si le menu de lancement est On Sreen ou non.
	 * 
	 * @return boolean LancementOS
	 */
	public static boolean getLancementOS() {
		return lancementOS;
	}
	/**
	 * Permets de modifier la variable lancementOS dans toutes les classes.
	 * 
	 * @param lancementOS
	 */
	public static void setLancementOS(boolean lancementOS) {
		Menu.lancementOS = lancementOS;
	}
	/**
	 * Retourne si le menu est On Sreen ou non.
	 * 
	 * @return boolean MenuOS
	 */
	public static boolean getMenuOS() {
		return menuOS;
	}
	/**
	 * Permets de modifier la variable menuOS dans toutes les classes.
	 * 
	 * @param menuOS
	 */
	public static void setMenuOS(boolean menuOS) {
		Menu.menuOS = menuOS;
	}
	/**
	 * Constructeur destine &agrave; la cr&eacute;ation de la Frame,
	 * a l'attribution de Listener et &agrave; la d&eacute;finition par d&eacute;faut de x et y.
	 */
	public Menu() {
		//Param&egrave;tres de la Frame
		super("Demineur");
		this.setSize(500,500);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setLocation(10,10);
		this.setResizable(false);
		//distribution de Listener
		this.addMouseMotionListener(new ControlerSouris(Panel));
		this.addMouseListener(new ControlerClique(Panel));
		this.addWindowListener(new ControlerFenetre());
		this.setContentPane(Panel);
		//d&eacute;finition de x et y
		Jeu.setx(15);
		Jeu.sety(15);
	}
	/**
	 *  Si le menu et le lancement n'est plus On Screen
	 *  La Frame se resize selon la valeur de x
	 *  Lance la generation des bombes
	 */
	public static void lancement() {		
		if (!getMenuOS() && !getLancementOS()) {
			if (Jeu.getx() >= 8) {
				Demineur.menu.setSize(30*Jeu.getx()+15,30*Jeu.gety()+80);
			} else {
				Demineur.menu.setSize(230,30*Jeu.gety()+80);
			}
			Jeu.generationBombes();
		}
	}
	/**
	 * Si une partie est d&eacute;j&agrave; enregistr&eacute;e on va lire dans save.txt 
	 * Les valeurs de tous les tableaux et les variables utiles au jeu se d&eacute;finiront
	 */
	public static void partieSave() {
		try {
			FileInputStream fichier = new FileInputStream("src/save.txt");
			DataInputStream donnees = new DataInputStream(fichier);
			try {
				if (donnees.available() > 0) {
					Jeu.setx(donnees.readInt());
					Jeu.sety(donnees.readInt());
					Jeu.setCompte(donnees.readInt());
					for(int i = 0; i < Jeu.getx(); i++) {
						for (int h = 0; h < Jeu.gety(); h++) {
							Jeu.getTab()[i][h] = donnees.readInt();
							JeuRun.getAction()[i][h] = donnees.readBoolean();
							Jeu.getDec()[i][h] = donnees.readBoolean();
							JeuRun.getDrapT()[i][h] = donnees.readBoolean();
							JeuRun.getDrapP()[i][h] = donnees.readBoolean();
						}
					}
					Jeu.setBombs(donnees.readInt());
				}
			} catch (IOException e1) {
				System.err.println("Erreur de lecture !");
			} try {
				fichier.close();
			} catch (IOException e2) {
				System.err.println("Erreur de fermeture !");
			}
		} catch (FileNotFoundException e3) {
			System.err.println("Erreur d'ouverture !");
		}
		if (!getMenuOS()) {
			Demineur.menu.setSize(30*Jeu.getx()+15,30*Jeu.gety()+80);
			Demineur.menu.setContentPane(Panel);
		}
	}
	/**
	 * Si l'utilisateur clique sur le bouton quit ou la croix en haut &agrave; droite
	 * Et si c'est lors d'une partie en cours
	 * Alors les valeurs de tous les tableaux et les variables utiles au jeu seront dans le fichier save.txt
	 */
	public static void partieEcriture() {
		try {
			FileOutputStream fichier = new FileOutputStream("src/save.txt");
			DataOutputStream donnees = new DataOutputStream(fichier);
			try {
				donnees.writeInt(Jeu.getx());
				donnees.writeInt(Jeu.gety());
				donnees.writeInt(Jeu.getCompte());
				for(int i = 0; i < Jeu.getx(); i++) {
					for (int h = 0; h < Jeu.gety(); h++) {
						donnees.writeInt(Jeu.getTab()[i][h]);
						donnees.writeBoolean(JeuRun.getAction()[i][h]);
						donnees.writeBoolean(Jeu.getDec()[i][h]);
						donnees.writeBoolean(JeuRun.getDrapT()[i][h]);
						donnees.writeBoolean(JeuRun.getDrapP()[i][h]);
					}
				}
				donnees.writeInt(Jeu.getBombs());
			} catch (IOException e1) {
				System.err.println("Erreur d'ecriture !");
			} try {
				fichier.close();
			} catch (IOException e2) {
				System.err.println("Erreur de fermeture !");
			}
		} catch (FileNotFoundException e3) {
			System.err.println("Erreur d'ouverture !");
		}
		System.exit(0);
	}
}