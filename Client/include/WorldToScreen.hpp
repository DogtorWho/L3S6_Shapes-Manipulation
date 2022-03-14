#ifndef WORLDTOSCREEN_HPP
#define WORLDTOSCREEN_HPP

#include <algorithm>

#include "Segment.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Polygon.hpp"

class WorldToScreen {
  private :
    double a, b;
    double l1, l2;
    int e1, e2;
    Vector2f C, Cp;

  public :

    WorldToScreen(Vector2f p1, Vector2f p2, Vector2f pp1, Vector2f pp2){
      double cmp1 = abs(pp2.getPosX() - pp1.getPosX()) / abs(p2.getPosX() - p1.getPosX());
      double cmp2 = abs(pp2.getPosY() - pp1.getPosY()) / abs(p2.getPosY() - p1.getPosY());
      double lambda = std::min(cmp1, cmp2);

      if( ((pp2.getPosX() - pp1.getPosX() < 0) && (p2.getPosX() - p1.getPosX() < 0)) || ((pp2.getPosX() - pp1.getPosX() > 0) && (p2.getPosX() - p1.getPosX() > 0)) )
        e1 = 1;
      else
        e1 = -1;

      if( ((pp2.getPosY() - pp1.getPosY() < 0) && (p2.getPosY() - p1.getPosY() < 0)) || ((pp2.getPosY() - pp1.getPosY() > 0) && (p2.getPosY() - p1.getPosY() > 0)) )
        e2 = 1;
      else
        e2 = -1;

      l1 = e1 * lambda;
      l2 = e2 * lambda;

      C.setPosX( (p2.getPosX() + p1.getPosX()) / 2.f );
      C.setPosY( (p2.getPosY() + p1.getPosY()) / 2.f );

      Cp.setPosX( (pp2.getPosX() + pp1.getPosX()) / 2.f );
      Cp.setPosY( (pp2.getPosY() + pp1.getPosY()) / 2.f );

      a = Cp.getPosX() - (l1 * C.getPosX());
      b = Cp.getPosY() - (l1 * C.getPosY());
    }

    virtual ~WorldToScreen(){}


    void visit(Segment *s) {
      s->setA(affineTransform(s->getA()));
      s->setB(affineTransform(s->getB()));
    }

    void visit(Triangle *t) {
      t->setA(affineTransform(t->getA()));
      t->setB(affineTransform(t->getB()));
      t->setC(affineTransform(t->getC()));
    }

    void visit(Circle *c) {
      Vector2f test = Vector2f(c->getCenter().getPosX() + c->getRadius(), c->getCenter().getPosY());
      test = affineTransform(test);

      c->setCenter(affineTransform(c->getCenter()));
      c->setRadius(test.getPosX() - c->getCenter().getPosX());
    }

    void visit(Polygon *p) {
      for(auto &point : p->getPoints())
        point->setVector2f(affineTransform(*point));
    }

    virtual void visit(Group *g) {
      for(auto &shape : g->getShapes()){
        shape->accept(this);
      }
    }

    Vector2f affineTransform(Vector2f v) const {
      return Vector2f(l1*v.getPosX() + a, l2*v.getPosY() + b);
    }

};

#endif
