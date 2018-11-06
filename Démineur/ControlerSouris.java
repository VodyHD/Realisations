import java.awt.event.*;
/**
 * La classe ControlerSouris est utilis&eacute;e pour capturer les mouvements de la souris dans la Frame.
 *  
 * @version 0.1
 * @author Thomas Quernec
 */
public class ControlerSouris implements MouseMotionListener {
	/**
	 * Permets d'identifier par la suite le JPanel.
	 */
	private Fenetre p;
	/**
	 * Ce constructeur permet d'identifier le JPanel -> Fenetre.
	 */
	public ControlerSouris(Fenetre panel) {
		this.p = panel;
	}
	/**
	 * &Agrave; chaque mouvement de souris elle va envoyer les coordonn&eacute;es et le boutton &agrave; la m&eacute;thode survolSouris.
	 *  
	 * @param l'evenement MouseEvent
 	 */
	@Override
	public void mouseMoved(MouseEvent e) {
		this.p.survolSouris(e.getX(),e.getY());
	}
	@Override
	public void mouseDragged(MouseEvent e) {
	}
}
