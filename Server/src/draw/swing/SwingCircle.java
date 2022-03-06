package draw.swing;

import shapes.Circle;
import java.awt.geom.Ellipse2D;
import java.awt.Graphics2D;

/**
 * SwingShape class extending the SwingShape class, to paint a circle with Swing
 */
public class SwingCircle extends SwingShape {
	private Circle c;
	
	public SwingCircle(Circle cir) {
		c = cir;
	}
	
	/**
	 * method to paint a circle on the Graphics2D
	 * @param g2d the graphics to paint on
	 */
	@Override
	public void paint(Graphics2D g2d) {
		Ellipse2D.Double circle = new Ellipse2D.Double(c.get_center().get_x() - c.get_radius(), 
				c.get_center().get_y() - c.get_radius(), c.get_radius()*2, c.get_radius()*2);
		g2d.setColor(_swingColors[c.get_color()]);
		g2d.fill(circle);
	}
}
