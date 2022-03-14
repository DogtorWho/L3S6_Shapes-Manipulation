/**
 * @file Polygon.hpp
 * File containing methods to create a polygon shape
 */
#ifndef POLYGON_HPP
#define POLYGON_HPP

#include "Shape.hpp"
#include <vector>

class Polygon : public Shape {
  private :
    // === Variables ===
    /** @var _points
     * @brief array of Vector2f stocking the all the point of the polygon
     */
    std::vector<Vector2f*> _points;

  public :
    // === Constructor & Destructor ===
    /**
     * @fn Polygon(ShapeColor col)
     * @brief Constructor of the Polygon class (without initializing the array)
     * @param col color of the polygon (default=SHAPE_BLACK)
     */
    Polygon(ShapeColor col = SHAPE_BLACK) : Shape(col) {}

    /**
     * @fn Polygon(const std::vector<Vector2f*> pts, ShapeColor col)
     * @brief Constructor of the Polygon class
     * @param pts array of points of the polygon
     * @param col color of the polygon (default=SHAPE_BLACK)
     */
    Polygon(const std::vector<Vector2f*> pts, ShapeColor col = SHAPE_BLACK) : Shape(col), _points(pts) {}

    /**
     * @fn Polygon(const Polygon& p)
     * @brief Copy Constructor of the Polygon class
     * @param p the polygon to copy
     */
    Polygon(const Polygon& p) : Shape(p._color), _points(p._points) {}

    /**
     * @fn virtual ~Polygon()
     * @brief Destructor of the Polygon class
     */
    virtual ~Polygon() {}

    // === Getters & Setters ===
    /**
     * @fn void setPoints(const std::vector<Vector2f*> pts)
     * @brief setter for the points of the polygon
     * @param pts array of the points of the polygon
     */
    void setPoints(const std::vector<Vector2f*> pts) { _points = pts; }

    /**
     * @fn std::vector<Vector2f*> getPoints()
     * @brief getter for the points of the polygon
     * @return std::vector<Vector2f*> array of the points of the polygon
     */
    std::vector<Vector2f*> getPoints() const { return _points; }

    Vector2f* getCentroid() const;

    /**
     * @fn const Polygon& operator+=(const Vector2f &v)
     * @brief overload of the += operator of Polygon
     * @return Polygon& clone of this polygon
     */
    const Polygon& operator+=(const Vector2f &v) { _points.push_back(v.clone()); return *this; }

    /**
     * @fn Vector2f* operator[](int i) const
     * @brief get a specific vector of the points array
     * @param i the index
     * @return Vector2f* the point at the index given
     */
    Vector2f* operator[](int i) const {
      if(i < 0 || i >= (int)_points.size())
        throw Error("Polygon::operator[]::Invalid index");
      else
        return _points[i];
    }

    /**
     * @fn void addVector2f(Vector2f v)
     * @brief add a point at the end of the array of points
     * @param v the vector the add in the array
     */
    void addVector2f(Vector2f v) { *this += v; }

    /**
     * @fn void removeVector2f(int i)
     * @brief remove a specific vector of the points array
     * @param i the index
     */
    void removeVector2f(int i) {
      if(i < 0 || i >= (int)_points.size())
        throw Error("Polygon::removeVector2f::Invalid index");
      else
        _points.erase(_points.begin() + i);
    }

    Vector2f getMin() const {
      Vector2f mini = *_points[0];

      for(auto &point : _points){
        if(point->getPosX() < mini.getPosX())
          mini.setPosX(point->getPosX());
        if(point->getPosY() < mini.getPosY())
          mini.setPosY(point->getPosY());
      }

      return mini;
    }

    Vector2f getMax() const {
      Vector2f maxi = *_points[0];

      for(auto &point : _points){
        if(point->getPosX() > maxi.getPosX())
          maxi.setPosX(point->getPosX());
        if(point->getPosY() > maxi.getPosY())
          maxi.setPosY(point->getPosY());
      }

      return maxi;
    }

    // === Functions ===
    void translate(Vector2f v);
    void homothety(Vector2f v, double zoom);
    void rotate(Vector2f v, double radian);

    /**
     * @fn double getArea()
     * @brief getter of the area of the polygon
     * @return double
     */
    double getArea() const;

    /**
     * @fn Shape* clone()
     * @brief clone the polygon
     * @return Polygon*
     */
    Shape* clone() const { return new Polygon(*this); }

    /**
     * @fn void accept(VisitorShape *v)
     * @brief visit the polygon
     * @param v the visitor of the polygon
     */
    void accept(VisitorShape *v) const;

    void accept(WorldToScreen *v);

    /**
     * @fn operator std::string()
     * @brief overload of the string cast operator
     * @return std::string
     */
    operator std::string() const {
      std::ostringstream os;
      os << "Polygon :";
      for(auto &point : _points){
        os << "\n";
        os << "\t- " << *point;
      }
      return os.str();
    }

    /**
     * @fn std::string export_to_string()
     * @brief export the polygon into a string
     * @return std::string
     */
    std::string export_to_string() const {
      std::ostringstream os;
      os << "POLYGON;" << _color << ";";
      for(auto &point : _points){
        os << point->export_to_string();
      }
      os << "END;";
      return os.str();
    }
};

#endif
