package draw;

import shapes.Circle;
import shapes.Polygon;
import shapes.Segment;
import shapes.Triangle;

/**
 * DrawAWT class implementing the Draw class, to draw the shapes with AWT
 */
public class DrawAWT extends Draw {
	@Override
	public void visit(Segment s) {	
		System.out.println("AWT: drawing the segment : " + s);
	}

	@Override
	public void visit(Triangle t) {
		System.out.println("AWT: drawing the triangle : " + t);
	}

	@Override
	public void visit(Circle c) {
		System.out.println("AWT: drawing the circle : " + c);
	}

	@Override
	public void visit(Polygon p) {
		System.out.println("AWT: drawing the polygon : " + p);
	}
}
