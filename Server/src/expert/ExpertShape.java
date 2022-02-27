package expert;

import shapes.VisitorShape;

/**
 * ExpertShape class implementing the Expert class, for the parsing of the different shapes
 */
public abstract class ExpertShape implements Expert {
	/**
	 * ExpertShape stocking the next node in the COR chain
	 */
	public ExpertShape _next;
	
	ExpertShape(ExpertShape next) { _next = next; }
	
	/**
	 * method to navigate in the COR nodes
	 * @param s the string to parse
	 * @param v the visitor which will draw the shape
	 * @return a boolean, true if the shape is founded in the COR, false if we need to continue searching
	 */
	public boolean resolve(String s, VisitorShape v) {
		boolean result = this.resolve1(s, v);
		
		if(!result) {
			if(this._next != null)
				return this._next.resolve(s, v);
			else
				return false;
		}
		return true;
	}
	
	/**
	 * method to parse a string and draw the shape represented in it
	 * @param s the string to parse
	 * @param v the visitor which will draw the shape
	 * @return a boolean, true if the shape is founded in the COR, false if we need to continue searching
	 */
	abstract boolean resolve1(String s, VisitorShape v);
	
}
