package shapes;

import java.util.Dictionary;

/**
 * Color class for the color of a shape
 */
public class Color {
	/**
	 * Dictionary stocking the colors name and their value
	 */
	private Dictionary<Integer, String> _colors;
	/**
	 * int stocking the color value
	 */
	private int _value;
	
	public Color(int value) { 
		_colors.put(0, "BLACK");
		_colors.put(1, "BLUE");
		_colors.put(2, "RED");
		_colors.put(3, "GREEN");
		_colors.put(4, "YELLOW");
		_colors.put(5, "CYAN");
		
		_value = value;
	}
	public String getColor() {
		return (_colors.get(_value));
	}
	
	public Dictionary<Integer, String> getColors() { return _colors; }
	public int getValue() { return _value; }
}
