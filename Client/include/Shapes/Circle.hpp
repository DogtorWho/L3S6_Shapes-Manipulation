/**
 * @file Circle.hpp
 * File containing methods to create a circle shape
 */
#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape {
  private :
    // === Variables ===
    /** @var _center
     * @brief Vector2f stocking the center point of the circle
     */
    Vector2f _center;

    /** @var _radius
     * @brief double stocking the radius of the circle
     */
    double _radius;

  public :
    // === Constructor & Destructor ===
    /**
     * @fn Circle(Vector2f c, double rad, ShapeColor col)
     * @brief Constructor of the Circle class
     * @param c the center point of the circle (default=Vector2f(0,0))
     * @param rad the radius of the circle (default=0)
     * @param col color of the circle (default=SHAPE_BLACK)
     */
    Circle(const Vector2f c = Vector2f(), double rad = 0, ShapeColor col = SHAPE_BLACK) : Shape(col), _center(c), _radius(rad) {}

    /**
     * @fn Circle(const Circle& c)
     * @brief Copy Constructor of the Circle class
     * @param c the circle to copy
     */
    Circle(const Circle& c) : Shape(c._color), _center(c._center), _radius(c._radius) {}

    /**
     * @fn virtual ~Circle()
     * @brief Destructor of the Circle class
     */
    virtual ~Circle() {}

    // === Getters & Setters ===
    /**
     * @fn Vector2f& getCenter()
     * @brief getter for the center point of the circle
     * @return Vector2f&
     */
    const Vector2f& getCenter() const { return _center; }

    /**
     * @fn double getRadius() const
     * @brief getter for the radius of the circle
     * @return double
     */
    double getRadius() const { return _radius; }

    // === Functions ===
    void translate(Vector2f v);
    void homothety(Vector2f v, double zoom);
    void rotate(Vector2f v, double radian);

    /**
     * @fn double getArea()
     * @brief getter of the area of the circle
     * @return double
     */
    double getArea() const;

    /**
     * @fn Shape* clone()
     * @brief clone the circle
     * @return Circle*
     */
    Shape* clone() const { return new Circle(*this); }

    /**
     * @fn void accept(VisitorShape *v)
     * @brief visit the circle
     * @param v the visitor of the circle
     */
    void accept(VisitorShape *v) const;

    /**
     * @fn operator std::string()
     * @brief overload of the string cast operator
     * @return std::string
     */
    operator std::string() const {
      std::ostringstream os;
      os << "Circle :\n";
      os << "\t- " << _center << "\n";
      os << "\t- " << _radius;
      return os.str();
    }

    /**
     * @fn std::string export_to_string()
     * @brief export the circle into a string
     * @return std::string
     */
    std::string export_to_string() const {
      std::ostringstream os;
      os << "CIRCLE;" << _color << ";";
      os << _center.export_to_string();
      os << _radius << ";";
      os << "END;";
      return os.str();
    }
};

#endif
