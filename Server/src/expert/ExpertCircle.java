package expert;

import shapes.Circle;
import shapes.Vector2f;
import shapes.VisitorShape;

/**
 * ExpertCircle class implementing the ExpertShape class, for the parsing of the circle shape
 */
public class ExpertCircle extends ExpertShape {
	public ExpertCircle(ExpertShape next) { super(next); }
	
	/**
	 * method to parse a string and draw the shape represented in it
	 * @param s the string to parse
	 * @param v the visitor which will draw the shape
	 * @return a boolean, true if the shape is founded in the COR, false if we need to continue searching
	 */
	boolean resolve1(String s, VisitorShape v) {
		String [] parsedMessage = s.split(";");
		
		if(parsedMessage[0].equals("CIRCLE")){
			int color = Integer.parseInt(parsedMessage[1]);
			
			double x1 = Double.parseDouble(parsedMessage[2]);
			double y1 = Double.parseDouble(parsedMessage[3]);
			Vector2f v1 = new Vector2f(x1, y1);
			
			double center = Double.parseDouble(parsedMessage[4]);

			Circle circle = new Circle(color, v1, center);
			
			circle.accept(v);
			
			return true;
		}
		return false;
	}
}
