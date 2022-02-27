package shapes;

/**
 * Segment class extending the Shape class, to manipulate a segment shape
 */
public class Segment extends Shape {
	/**
	 * Vector2f stocking the first point of the segment
	 */
	private Vector2f _a;
	/**
	 * Vector2f stocking the second point of the segment
	 */
	private Vector2f _b;
	
	public Segment(int color, Vector2f a, Vector2f b) {
		super(color);
		this._a = a;
		this._b = b;
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

	public void set_a(Vector2f a) { this._a = a; }
	public void set_b(Vector2f b) { this._b = b; }
	
	@Override
	public String toString() {
		return "Segment [_a=" + _a + ", _b=" + _b + ", get_color()=" + get_color() + "]";
	}
}
