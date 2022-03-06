package draw.swing;

import shapes.Circle;
import shapes.Polygon;
import shapes.Segment;
import shapes.Triangle;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.util.ArrayList;

import javax.swing.*;

import draw.Draw;

/**
 * DrawSwing class implementing the Draw class, to draw the shapes with Swing
 */
@SuppressWarnings("serial")
public class DrawSwing extends JComponent implements Draw {
	/**
	 * JFrame stocking the Swing frame
	 */
	private JFrame _frame;
	/**
	 * ArrayList stocking the SwingShape to draw
	 */
	private ArrayList<SwingShape> _shapes;
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
		
		_shapes = new ArrayList<SwingShape>();
		
		_frame = new JFrame("Swing Frame");
		_frame.setSize(_width, _height);
		//_frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		_frame.setVisible(true);
		_frame.createBufferStrategy(2);
	}
	
	@Override
	protected void paintComponent(Graphics g) {
		Graphics2D g2d = (Graphics2D)g;
		RenderingHints rh = new RenderingHints(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		g2d.setRenderingHints(rh);
		
		for(int i=0; i < _shapes.size(); i++) {
			_shapes.get(i).paint(g2d);
		}
	}

	/**
	 * method to visit the Segment class
	 * @param s the segment to draw with Swing
	 */	
	@Override
	public void visit(Segment s) {
		System.out.println("Swing: drawing the segment : " + s);
		
		_shapes.add(new SwingSegment(s));
			
		_frame.add(this);
	}

	/**
	 * method to visit the Triangle class
	 * @param t the triangle to draw with Swing
	 */
	@Override
	public void visit(Triangle t) {
		System.out.println("Swing: drawing the triangle : " + t);
		
		_shapes.add(new SwingTriangle(t));
		
		_frame.add(this);
	}

	/**
	 * method to visit the Circle class
	 * @param c the circle to draw with Swing
	 */
	@Override
	public void visit(Circle c) {
		System.out.println("Swing: drawing the circle : " + c);
		
		_shapes.add(new SwingCircle(c));
		
		_frame.add(this);
	}

	/**
	 * method to visit the Polygon class
	 * @param p the polygon to draw with Swing
	 */
	@Override
	public void visit(Polygon p) {
		System.out.println("Swing: drawing the polygon : " + p);
				
		_shapes.add(new SwingPolygon(p));
		
		_frame.add(this);
	}
}
