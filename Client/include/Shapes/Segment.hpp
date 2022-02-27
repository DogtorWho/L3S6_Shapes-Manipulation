/**
 * @file Segment.hpp
 * File containing methods to create a segment shape
 */
#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "Shape.hpp"

class Segment : public Shape {
  private :
    // === Variables ===
    /** @var _a
     * @brief Vector2f stocking the first point of the segment
     */
    Vector2f _a;

    /** @var _b
     * @brief Vector2f stocking the second point of the segment
     */
    Vector2f _b;

  public :
    // === Constructor & Destructor ===
    /**
     * @fn Segment(Vector2f a, Vector2f b, ShapeColor col)
     * @brief Constructor of the Segment class
     * @param a the first point of the segment (default=Vector2f(0,0))
     * @param b the second point of the segment (default=Vector2f(0,0))
     * @param col color of the segment (default=SHAPE_BLACK)
     */
    Segment(Vector2f a = Vector2f(), Vector2f b = Vector2f(), ShapeColor col = SHAPE_BLACK) : Shape(col), _a(a), _b(b) {}

    /**
     * @fn Segment(const Segment& s)
     * @brief Copy Constructor of the Segment class
     * @param s the segment to copy
     */
    Segment(const Segment& s) : Shape(s._color), _a(s._a), _b(s._b) {}

    /**
     * @fn virtual ~Segment()
     * @brief Destructor of the Segment class
     */
    virtual ~Segment() {}

    // === Getters & Setters ===
    /**
     * @fn Vector2f& getA()
     * @brief getter for the first point of the segment
     * @return Vector2f&
     */
    const Vector2f& getA() const { return _a; }

    /**
     * @fn Vector2f& getB()
     * @brief getter for the second point of the segment
     * @return Vector2f&
     */
    const Vector2f& getB() const { return _b; }

    // === Functions ===
    void translate(Vector2f v);
    void homothety(Vector2f v, double zoom);
    void rotate(Vector2f v, double radian);

    /**
     * @fn double getArea()
     * @brief getter of the area of the segment
     * @return double
     */
    double getArea() const;

    /**
     * @fn Shape* clone()
     * @brief clone the segment
     * @return Segment*
     */
    Shape* clone() const { return new Segment(*this); }

    /**
     * @fn void accept(VisitorShape *v)
     * @brief visit the segment
     * @param v the visitor of the segment
     */
    void accept(const VisitorShape *v) const;

    /**
     * @fn operator std::string()
     * @brief overload of the string cast operator
     * @return std::string
     */
    operator std::string() const {
      std::ostringstream os;
      os << "Segment :\n";
      os << "\t- " << _a << "\n";
      os << "\t- " << _b;
      return os.str();
    }

    /**
     * @fn std::string export_to_string()
     * @brief export the segment into a string
     * @return std::string
     */
    std::string export_to_string() const {
      std::ostringstream os;
      os << "SEGMENT;" << _color << ";";
      os << _a.export_to_string();
      os << _b.export_to_string();
      os << "END;";
      return os.str();
    }
};

#endif
