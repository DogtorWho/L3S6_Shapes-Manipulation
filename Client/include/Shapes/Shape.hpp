/**
 * @file Shape.hpp
 * File containing the base of all shapes
 */
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "Error.hpp"
#include "Vector2f.hpp"

class VisitorShape;

/**
 * @enum ShapeColor
 * @brief list of the possible colors of the shapes
 */
enum ShapeColor { SHAPE_BLACK, SHAPE_BLUE, SHAPE_RED, SHAPE_GREEN, SHAPE_YELLOW, SHAPE_CYAN };

class Shape {
  protected :
    // === Variables ===
    /** @var _color
     * @brief ShapeColor stocking the shape color
     */
    ShapeColor _color;

  public :
    // === Constructor & Destructor ===
    /**
     * @fn Shape()
     * @brief Constructor of the Shape class
     * @param c color of the shape (default=SHAPE_BLACK)
     */
    Shape(ShapeColor c = SHAPE_BLACK) : _color(c) {}

    /**
     * @fn virtual ~Shape()
     * @brief Destructor of the Shape class
     */
    virtual ~Shape(){}

    // === Getters & Setters ===
    /**
     * @fn ShapeColor getColor()
     * @brief getter for the color of the shape
     * @return ShapeColor
     */
    ShapeColor getColor() const { return _color; }

    /**
     * @fn ShapeColor getColor()
     * @brief setter for the color of the shape
     * @param c the new color of the shape
     */
    void setColor(ShapeColor c) { _color = c; }

    // === Functions ===
    /**
     * @fn void translate(Vector2f v)
     * @brief translate the shape
     * @param v the vector translating the shape
     */
    virtual void translate(Vector2f v) = 0;

    /**
     * @fn void homothety(Vector2f v, double zoom)
     * @brief zoom the shape
     * @param v the vector zooming the shape
     * @param zoom the double indicating the zoom factor
     */
    virtual void homothety(Vector2f v, double zoom) = 0;

    /**
     * @fn void rotate(Vector2f v, double radian)
     * @brief rotate the shape
     * @param v the vector rotating the shape
     * @param radian the double indicating the angle of the rotation
     */
    virtual void rotate(Vector2f v, double radian) = 0;

    /**
     * @fn double getArea()
     * @brief getter of the area of the shape
     * @return double
     */
    virtual double getArea() const = 0;

    /**
     * @fn Shape* clone()
     * @brief clone the shape
     * @return Shape*
     */
    virtual Shape* clone() const = 0;

    /**
     * @fn void accept(VisitorShape *v)
     * @brief visit the shape
     * @param v the visitor of the shape
     */
    virtual void accept(VisitorShape *v) const = 0;

    /**
     * @fn operator std::string()
     * @brief overload of the string cast operator
     * @return std::string
     */
    virtual operator std::string() const {
      std::ostringstream os;
      os << "Shape :\n";
      os << " - ShapeColor : " << _color;
      return os.str();
    }

    /**
     * @fn std::string export_to_string()
     * @brief export the shape into a string
     * @return std::string
     */
    virtual std::string export_to_string() const = 0;

    /**
     * @fn friend std::ostream& operator<< (std::ostream &s, Shape &shape)
     * @brief overload of the << operator to print the class info
     * @param s the stream to write to
     * @param shape the class to write into the stream
     * @return std::ostream&
     */
    friend std::ostream& operator<< (std::ostream &s, const Shape &shape);
};

inline std::ostream& operator<< (std::ostream &s, const Shape &shape){
  return (s << (std::string)shape);
}

#endif
