/**
 * @file Triangle.hpp
 * File containing methods to create a triangle shape
 */
#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shape.hpp"

class Triangle : public Shape {
  private :
    // === Variables ===
    /** @var _a
     * @brief Vector2f stocking the first point of the triangle
     */
    Vector2f _a;

    /** @var _b
     * @brief Vector2f stocking the second point of the triangle
     */
    Vector2f _b;

    /** @var _c
     * @brief Vector2f stocking the third point of the triangle
     */
    Vector2f _c;

  public :
    // === Constructor & Destructor ===
    /**
     * @fn Triangle(Vector2f a, Vector2f b, Vector2f c, ShapeColor col)
     * @brief Constructor of the Triangle class
     * @param a the first point of the triangle (default=Vector2f(0,0))
     * @param b the second point of the triangle (default=Vector2f(0,0))
     * @param c the third point of the triangle (default=Vector2f(0,0))
     * @param col color of the triangle (default=SHAPE_BLACK)
     */
    Triangle(Vector2f a = Vector2f(), Vector2f b = Vector2f(), Vector2f c = Vector2f(), ShapeColor col = SHAPE_BLACK) : Shape(col), _a(a), _b(b), _c(c) {}

    /**
     * @fn Triangle(const Triangle& s)
     * @brief Copy Constructor of the Triangle class
     * @param t the triangle to copy
     */
    Triangle(const Triangle &t) : Shape(t._color), _a(t._a), _b(t._b), _c(t._c) {}

    /**
     * @fn virtual ~Triangle()
     * @brief Destructor of the Triangle class
     */
    virtual ~Triangle() {}

    // === Getters & Setters ===

    // === Functions ===
    /**
     * @fn Vector2f& getA()
     * @brief getter for the first point of the triangle
     * @return Vector2f&
     */
    const Vector2f& getA() const { return _a; }

    /**
     * @fn Vector2f& getB()
     * @brief getter for the second point of the triangle
     * @return Vector2f&
     */
    const Vector2f& getB() const { return _b; }

    /**
     * @fn Vector2f& getC()
     * @brief getter for the second point of the triangle
     * @return Vector2f&
     */
    const Vector2f& getC() const { return _c; }

    /**
     * @fn const Triangle& operator=(const Triangle &t)
     * @brief overload of the = operator of Triangle
     * @param v the new triangle
     * @return const Triangle&
     */
    const Triangle& operator=(const Triangle &t) { _a = t._a; _b = t._b; _c = t._c; _color = t._color; return *this; }

    // === Functions ===
    void translate(Vector2f v);
    void homothety(Vector2f v, double zoom);
    void rotate(Vector2f v, double radian);

    /**
     * @fn double getArea()
     * @brief getter of the area of the triangle
     * @return double
     */
    double getArea() const;

    /**
     * @fn Shape* clone()
     * @brief clone the segment
     * @return Triangle*
     */
    Shape* clone() const { return new Triangle(*this); }

    /**
     * @fn void accept(VisitorShape *v)
     * @brief visit the triangle
     * @param v the visitor of the triangle
     */
    void accept(const VisitorShape *v) const;

    /**
     * @fn operator std::string()
     * @brief overload of the string cast operator
     * @return std::string
     */
    operator std::string() const {
      std::ostringstream os;
      os << "Triangle :\n";
      os << "\t- " << _a << "\n";
      os << "\t- " << _b << "\n";
      os << "\t- " << _c;
      return os.str();
    }

    /**
     * @fn std::string export_to_string()
     * @brief export the triangle into a string
     * @return std::string
     */
    std::string export_to_string() const {
      std::ostringstream os;
      os << "TRIANGLE;" << _color << ";";
      os << _a.export_to_string();
      os << _b.export_to_string();
      os << _c.export_to_string();
      os << "END;";
      return os.str();
    }
};

#endif
