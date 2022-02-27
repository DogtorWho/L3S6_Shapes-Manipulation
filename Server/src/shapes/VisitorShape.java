package shapes;

/**
 * VisitorShape interface to visit the different shapes
 */
public interface VisitorShape {
	/**
	 * method to visit the Segment class
	 * @param s the segment to visit
	 */
	void visit(Segment s);
	/**
	 * method to visit the Triangle class
	 * @param t the triangle to visit
	 */
	void visit(Triangle t);
	/**
	 * method to visit the Circle class
	 * @param c the circle to visit
	 */
	void visit(Circle c);
	/**
	 * method to visit the Polygon class
	 * @param p the polygon to visit
	 */
	void visit(Polygon p);
}
