package draw.swing;

import shapes.Segment;
import java.awt.geom.Line2D;
import java.awt.Graphics2D;

/**
 * SwingShape class extending the SwingShape class, to paint a segment with Swing
 */
public class SwingSegment extends SwingShape {
	private Segment s;
	
	public SwingSegment(Segment seg) {
		s = seg;
	}
	
	/**
	 * method to paint a segment on the Graphics2D
	 * @param g2d the graphics to paint on
	 */
	@Override
	public void paint(Graphics2D g2d) {
		Line2D.Double segment = new Line2D.Double(s.get_a().get_x(), s.get_a().get_y(), s.get_b().get_x(), s.get_b().get_y());
		g2d.setColor(_swingColors[s.get_color()]);
		g2d.draw(segment);
	}
}
