/**
 * @file Draw.hpp
 * File containing the base for all the drawing options of shapes
 */
#ifndef DRAW_HPP
#define DRAW_HPP

#include "VisitorShape.hpp"
#include "Segment.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Polygon.hpp"

class Draw : public VisitorShape {
  public :
    /**
     * @fn void visit(const Segment *s)
     * @brief visit a segment
     * @param s the segment to draw
     */
    virtual void visit(const Segment *s) = 0;

    /**
     * @fn void visit(const Triangle *t)
     * @brief visit a triangle
     * @param t the triangle to draw
     */
    virtual void visit(const Triangle *t) = 0;

    /**
     * @fn void visit(const Circle *c)
     * @brief visit a circle
     * @param c the circle to draw
     */
    virtual void visit(const Circle *c) = 0;

    /**
     * @fn void visit(const Polygon *p)
     * @brief visit a polygon
     * @param p the polygon to draw
     */
    virtual void visit(const Polygon *p) = 0;

    /**
     * @fn void visit(const Group *g)
     * @brief visit a group
     * @param g the group to draw
     */
    virtual void visit(const Group *g) = 0;
};

#endif
