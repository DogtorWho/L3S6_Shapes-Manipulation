package shapes;

/**
 * Triangle class extending the Shape class, to manipulate a triangle shape
 */
public class Triangle extends Shape {
	/**
	 * Vector2f stocking the first point of the triangle
	 */
	private Vector2f _a;
	/**
	 * Vector2f stocking the second point of the triangle
	 */
	private Vector2f _b;
	/**
	 * Vector2f stocking the third point of the triangle
	 */
	private Vector2f _c;
	
	public Triangle(int color, Vector2f a, Vector2f b, Vector2f c) {
		super(color);
		this._a = a;
		this._b = b;
		this._c = c;
	}
	
	/**
	 * method accepting a visitor
	 * @param v the visitor
	 */
	public void accept(VisitorShape v) {
		v.visit(this);
	}

	public Vector2f get_a() { return _a; }
	public Vector2f get_b() { return _b; }
	public Vector2f get_c() { return _c; }

	public void set_a(Vector2f a) { this._a = a; }
	public void set_b(Vector2f b) { this._b = b; }
	public void set_c(Vector2f c) { this._c = c; }

	@Override
	public String toString() {
		return "Triangle [_a=" + _a + ", _b=" + _b + ", _c=" + _c + ", get_color()=" + get_color() + "]";
	}
}
