import java.awt.event.WindowEvent;
import java.awt.event.*;
/**
 * La classe ControlerFenetre est utilis&eacute;e pour capturer l'event de fermeture de la Frame.
 *  
 * @version 0.1
 * @author Thomas Quernec
 */
public class ControlerFenetre implements WindowListener{
	/**
	 * Si c'est lors d'une partie et qu'elle est en cours,
	 * On va demander &agrave; la m&eacute;thode partieEcriture() d'&eacute;crire les donn&eacute;es de la partie en cours.
	 * 
	 * @param WindowEvent
	 */
	@Override
	public void windowClosing(WindowEvent arg0) {
		if (Jeu.getVict() == 0 && !Menu.getMenuOS() && !Menu.getLancementOS()) {
			Menu.partieEcriture();
		}
	}
	@Override
	public void windowActivated(WindowEvent arg0) {}
	@Override
	public void windowClosed(WindowEvent arg0) {}
	@Override
	public void windowDeactivated(WindowEvent arg0) {}
	@Override
	public void windowDeiconified(WindowEvent arg0) {}
	@Override
	public void windowIconified(WindowEvent arg0) {}
	@Override
	public void windowOpened(WindowEvent arg0) {}

}
