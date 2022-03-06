package draw;

import shapes.Circle;
import shapes.Polygon;
import shapes.Segment;
import shapes.Triangle;

/**
 * DrawAWT class implementing the Draw class, to draw the shapes with AWT
 */
public class DrawAWT implements Draw {
	/**
	 * method to visit the Segment class
	 * @param s the segment to draw with AWT
	 */
	@Override
	public void visit(Segment s) {	
		System.out.println("AWT: drawing the segment : " + s);
	}
	
	/**
	 * method to visit the Triangle class
	 * @param t the triangle to draw with AWT
	 */
	@Override
	public void visit(Triangle t) {
		System.out.println("AWT: drawing the triangle : " + t);
	}
	
	/**
	 * method to visit the Circle class
	 * @param c the circle to draw with AWT
	 */
	@Override
	public void visit(Circle c) {
		System.out.println("AWT: drawing the circle : " + c);
	}
	
	/**
	 * method to visit the Polygon class
	 * @param p the polygon to draw with AWT
	 */
	@Override
	public void visit(Polygon p) {
		System.out.println("AWT: drawing the polygon : " + p);
	}
}
