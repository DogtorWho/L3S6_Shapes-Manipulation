package shapes;

/**
 * Shape abstract class, the base for the concrete shapes
 */
public abstract class Shape {
	/**
	 * int stocking the color of the shape
	 */
	private int _color;
	
	Shape(int value){ set_color(value); }

	public int get_color() { return _color; }
	public void set_color(int _color) { this._color = _color; }	
	
	@Override
	public String toString() {
		return "Shape [_color=" + _color + "]";
	}
}
