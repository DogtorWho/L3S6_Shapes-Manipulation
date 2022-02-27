#include "Group.hpp"
#include "VisitorShape.hpp"

#include <cmath>

// === Functions ===

void Group::translate(Vector2f v){
  for(auto &shape : _shapes){
    shape->translate(v);
  }
}

void Group::homothety(Vector2f v, double zoom){
  for(auto &shape : _shapes){
    shape->homothety(v, zoom);
  }
}

void Group::rotate(Vector2f v, double radian){
  for(auto &shape : _shapes){
    shape->rotate(v, radian);
  }
}

double Group::getArea() const {
  double area = 0;
  for(auto &shape : _shapes){
    area += shape->getArea();
  }
  return area;
}

void Group::accept(const VisitorShape *v) const {
  v->visit(this);
}
