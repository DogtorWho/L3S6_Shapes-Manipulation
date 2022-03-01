#include "Segment.hpp"
#include "VisitorShape.hpp"

#include <cmath>

// === Functions ===

void Segment::translate(Vector2f v){
  _a += v;
  _b += v;
}

void Segment::homothety(Vector2f v, double zoom){
  _a.setPosX((zoom * (_a.getPosX() - v.getPosX())) + v.getPosX());
  _a.setPosY((zoom * (_a.getPosY() - v.getPosY())) + v.getPosY());

  _b.setPosX((zoom * (_b.getPosX() - v.getPosX())) + v.getPosX());
  _b.setPosY((zoom * (_b.getPosY() - v.getPosY())) + v.getPosY());
}

void Segment::rotate(Vector2f v, double radian){
  _a.setPosX(cos(radian) * (_a.getPosX() - v.getPosX()) - sin(radian) * (_a.getPosY() - v.getPosY()) + v.getPosX());
  _a.setPosY(sin(radian) * (_a.getPosX() - v.getPosX()) + cos(radian) * (_a.getPosY() - v.getPosY()) + v.getPosY());

  _b.setPosX(cos(radian) * (_b.getPosX() - v.getPosX()) - sin(radian) * (_b.getPosY() - v.getPosY()) + v.getPosX());
  _b.setPosY(sin(radian) * (_b.getPosX() - v.getPosX()) + cos(radian) * (_b.getPosY() - v.getPosY()) + v.getPosY());
}

double Segment::getArea() const {
  return 0.f;
}

void Segment::accept(VisitorShape *v) const {
  v->visit(this);
}
