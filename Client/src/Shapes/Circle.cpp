#include "Circle.hpp"
#include "VisitorShape.hpp"

#include <cmath>

// === Functions ===

void Circle::translate(Vector2f v){
  _center += v;
}

void Circle::homothety(Vector2f v, double zoom){
  if(zoom == 0.f)
    throw Error("Circle::homothety::zoom can't be 0");

  _center.setPosX((zoom * (_center.getPosX() - v.getPosX())) + v.getPosX());
  _center.setPosY((zoom * (_center.getPosY() - v.getPosY())) + v.getPosY());

  _radius *= zoom;
}

void Circle::rotate(Vector2f v, double radian){
  _center.setPosX(cos(radian) * (_center.getPosX() - v.getPosX()) - sin(radian) * (_center.getPosY() - v.getPosY()) + v.getPosX());
  _center.setPosY(sin(radian) * (_center.getPosX() - v.getPosX()) + cos(radian) * (_center.getPosY() - v.getPosY()) + v.getPosY());
}

double Circle::getArea() const {
  return ( M_PI * (_radius * _radius) );
}

void Circle::accept(VisitorShape *v) const {
  v->visit(this);
}
