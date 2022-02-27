package expert;

import java.util.ArrayList;

import shapes.Polygon;
import shapes.Vector2f;
import shapes.VisitorShape;

/**
 * ExpertPolygon class implementing the ExpertShape class, for the parsing of the polygon shape
 */
public class ExpertPolygon extends ExpertShape {
	public ExpertPolygon(ExpertShape next) { super(next); }
	
	/**
	 * method to parse a string and draw the shape represented in it
	 * @param s the string to parse
	 * @param v the visitor which will draw the shape
	 * @return a boolean, true if the shape is founded in the COR, false if we need to continue searching
	 */
	boolean resolve1(String s, VisitorShape v) {
		String [] parsedMessage = s.split(";");
		
		if(parsedMessage[0].equals("POLYGON")){
			int color = Integer.parseInt(parsedMessage[1]);
			
			ArrayList<Vector2f> vectors = new ArrayList<Vector2f>();

			for(int i=2; i < parsedMessage.length-1; i+=2) {
				double x = Double.parseDouble(parsedMessage[i]);
				double y = Double.parseDouble(parsedMessage[i+1]);
				Vector2f vect = new Vector2f(x, y);
				
				vectors.add(vect);
			}

			Polygon polygon = new Polygon(color, vectors);
			
			polygon.accept(v);
			
			return true;
		}
		return false;
	}
}
