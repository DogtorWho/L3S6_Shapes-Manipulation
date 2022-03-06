package draw.swing;

import shapes.Triangle;
import java.awt.geom.Path2D;
import java.awt.Graphics2D;

/**
 * SwingShape class extending the SwingShape class, to paint a triangle with Swing
 */
public class SwingTriangle extends SwingShape {
	private Triangle t;
	
	public SwingTriangle(Triangle tri) {
		t = tri;
	}
	
	/**
	 * method to paint a triangle on the Graphics2D
	 * @param g2d the graphics to paint on
	 */
	@Override
	public void paint(Graphics2D g2d) {
		Path2D.Double triangle = new Path2D.Double();
		g2d.setColor(_swingColors[t.get_color()]);
		triangle.moveTo(t.get_a().get_x(), t.get_a().get_y());
		triangle.lineTo(t.get_b().get_x(), t.get_b().get_y());
		triangle.lineTo(t.get_c().get_x(), t.get_c().get_y());
		triangle.closePath();
		g2d.fill(triangle);
	}
}


