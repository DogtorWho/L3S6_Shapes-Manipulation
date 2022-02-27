/**
 * @file Save.hpp
 * File containing the base for all the saving options of shapes
 */
#ifndef SAVE_HPP
#define SAVE_HPP

#include "VisitorShape.hpp"
#include "Segment.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Polygon.hpp"

#include <string>

class Save : public VisitorShape {
  protected :
    std::string _filepath;

  public :
    /**
     * @fn Save()
     * @brief Constructor of the Save class
     * @param filename the name of the file to save in
     */
    Save(std::string filepath = "build/objects/save/") : _filepath(filepath) {}

    /**
     * @fn virtual ~Save()
     * @brief Destructor of the Save class
     */
    virtual ~Save(){}

    /**
     * @fn void visit(const Segment *s)
     * @brief visit a segment
     * @param s the segment to save
     */
    virtual void visit(const Segment *s) const = 0;

    /**
     * @fn void visit(const Triangle *t)
     * @brief visit a triangle
     * @param t the triangle to save
     */
    virtual void visit(const Triangle *t) const = 0;

    /**
     * @fn void visit(const Circle *c)
     * @brief visit a circle
     * @param c the circle to save
     */
    virtual void visit(const Circle *c) const = 0;

    /**
     * @fn void visit(const Polygon *p)
     * @brief visit a polygon
     * @param p the polygon to save
     */
    virtual void visit(const Polygon *p) const = 0;

    /**
     * @fn void visit(const Group *g)
     * @brief visit a group
     * @param g the group to save
     */
    virtual void visit(const Group *g) const = 0;
};

#endif
