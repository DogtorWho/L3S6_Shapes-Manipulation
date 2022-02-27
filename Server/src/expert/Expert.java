package expert;

import shapes.VisitorShape;

/**
 * Expert interface for the base of the COR design pattern
 */
interface Expert {
	/**
	 * method to navigate in the COR nodes
	 * @param s the string to parse
	 * @param v the visitor which will draw the shape
	 * @return a boolean, true if the shape is founded in the COR, false if we need to continue searching
	 */
	boolean resolve(String s, VisitorShape v);
}
