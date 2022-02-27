/**
 * @file Group.hpp
 * File containing methods to create a polygon shape
 */
#ifndef GROUP_HPP
#define GROUP_HPP

#include "Shape.hpp"
#include <vector>

class Group : public Shape {
  private :
    // === Variables ===
    /** @var _points
     * @brief array of Shape stocking the all the shapes of the group
     */
    std::vector<Shape*> _shapes;

  public :
    // === Constructor & Destructor ===
    /**
     * @fn Group(ShapeColor col)
     * @brief Constructor of the Group class (without initializing the array)
     * @param col color of the group (default=SHAPE_BLACK)
     */
    Group(ShapeColor col = SHAPE_BLACK) : Shape(col) {}

    /**
     * @fn Group(const std::vector<Shape*> shapes, ShapeColor col)
     * @brief Constructor of the Group class
     * @param shapes array of shapes of the group
     * @param col color of the group (default=SHAPE_BLACK)
     */
    Group(const std::vector<Shape*> shapes, ShapeColor col = SHAPE_BLACK) : Shape(col), _shapes(shapes) {}

    /**
     * @fn Group(const Group& p)
     * @brief Copy Constructor of the Group class
     * @param g the group to copy
     */
    Group(const Group& g) : Shape(g._color), _shapes(g._shapes) {}

    /**
     * @fn virtual ~Group()
     * @brief Destructor of the Group class
     */
    virtual ~Group() {}

    // === Getters & Setters ===
    /**
     * @fn void setShapes(const std::vector<Shape*> shapes)
     * @brief setter for the points of the polygon
     * @param shapes array of the shapes of the group
     */
    void setShapes(const std::vector<Shape*> shapes) { _shapes = shapes; }

    /**
     * @fn std::vector<Shape*> getShapes()
     * @brief getter for the shapes of the group
     * @return std::vector<Shape*> array of the shapes of the group
     */
    std::vector<Shape*> getShapes() const { return _shapes; }

    /**
     * @fn const Group& operator+=(const Shape &s)
     * @brief overload of the += operator of Group
     * @return Group& clone of this group
     */
    const Group& operator+=(const Shape &s) { _shapes.push_back(s.clone()); return *this; }

    /**
     * @fn Shape* operator[](int i) const
     * @brief get a specific vector of the shapes array
     * @param i the index
     * @return Shape* the shape at the index given
     */
    const Shape* operator[](int i) const {
      if(i < 0 || i >= (int)_shapes.size())
        throw Error("Group::operator[]::Invalid index");
      else
        return _shapes[i];
    }

    /**
     * @fn void addShape(Shape s)
     * @brief add a shape at the end of the array of shapes
     * @param s the shape to add in the array
     */
    void addShape(const Shape &s) { *this += s; }

    /**
     * @fn void removeShape(int i)
     * @brief remove a specific shape of the shapes array
     * @param i the index
     */
    void removeShape(int i) {
      if(i < 0 || i >= (int)_shapes.size())
        throw Error("Shape::removeShape::Invalid index");
      else
        _shapes.erase(_shapes.begin() + i);
    }

    // === Functions ===
    void translate(Vector2f v);
    void homothety(Vector2f v, double zoom);
    void rotate(Vector2f v, double radian);

    /**
     * @fn double getArea()
     * @brief getter of the area of the group
     * @return double
     */
    double getArea() const;

    /**
     * @fn Shape* clone()
     * @brief clone the group
     * @return Group*
     */
    Shape* clone() const { return new Group(*this); }

    /**
     * @fn void accept(VisitorShape *v)
     * @brief visit the group
     * @param v the visitor of the group
     */
    void accept(const VisitorShape *v) const;

    /**
     * @fn operator std::string()
     * @brief overload of the string cast operator
     * @return std::string
     */
    operator std::string() const {
      std::ostringstream os;
      os << "Group :";
      for(auto &shape : _shapes){
        os << "\n";
        os << "\t- " << *shape;
      }
      return os.str();
    }

    /**
     * @fn std::string export_to_string()
     * @brief export the group into a string
     * @return std::string
     */
    std::string export_to_string() const {
      std::ostringstream os;
      os << "GROUP;" << _color << ";";
      for(auto &shape : _shapes){
        os << shape->export_to_string();
      }
      os << "END;";
      return os.str();
    }
};

#endif
