package draw.swing;

import shapes.Circle;
import shapes.Polygon;
import shapes.Segment;
import shapes.Triangle;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Path2D;

import javax.swing.*;

import draw.Draw;

/**
 * DrawSwing class implementing the Draw class, to draw the shapes with Swing
 */
public class DrawSwing extends Draw {
	/**
	 * JFrame stocking the Swing frame
	 */
	private JFrame _frame;
	/**
	 * Color[] stocking the Swing colors of the shape
	 */
	private Color[] _swingColors = {Color.BLACK, Color.BLUE, Color.RED, Color.GREEN, Color.YELLOW, Color.CYAN };
	/**
	 * int stocking the width of the window
	 */
	private int _width;
	/**
	 * int stocking the height of the window
	 */
	private int _height;
	
	public DrawSwing(int width, int height) {
		_width = width;
		_height = height;
		
		_frame = new JFrame("Swing Frame");
		_frame.setSize(_width, _height);
		//_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		_frame.setVisible(true);
		_frame.createBufferStrategy(2);
	}

	@Override
	public void visit(Segment s) {
		System.out.println("Swing: drawing the segment : " + s);
		
		@SuppressWarnings("serial")
		JComponent canvas = new JComponent() {
			@Override
			protected void paintComponent(Graphics g) {
				Graphics2D g2d = (Graphics2D)g;
				
				RenderingHints rh = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
				g2d.setRenderingHints(rh);
				
				Line2D.Double segment = new Line2D.Double(s.get_a().get_x(), s.get_a().get_y(), s.get_b().get_x(), s.get_b().get_y());
				g2d.setColor(_swingColors[s.get_color()]);
				g2d.draw(segment);
			}
		};
		
		_frame.add(canvas);
	}

	@Override
	public void visit(Triangle t) {
		System.out.println("Swing: drawing the triangle : " + t);
		
		@SuppressWarnings("serial")
		JComponent canvas = new JComponent() {
			@Override
			protected void paintComponent(Graphics g) {
				Graphics2D g2d = (Graphics2D)g;		
				
				RenderingHints rh = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
				g2d.setRenderingHints(rh);
				
				Path2D.Double triangle = new Path2D.Double();
				g2d.setColor(_swingColors[t.get_color()]);
				triangle.moveTo(t.get_a().get_x(), t.get_a().get_y());
				triangle.lineTo(t.get_b().get_x(), t.get_b().get_y());
				triangle.lineTo(t.get_c().get_x(), t.get_c().get_y());
				triangle.closePath();
				g2d.fill(triangle);
			}
		};
		
		_frame.add(canvas);
	}

	@Override
	public void visit(Circle c) {
		System.out.println("Swing: drawing the circle : " + c);
		
		@SuppressWarnings("serial")
		JComponent canvas = new JComponent() {
			@Override
			protected void paintComponent(Graphics g) {
				super.paintComponent(g);
				
				Graphics2D g2d = (Graphics2D)g;
				
				RenderingHints rh = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
				g2d.setRenderingHints(rh);
				
				Ellipse2D.Double circle = new Ellipse2D.Double(c.get_center().get_x() - c.get_radius(), 
															c.get_center().get_y() - c.get_radius(), 
															c.get_radius()*2, c.get_radius()*2);
				g2d.setColor(_swingColors[c.get_color()]);
				g2d.fill(circle);
			}
		};
		
		_frame.add(canvas);
	}

	@Override
	public void visit(Polygon p) {
		System.out.println("Swing: drawing the polygon : " + p);
		
		@SuppressWarnings("serial")
		JComponent canvas = new JComponent() {
			@Override
			protected void paintComponent(Graphics g) {
				super.paintComponent(g);
				
				Graphics2D g2d = (Graphics2D)g;
				
				RenderingHints rh = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
				g2d.setRenderingHints(rh);
				
				Path2D.Double polygon = new Path2D.Double();
				g2d.setColor(_swingColors[p.get_color()]);
				
				polygon.moveTo(p.get_vectors().get(0).get_x(), p.get_vectors().get(0).get_y());
				for(int i=1; i < p.get_vectors().size(); i++) {
					polygon.lineTo(p.get_vectors().get(i).get_x(), p.get_vectors().get(i).get_y());
				}
				polygon.closePath();
				g2d.fill(polygon);	
			}
		};
		
		_frame.add(canvas);
	}

}
