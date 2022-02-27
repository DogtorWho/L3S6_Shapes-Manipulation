package shapes;

/**
 * VEctor2f class to manipulate vector of double
 */
public class Vector2f {	
	/**
	 * double stocking the x position value of the vector
	 */
	private double _x;
	/**
	 * double stocking the y position value of the vector
	 */
	private double _y;
	
	public Vector2f(double x, double y) {
		this._x = x;
		this._y = y;
	}
	
	public double get_x() { return _x; }
	public double get_y() { return _y; }
	
	public void set_x(double _x) { this._x = _x; }	
	public void set_y(double _y) { this._y = _y; }
	
	@Override
	public String toString() {
		return "Vector2f [_x=" + _x + ", _y=" + _y + "]";
	}
}
