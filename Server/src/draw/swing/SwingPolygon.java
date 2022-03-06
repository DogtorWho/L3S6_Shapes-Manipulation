package draw.swing;

import shapes.Polygon;
import java.awt.geom.Path2D;
import java.awt.Graphics2D;

/**
 * SwingShape class extending the SwingShape class, to paint a polygon with Swing
 */
public class SwingPolygon extends SwingShape {
	private Polygon p;
	
	public SwingPolygon(Polygon pol) {
		p = pol;
	}
	
	/**
	 * method to paint a polygon on the Graphics2D
	 * @param g2d the graphics to paint on
	 */
	@Override
	public void paint(Graphics2D g2d) {
		Path2D.Double polygon = new Path2D.Double();
		g2d.setColor(_swingColors[p.get_color()]);
		
		polygon.moveTo(p.get_vectors().get(0).get_x(), p.get_vectors().get(0).get_y());
		for(int i=1; i < p.get_vectors().size(); i++) {
			polygon.lineTo(p.get_vectors().get(i).get_x(), p.get_vectors().get(i).get_y());
		}
		polygon.closePath();
		g2d.fill(polygon);
	}
}
