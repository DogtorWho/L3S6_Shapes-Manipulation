/**
 * @file DrawServer.hpp
 * File containing methods to visit shapes to draw them on a server
 */
#ifndef DRAWSERVER_HPP
#define DRAWSERVER_HPP

#include <string>

#include "Draw.hpp"
#include "TCP.hpp"

class DrawServer : public Draw {
  public :
    /**
     * @fn DrawServer()
     * @brief Constructor of the DrawServer class
     */
    DrawServer(){}

    /**
     * @fn virtual ~DrawServer()
     * @brief Destructor of the DrawServer class
     */
    virtual ~DrawServer(){}

    /**
     * @fn void visit(const Segment *s)
     * @brief visit a segment
     * @param s the segment to draw in the server
     */
    void visit(const Segment *s) {
      std::string msg = s->export_to_string() + "\n";
      TCP::getInstance()->send_to_server(msg);
    }

    /**
     * @fn void visit(const Triangle *t)
     * @brief visit a triangle
     * @param t the triangle to draw in the server
     */
    void visit(const Triangle *t) {
      std::string msg = t->export_to_string() + "\n";
      TCP::getInstance()->send_to_server(msg);
    }

    /**
     * @fn void visit(const Circle *c)
     * @brief visit a circle
     * @param c the circle to draw int the server
     */
    void visit(const Circle *c) {
      std::string msg = c->export_to_string() + "\n";
      TCP::getInstance()->send_to_server(msg);
    }

    /**
     * @fn void visit(const Polygon *p)
     * @brief visit a polygon
     * @param p the polygon to draw in the server
     */
    void visit(const Polygon *p) {
      std::string msg = p->export_to_string() + "\n";
      TCP::getInstance()->send_to_server(msg);
    }

    /**
     * @fn void visit(const Group *g)
     * @brief visit a group
     * @param g the group to draw in the server
     */
    void visit(const Group *g) {
      for(auto &shape : g->getShapes()){
        shape->setColor(g->getColor());
        shape->accept(this);
      }
    }
};

#endif
