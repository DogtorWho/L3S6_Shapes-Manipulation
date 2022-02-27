package expert;

import shapes.Segment;
import shapes.VisitorShape;
import shapes.Vector2f;

/**
 * ExpertSegment class implementing the ExpertShape class, for the parsing of the segment shape
 */
public class ExpertSegment extends ExpertShape {
	public ExpertSegment(ExpertShape next) { super(next); }
	
	/**
	 * method to parse a string and draw the shape represented in it
	 * @param s the string to parse
	 * @param v the visitor which will draw the shape
	 * @return a boolean, true if the shape is founded in the COR, false if we need to continue searching
	 */
	boolean resolve1(String s, VisitorShape v) {
		String [] parsedMessage = s.split(";");
		
		if(parsedMessage[0].equals("SEGMENT")){
			int color = Integer.parseInt(parsedMessage[1]);
			
			double x1 = Double.parseDouble(parsedMessage[2]);
			double y1 = Double.parseDouble(parsedMessage[3]);
			Vector2f v1 = new Vector2f(x1, y1);
			
			double x2 = Double.parseDouble(parsedMessage[4]);
			double y2 = Double.parseDouble(parsedMessage[5]);	
			Vector2f v2 = new Vector2f(x2, y2);

			Segment segment = new Segment(color, v1, v2);
			
			segment.accept(v);
			
			return true;
		}
		return false;
	}
}
