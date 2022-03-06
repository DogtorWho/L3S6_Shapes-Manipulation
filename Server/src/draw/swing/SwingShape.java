package draw.swing;

import java.awt.Color;
import java.awt.Graphics2D;

/**
 * SwingShape class, to paint a shape with Swing
 */
public abstract class SwingShape {
	/**
	 * Color[] stocking the Swing colors of the shape
	 */
	protected Color[] _swingColors = {Color.BLACK, Color.BLUE, Color.RED, Color.GREEN, Color.YELLOW, Color.CYAN };
	
	/**
	 * method to paint a shape on the Graphics2D
	 * @param g2d the graphics to paint on
	 */
	public void paint(Graphics2D g2d) {}
}
