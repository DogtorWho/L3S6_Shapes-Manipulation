package shapes;

public class Circle extends Shape {
	/**
	 * Vector2f stocking the center point of the triangle
	 */
	private Vector2f _center;
	/**
	 * double stocking the radius of the circle
	 */
	private double _radius;
	
	public Circle(int color, Vector2f center, double radius) {
		super(color);
		this._center = center;
		this._radius = radius;
	}
	
	/**
	 * method accepting a visitor
	 * @param v the visitor
	 */
	public void accept(VisitorShape v) {
		v.visit(this);
	}

	public Vector2f get_center() { return _center; }
	public double get_radius() { return _radius; }

	public void set_center(Vector2f center) { this._center = center; }
	public void set_radius(double radius) { this._radius = radius; }

	@Override
	public String toString() {
		return "Circle [_center=" + _center + ", _radius=" + _radius + ", get_color()=" + get_color() + "]";
	}
}
