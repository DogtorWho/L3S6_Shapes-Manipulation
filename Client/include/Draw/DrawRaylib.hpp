/**
 * @file DrawRaylib.hpp
 * File containing methods to visit shapes to draw them with raylib
 */
#ifndef DRAWRAYLIB_HPP
#define DRAWRAYLIB_HPP

#include <string>
#include <map>

#include "Draw.hpp"
#include "raylib.h"

#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320

class DrawRaylib : public Draw {
  private :
    std::vector<Color> _colors;

  public :
    /**
     * @fn DrawRaylib()
     * @brief Constructor of the DrawRaylib class
     */
    DrawRaylib(){
      _colors.push_back(BLACK);
      _colors.push_back(BLUE);
      _colors.push_back(RED);
      _colors.push_back(GREEN);
      _colors.push_back(YELLOW);
      _colors.push_back(SKYBLUE);
    }

    /**
     * @fn virtual ~DrawRaylib()
     * @brief Destructor of the DrawRaylib class
     */
    virtual ~DrawRaylib(){}

    /**
     * @fn void visit(const Segment *s)
     * @brief visit a segment
     * @param s the segment to draw with raylib
     */
    void visit(const Segment *s) {
      Vector2 v1 = {(float)s->getA().getPosX(), (float)s->getA().getPosY()};
      Vector2 v2 = {(float)s->getB().getPosX(), (float)s->getB().getPosY()};
      DrawLineV(v1, v2, _colors[s->getColor()]);
    }

    /**
     * @fn void visit(const Triangle *t)
     * @brief visit a triangle
     * @param t the triangle to draw with raylib
     */
    void visit(const Triangle *t) {
      Vector2 v1 = {(float)t->getA().getPosX(), (float)t->getA().getPosY()};
      Vector2 v2 = {(float)t->getB().getPosX(), (float)t->getB().getPosY()};
      Vector2 v3 = {(float)t->getC().getPosX(), (float)t->getC().getPosY()};
      DrawTriangle(v1, v2, v3, _colors[t->getColor()]);
    }

    /**
     * @fn void visit(const Circle *c)
     * @brief visit a circle
     * @param c the circle to draw with raylib
     */
    void visit(const Circle *c) {
      DrawCircle(c->getCenter().getPosX(), c->getCenter().getPosY(), c->getRadius(), _colors[c->getColor()]);
    }

    /**
     * @fn void visit(const Polygon *p)
     * @brief visit a polygon
     * @param p the polygon to draw with raylib
     */
    void visit(const Polygon *p) {
      Vector2 center = {(float)p->getCentroid()->getPosX(), (float)p->getCentroid()->getPosY()};
      DrawPoly(center, p->getPoints().size(), 100, 0, _colors[p->getColor()]);
    }

    /**
     * @fn void visit(const Group *g)
     * @brief visit a group
     * @param g the group to draw with raylib
     */
    void visit(const Group *g) {
      for(auto &shape : g->getShapes()){
        shape->setColor(g->getColor());
        shape->accept(this);
      }
    }
};

#endif
