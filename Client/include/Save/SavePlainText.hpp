/**
 * @file SavePlainText.hpp
 * File containing methods to visit shapes to save them in a plain text format
 */
#ifndef SAVETEXT_HPP
#define SAVETEXT_HPP

#include "Save.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>

class SavePlainText : public Save {
  private :
    int cpt_seg, cpt_tri, cpt_cir, cpt_pol, cpt_grp;

  public :
    /**
     * @fn SavePlainText()
     * @brief Constructor of the SavePlainText class
     * @param filename the name of the file to save in
     */
    SavePlainText(std::string filepath = "build/objects/save/plainText/") : Save(filepath) {
      cpt_seg = 0;
      cpt_tri = 0;
      cpt_cir = 0;
      cpt_pol = 0;
      cpt_grp = 0;
    }

    /**
     * @fn virtual ~SavePlainText()
     * @brief Destructor of the SavePlainText class
     */
    virtual ~SavePlainText(){}

    /**
     * @fn void visit(const Segment *s)
     * @brief visit a segment
     * @param s the segment to save in a plain text format
     */
    void visit(const Segment *s) {
      std::string filename = "segment_" + std::to_string(cpt_seg);
      save_in_file(s, filename);
      cpt_seg++;
    }

    /**
     * @fn void visit(const Triangle *t)
     * @brief visit a triangle
     * @param t the triangle to save in a plain text format
     */
    void visit(const Triangle *t) {
      std::string filename = "triangle_" + std::to_string(cpt_tri);
      save_in_file(t, filename);
      cpt_tri++;
    }

    /**
     * @fn void visit(const Circle *c)
     * @brief visit a circle
     * @param c the circle to save in a plain text format
     */
    void visit(const Circle *c) {
      std::string filename = "circle_" + std::to_string(cpt_cir);
      save_in_file(c, filename);
      cpt_cir++;
    }

    /**
     * @fn void visit(const Polygon *p)
     * @brief visit a polygon
     * @param p the polygon to save in a plain text format
     */
    void visit(const Polygon *p) {
      std::string filename = "polygon_" + std::to_string(cpt_pol);
      save_in_file(p, filename);
      cpt_pol++;
    }

    /**
     * @fn void visit(const Group *g)
     * @brief visit a group
     * @param g the group to save in a plain text format
     */
    virtual void visit(const Group *g) {
      _filepath += "/group_" + std::to_string(cpt_grp) + "/";
      std::string cmd = "mkdir " + _filepath;
      system(cmd.c_str());

      std::ofstream o;
      std::string fd = _filepath + "color";
      o.open(fd, std::ofstream::app);
      o << std::to_string(g->getColor());
      o.close();

      cpt_grp++;
      for(auto &shape : g->getShapes()){
        shape->accept(this);
      }

      _filepath = "build/objects/save/plainText/"; //reset the path
    }

    void save_in_file(const Shape *shape, std::string filename) const {
      std::ofstream o;
      std::string fd = _filepath + filename;
      o.open(fd, std::ofstream::app);
      o << shape->export_to_string() + "\n";
      o.close();
    }

    void remove_saves() const {
      //std::filesystem::remove_all(_filepath);
      std::string cmd = "rm -rf " + _filepath + "*";
      if(system(cmd.c_str()) < 0)
        throw Error("SavePlainText::remove_saves::system command failed");      
    }
};

#endif
