package shapes;

import java.util.ArrayList;

public class Polygon extends Shape {
	/**
	 * ArrayList stocking all the vectors of the polygon
	 */
	private ArrayList<Vector2f> _vectors;
	
	public Polygon(int color) { super(color); }
	
	public Polygon(int color, ArrayList<Vector2f> vectors) {
		super(color);
		this.set_vectors(vectors);
	}
	
	/**
	 * method accepting a visitor
	 * @param v the visitor
	 */
	public void accept(VisitorShape v) {
		v.visit(this);
	}

	public ArrayList<Vector2f> get_vectors() { return _vectors; }
	public void set_vectors(ArrayList<Vector2f> _vectors) { this._vectors = _vectors; }

	@Override
	public String toString() {
		return "Polygon [_vectors=" + _vectors + ", get_color()=" + get_color() + "]";
	}
}
