package expert;

import shapes.Triangle;
import shapes.Vector2f;
import shapes.VisitorShape;

/**
 * ExpertTriangle class implementing the ExpertShape class, for the parsing of the triangle shape
 */
public class ExpertTriangle extends ExpertShape {
	public ExpertTriangle(ExpertShape next) { super(next); }
	
	/**
	 * method to parse a string and draw the shape represented in it
	 * @param s the string to parse
	 * @param v the visitor which will draw the shape
	 * @return a boolean, true if the shape is founded in the COR, false if we need to continue searching
	 */
	boolean resolve1(String s, VisitorShape v) {
		String [] parsedMessage = s.split(";");
		
		if(parsedMessage[0].equals("TRIANGLE")){
			int color = Integer.parseInt(parsedMessage[1]);
			
			double x1 = Double.parseDouble(parsedMessage[2]);
			double y1 = Double.parseDouble(parsedMessage[3]);
			Vector2f v1 = new Vector2f(x1, y1);
			
			double x2 = Double.parseDouble(parsedMessage[4]);
			double y2 = Double.parseDouble(parsedMessage[5]);	
			Vector2f v2 = new Vector2f(x2, y2);
			
			double x3 = Double.parseDouble(parsedMessage[6]);
			double y3 = Double.parseDouble(parsedMessage[7]);	
			Vector2f v3 = new Vector2f(x3, y3);

			Triangle triangle = new Triangle(color, v1, v2, v3);
			
			triangle.accept(v);
			
			return true;
		}
		return false;
	}
}
