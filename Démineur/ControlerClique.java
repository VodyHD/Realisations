import java.awt.event.*;
/**
 * La classe ControlerClique est utilis&eacute;e pour capturer les clics de la souris dans la Frame.
 *  
 * @version 0.1
 * @author Thomas Quernec
 */
public class ControlerClique implements MouseListener {
	/**
	 * Permets d'identifier par la suite le JPanel.
	 */	
	private Fenetre p;
	/**
	 * Ce constructeur permet d'identifier le JPanel -> Fenetre.
	 */
	public ControlerClique(Fenetre panel) {
		this.p = panel;
	}
	/**
	 * &Agrave; chaque clic de souris elle va envoyer les coordonn&eacute;es,
	 * Et le boutton a la m&eacute;thode cliqueSouris.
	 *  
	 * @param l'evenement MouseEvent
 	 */
	@Override
	public void mouseClicked(MouseEvent e) {
		this.p.cliqueSouris(e.getX(),e.getY(),e.getButton());
	}
	@Override
	public void mouseEntered(MouseEvent arg0) {}
	@Override
	public void mouseExited(MouseEvent arg0) {}
	@Override
	public void mousePressed(MouseEvent arg0) {}
	@Override
	public void mouseReleased(MouseEvent arg0) {}
}