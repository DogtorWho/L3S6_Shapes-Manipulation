#include "Triangle.hpp"
#include "VisitorShape.hpp"

#include <cmath>

// === Functions ===

void Triangle::translate(Vector2f v){
  _a += v;
  _b += v;
  _c += v;
}

void Triangle::homothety(Vector2f v, double zoom){
  _a.setPosX((zoom * (_a.getPosX() - v.getPosX())) + v.getPosX());
  _a.setPosY((zoom * (_a.getPosY() - v.getPosY())) + v.getPosY());

  _b.setPosX((zoom * (_b.getPosX() - v.getPosX())) + v.getPosX());
  _b.setPosY((zoom * (_b.getPosY() - v.getPosY())) + v.getPosY());

  _c.setPosX((zoom * (_c.getPosX() - v.getPosX())) + v.getPosX());
  _c.setPosY((zoom * (_c.getPosY() - v.getPosY())) + v.getPosY());
}

void Triangle::rotate(Vector2f v, double radian){
  _a.setPosX(cos(radian) * (_a.getPosX() - v.getPosX()) - sin(radian) * (_a.getPosY() - v.getPosY()) + v.getPosX());
  _a.setPosY(sin(radian) * (_a.getPosX() - v.getPosX()) + cos(radian) * (_a.getPosY() - v.getPosY()) + v.getPosY());

  _b.setPosX(cos(radian) * (_b.getPosX() - v.getPosX()) - sin(radian) * (_b.getPosY() - v.getPosY()) + v.getPosX());
  _b.setPosY(sin(radian) * (_b.getPosX() - v.getPosX()) + cos(radian) * (_b.getPosY() - v.getPosY()) + v.getPosY());

  _c.setPosX(cos(radian) * (_c.getPosX() - v.getPosX()) - sin(radian) * (_c.getPosY() - v.getPosY()) + v.getPosX());
  _c.setPosY(sin(radian) * (_c.getPosX() - v.getPosX()) + cos(radian) * (_c.getPosY() - v.getPosY()) + v.getPosY());
}

// area = 1/2(x1(y2-y3) + x2(y3-y1) + x3(y1-y2))
double Triangle::getArea() const {
  return abs( ( ( _a.getPosX() * (_b.getPosY() - _c.getPosY()) )
          + ( _b.getPosX() * (_c.getPosY() - _a.getPosY()) )
          + ( _c.getPosX() * (_a.getPosY() - _b.getPosY()) ) )
          / 2.f );

  // other possiblity : (not as fast)
  /*Vector2f AB(_b-_a);
  Vector2f AC(_c-_a);
  return abs( (AB^AC) / 2.f );*/
}

void Triangle::accept(VisitorShape *v) const {
  v->visit(this);
}
