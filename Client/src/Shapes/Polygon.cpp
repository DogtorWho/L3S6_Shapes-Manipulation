#include "Polygon.hpp"
#include "VisitorShape.hpp"

#include <cmath>

// === Functions ===

void Polygon::translate(Vector2f v){
  for(auto &point : _points){
    *point += v;
  }
}

void Polygon::homothety(Vector2f v, double zoom){
  if(zoom == 0.f)
    throw Error("Polygon::homothety::zoom can't be 0");

  for(auto &point : _points){
    point->setPosX((zoom * (point->getPosX() - v.getPosX())) + v.getPosX());
    point->setPosY((zoom * (point->getPosY() - v.getPosY())) + v.getPosY());
  }
}

void Polygon::rotate(Vector2f v, double radian){
  for(auto &point : _points){
    point->setPosX(cos(radian) * (point->getPosX() - v.getPosX()) - sin(radian) * (point->getPosY() - v.getPosY()) + v.getPosX());
    point->setPosY(sin(radian) * (point->getPosX() - v.getPosX()) + cos(radian) * (point->getPosY() - v.getPosY()) + v.getPosY());
  }
}

Vector2f* Polygon::getCentroid() const {
  Vector2f centroid;
  int n = _points.size();
  double signedArea = 0;

  for (int i = 0; i < n; i++) {
    Vector2f v1(*_points[i]);
    Vector2f v2(*_points[(i+1) % n]);

    double A = (v1^v2);
    signedArea += A;

    centroid += ((v1+v2) * A);
  }

  signedArea *= 0.5;
  centroid *= (1 / (6 * signedArea));

  return centroid.clone();
}

double Polygon::getArea() const {
  double area = 0;
  Vector2f *centroid = getCentroid();

  for(int i = 0; i < (int)_points.size(); i++) {
    Triangle tri;
    if(i == (int)_points.size()-1)
      tri = Triangle(*centroid, *_points[i], *_points[0]);
    else
      tri = Triangle(*centroid, *_points[i], *_points[i+1]);

    area += tri.getArea();
  }

  return area;
}

void Polygon::accept(VisitorShape *v) const {
  v->visit(this);
}
