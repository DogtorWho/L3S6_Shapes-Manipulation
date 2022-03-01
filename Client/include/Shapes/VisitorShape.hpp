/**
 * @file VisitorShape.hpp
 * File containing the base for all the visitors of shapes
 */
#ifndef VISITORSHAPE_HPP
#define VISITORSHAPE_HPP

#include "Segment.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Polygon.hpp"
#include "Group.hpp"

class VisitorShape {
  public :
    /**
     * @fn void visit(const Segment *s)
     * @brief visit a segment
     * @param s the segment to visit
     */
    virtual void visit(const Segment *s) = 0;

    /**
     * @fn void visit(const Triangle *t)
     * @brief visit a triangle
     * @param t the triangle to visit
     */
    virtual void visit(const Triangle *t) = 0;

    /**
     * @fn void visit(const Circle *c)
     * @brief visit a circle
     * @param c the circle to visit
     */
    virtual void visit(const Circle *c) = 0;

    /**
     * @fn void visit(const Polygon *p)
     * @brief visit a polygon
     * @param p the polygon to visit
     */
    virtual void visit(const Polygon *p) = 0;

    /**
     * @fn void visit(const Group *g)
     * @brief visit a group
     * @param g the group to visit
     */
    virtual void visit(const Group *g) = 0;
};

#endif
