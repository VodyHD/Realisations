import java.awt.*;
import java.io.*;
import javax.swing.*;
/**
 * La classe Fenetre est utilis&eacute;e pour l'affichage de tous les &eacute;l&eacute;ments.
 *  
 * @version 0.1
 * @author Thomas Quernec
 */
public class Fenetre extends JPanel {
	/**
     * Permets de changer la surbrillance d'un titre grace a un boolean.
     * True = survol&eacute;.
     * False = non survol&eacute;.
     */
	private static boolean survolT[] = new boolean [7];
	/**
	 * Permets de g&eacute;rer tous les clics du programme (menu, menu de lancement, jeu).
	 * 
     * @param xS
     * @param yS
     * @param button
     */
	public void cliqueSouris(int xS, int yS, int button) {
		//Jeu
		if (!Menu.getMenuOS() && !Menu.getLancementOS()) {
			//Lorsque le joueur appuit sur "Quit"
			if (Jeu.getVict() == 0 && (xS > this.getWidth()-65) && (xS < this.getWidth()-8) && (yS > this.getHeight()-14) && (yS < Demineur.menu.getHeight()) && button == 1) Menu.partieEcriture();
			//Lorsque le joueur clic sur "Menu"
			if ((xS > 100) && (xS < 190) && (yS > this.getHeight()-14) && (yS < Demineur.menu.getHeight())) {
				Menu.setMenuOS(true);
				Menu.setLancementOS(false);
				JeuRun.reset();
			}
			//Chaque case clique passe par ici
			if ((xS > 0) && (xS < this.getWidth()) && (yS > 0) && (yS < this.getHeight())) {
				//Permet d'avoir les coordonnees par rapport au tableau [30][30]
				JeuRun.getS()[0] = xS/30;
				yS-=30;
				JeuRun.getS()[1] = yS/30;
				//Lorsque le joueur utilise le clic gauche sur une case
				if ((button == 1) && JeuRun.getAction()[JeuRun.getS()[0]][JeuRun.getS()[1]]) {
					JeuRun.victoire();
					JeuRun.apparition();
					this.repaint();
				//Lorsque le joueur utilise le clic droit sur une case
				} else if (button == 3 && !Jeu.getDec()[JeuRun.getS()[0]][JeuRun.getS()[1]] && Jeu.getVict() == 0) {
					JeuRun.drap();
					this.repaint();
				}
			}
		//Menu	
		} else if (Menu.getMenuOS() && !Menu.getLancementOS()) {
			//Lorque le joueur clic sur "Play"
			if ((xS > 180) && (xS < 320) && (yS > 90) && (yS < 180) && button == 1) {
				Menu.setLancementOS(true);
				Menu.lancement();
			}
			//Lorque le joueur clic sur "Resume"
			if ((xS > 170) && (xS < 420) && (yS > 200) && (yS < 290) && button == 1) {
				try {
					FileInputStream fichier = new FileInputStream("src/save.txt");
					DataInputStream donnees = new DataInputStream(fichier);
					try {
						//Seulement si une partie est deja enregistree
						if (donnees.available() > 0) {
							Menu.setMenuOS(false);
							Menu.partieSave();
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
			}
			//Lorque le joueur clic sur "Quit"
			if ((xS > 190) && (xS < 330) && (yS > 340) && (yS < 420) && button == 1) System.exit(0);
		//Menu de lancement
		} else if (Menu.getMenuOS() && Menu.getLancementOS()) {
			//Modification du nombre de mines
			if ((xS > 230) && (xS < 270) && (yS > 125) && (yS < 164)) {
				if (Jeu.getBombs() > 0) Jeu.setBombs(Jeu.getBombs() - 1);
			}
			if ((xS > 230) && (xS < 270) && (yS > 166) && (yS < 190)) {
				if (Jeu.getBombs() > 0) Jeu.setBombs(Jeu.getBombs() - 10);
			}
			if ((xS > 390) && (xS < 430) && (yS > 125) && (yS < 164)) {
				if (Jeu.getBombs() < Jeu.getx()*Jeu.gety()-1) Jeu.setBombs(Jeu.getBombs() + 1);
			}
			if ((xS > 390) && (xS < 430) && (yS > 166) && (yS < 190)) {
				if (Jeu.getBombs()+10 < Jeu.getx()*Jeu.gety()-1) Jeu.setBombs(Jeu.getBombs() + 10);
			}
			//Modification du x
			if ((xS > 230) && (xS < 270) && (yS > 230) && (yS < 290)) {
				if (Jeu.getx() > 4 && Jeu.getBombs()+1 <= Jeu.getx()*Jeu.gety()) Jeu.setx(Jeu.getx() - 1);
			}
			if ((xS > 410) && (xS < 480) && (yS > 230) && (yS < 290)) {
				if (Jeu.getx() < 30) Jeu.setx(Jeu.getx() + 1);
			}
			//Modification du y
			if ((xS > 230) && (xS < 270) && (yS > 320) && (yS < 380)) {
				if (Jeu.gety() > 4 && Jeu.getBombs() <= Jeu.getx()*Jeu.gety()) Jeu.sety(Jeu.gety() - 1);
			}
			if ((xS > 410) && (xS < 480) && (yS > 320) && (yS < 380)) {
				if (Jeu.gety() < 30) Jeu.sety(Jeu.gety() + 1);
			}
			//Lorsque le joueur clic sur "Start"
			if ((xS > 190) && (xS < 330) && (yS > 400) && (yS < 460)) {
				Menu.setLancementOS(false);
				Menu.setMenuOS(false); 
				Menu.lancement();
			}
		}
		this.repaint();
	}
	/**
     * Permet de changer la surbrillance d'un titre grace a un boolean.
     * True = survol&eacute;.
     * False = non survol&eacute;.
     */
	public void survolSouris(int xS, int yS) {
		if ((xS > this.getWidth()-65) && (xS < this.getWidth()-8) && (yS > this.getHeight()-14) && (yS < Demineur.menu.getHeight())) survolT[0] = true;
		else survolT[0] = false;
		if ((xS > 180) && (xS < 320) && (yS > 90+26) && (yS < 180+26)) survolT[1] = true;
		else survolT[1] = false;
		if ((xS > 170) && (xS < 420) && (yS > 200+26) && (yS < 290+26)) survolT[2] = true;
		else survolT[2] = false;
		if ((xS > 190) && (xS < 330) && (yS > 340) && (yS < 420)) survolT[3] = true;
		else survolT[3] = false;
		if ((xS > 190) && (xS < 330) && (yS > 400) && (yS < 460)) survolT[4] = true;
		else survolT[4] = false;
		if ((xS > 100) && (xS < 190) && (yS > this.getHeight()-14) && (yS < Demineur.menu.getHeight())) survolT[5] = true;
		else survolT[5] = false;
		this.repaint();
	}
	/**
     * Permets de g&eacute;rer toute la partie graphique du programme.
     */
	@Override
	public void paintComponent(Graphics pinceau) {
		Graphics secondPinceau = pinceau.create();
		if (this.isOpaque()) {
			pinceau.setColor(this.getBackground());
			pinceau.fillRect(0, 0, this.getWidth(), this.getHeight());
		}
		//Ajoute une image de fond
		secondPinceau.drawImage(new ImageIcon("src/background.jpg").getImage(), 0, 0, this.getWidth(), this.getHeight(), null);
		//Jeu
		if (!Menu.getMenuOS() && !Menu.getLancementOS()) {
			for (int i = 0; i<Jeu.getx(); i++) {
				for (int h = 0; h<Jeu.gety(); h++) {
					secondPinceau.drawImage(new ImageIcon("src/case1.png").getImage(), i*30, h*30, 30, 30, null);
					if (JeuRun.getAction()[i][h] && (Jeu.getTab()[i][h] == 10 && !JeuRun.getDrapT()[i][h]) || ((Jeu.getTab()[i][h] == 10) && (Jeu.getVict() == 2))) {
						//Affichage de la mine perdante (case en rouge
						if (!JeuRun.getMineP()[i][h]) secondPinceau.setColor(Color.BLACK);
						secondPinceau.fillRect(i*30, h*30, 30, 30);
						secondPinceau.drawImage(new ImageIcon("src/bombe.png").getImage(), i*30+4, h*30+2, 25, 25,null);
					//Affichage des indicateur sr les cases decouvertes
					} else if ((Jeu.getTab()[i][h] >= 1) && (Jeu.getTab()[i][h] < 9)) {
						if (Jeu.getTab()[i][h] == 1) secondPinceau.setColor(new Color (0, 0, 255));
						if (Jeu.getTab()[i][h] == 2) secondPinceau.setColor(new Color (0, 255, 0));
						if (Jeu.getTab()[i][h] == 3) secondPinceau.setColor(new Color (238, 0, 0));
						if (Jeu.getTab()[i][h] == 4) secondPinceau.setColor(new Color (0, 0, 100));
						if (Jeu.getTab()[i][h] == 5) secondPinceau.setColor(new Color (0, 0, 0));
						if (Jeu.getTab()[i][h] == 6) secondPinceau.setColor(new Color (238, 58, 140));
						if (Jeu.getTab()[i][h] == 7) secondPinceau.setColor(new Color (0, 100, 0));
						if (Jeu.getTab()[i][h] == 8) secondPinceau.setColor(new Color (255, 255, 255));
						secondPinceau.setFont(new Font("Stikat", Font.BOLD, 20));
						secondPinceau.drawString(Integer.toString(Jeu.getTab()[i][h]),i*30+9,h*30+23);
					}
					//Seulement si la case en question est cachee
					if (!Jeu.getDec()[i][h]) {
						//Affichage d'une case cachee
						if (!JeuRun.getDrapT()[i][h]  && !JeuRun.getDrapP()[i][h]) {
							secondPinceau.drawImage(new ImageIcon("src/case.png").getImage(), i*30, h*30, 30, 30, null);
						//Affichage du marqueur : etoile
						} else if (JeuRun.getDrapT()[i][h]  && !JeuRun.getDrapP()[i][h]) {
							secondPinceau.drawImage(new ImageIcon("src/case.png").getImage(), i*30, h*30, 30, 30, null);
							secondPinceau.drawImage(new ImageIcon("src/etoile.png").getImage(), i*30, h*30, 30, 30, null);
						//Affichage du marqueur : ?
						} else if (!JeuRun.getDrapT()[i][h] && JeuRun.getDrapP()[i][h]){
							secondPinceau.drawImage(new ImageIcon("src/case.png").getImage(), i*30, h*30, 30, 30, null);
							secondPinceau.setColor(Color.BLACK);
							secondPinceau.setFont(new Font("Stikat", Font.BOLD, 20));
							secondPinceau.drawString("?",i*30+9,h*30+23);
						}
					}
					//Affichage du denouement de la partie
					secondPinceau.setColor(Color.RED);
					secondPinceau.setFont(new Font("Stikat", Font.BOLD, 40));
					if (Jeu.getVict() != 0) JeuRun.getAction()[i][h] = false;
					if (Jeu.getVict() == 2) secondPinceau.drawString("Perdu !",this.getWidth()/2,this.getHeight()-8);
					else if (Jeu.getVict() == 1) {
						secondPinceau.setColor(Color.GREEN);
						secondPinceau.drawString("Victoire !",this.getWidth()/2,this.getHeight()-8);
					}
				}
			}
			//Affichage de jeu (progression du joueur)
			secondPinceau.setColor(Color.BLACK);
			secondPinceau.setFont(new Font("Segoe Print", Font.BOLD, 20));
			secondPinceau.drawString(Integer.toString(Jeu.getCompte()),5,this.getHeight()-15);
			if (Jeu.getCompte() > 99) secondPinceau.drawImage(new ImageIcon("src/bombe.png").getImage(), 55, this.getHeight()-40, 40, 40,null);
			else secondPinceau.drawImage(new ImageIcon("src/bombe.png").getImage(), 35, this.getHeight()-40, 40, 40,null);
			//Boutton Menu
			if (survolT[5]) secondPinceau.setColor(Color.BLUE);
			secondPinceau.drawString("Menu", 100, this.getHeight()-15);
			secondPinceau.setColor(Color.BLACK);
			//Tant quye la partie n'est pas terminee le joueur peut l'enregistrer
			if (Jeu.getVict() == 0) {
				if (survolT[0]) secondPinceau.setColor(Color.BLUE);
					secondPinceau.drawString("Quit", this.getWidth()-65,this.getHeight()-15);
			}
		//Menu
		} else if (Menu.getMenuOS() && !Menu.getLancementOS()){
			//Title
			secondPinceau.setColor(Color.BLACK);
			secondPinceau.setFont(new Font("Segoe Print", Font.BOLD, 60));
			secondPinceau.drawString("Minesweeper",this.getWidth()/2-190, 50);
			secondPinceau.setFont(new Font("Segoe Print", Font.BOLD, 40));
			//Boutton Play
			if (survolT[1]) secondPinceau.setColor(Color.BLUE);
			secondPinceau.drawString("Play",210, 150);
			//Boutton Resume
			if (!survolT[2]) secondPinceau.setColor(Color.BLACK);
			else secondPinceau.setColor(Color.BLUE);
			secondPinceau.drawString("Resume",180, 260);
			//Boutton Quit
			if (!survolT[3]) secondPinceau.setColor(Color.BLACK);
			else secondPinceau.setColor(Color.BLUE);
			secondPinceau.drawString("Quit",210, 370);
		//Menu de lancement
		} else if (Menu.getMenuOS() && Menu.getLancementOS()) {
			//Bombs
			secondPinceau.drawImage(new ImageIcon("src/-.png").getImage(), 230, 90, 35, 35, null);
			secondPinceau.drawImage(new ImageIcon("src/-.png").getImage(), 230, 135, 35, 35, null);
			secondPinceau.drawImage(new ImageIcon("src/+.png").getImage(), 390, 90, 35, 35, null);
			secondPinceau.drawImage(new ImageIcon("src/+.png").getImage(), 390, 135, 35, 35, null);
			secondPinceau.setFont(new Font("Segoe Print", Font.BOLD, 40));
			if (Jeu.getBombs() > 99) secondPinceau.drawString(Integer.toString(Jeu.getBombs()),290, 150);
			else secondPinceau.drawString(Integer.toString(Jeu.getBombs()),310, 150);
			secondPinceau.setFont(new Font("Segoe Print", Font.BOLD, 20));
			secondPinceau.drawString("+ 1", 435, 115);
			secondPinceau.drawString("+ 10", 435, 160);
			//Width
			secondPinceau.setFont(new Font("Segoe Print", Font.BOLD, 40));
			secondPinceau.drawImage(new ImageIcon("src/-.png").getImage(), 220, 200, 50, 50, null);
			secondPinceau.drawImage(new ImageIcon("src/+.png").getImage(), 410, 200, 55, 55, null);
			secondPinceau.drawString(Integer.toString(Jeu.getx()),320,240);
			//Height
			secondPinceau.drawImage(new ImageIcon("src/-.png").getImage(), 220, 290, 50, 50, null);
			secondPinceau.drawImage(new ImageIcon("src/+.png").getImage(), 410, 290, 55, 55, null);
			secondPinceau.drawString(Integer.toString(Jeu.gety()),320,330);
			//Titres
			secondPinceau.setColor(Color.BLACK);
			secondPinceau.setFont(new Font("Segoe Print", Font.BOLD, 60));
			secondPinceau.drawString("Parameters",80, 50);
			secondPinceau.setFont(new Font("Segoe Print", Font.BOLD, 40));
			secondPinceau.drawString("Mines :",40, 150);
			secondPinceau.drawString("Width :",40, 240);
			secondPinceau.drawString("Height :",40, 330);
			//Boutton Start
			if (survolT[4]) secondPinceau.setColor(Color.BLUE);
			else secondPinceau.setColor(Color.BLACK);
			secondPinceau.drawString("Start",200, 420);
		}
	}
}