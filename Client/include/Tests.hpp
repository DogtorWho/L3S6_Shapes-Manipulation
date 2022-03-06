/**
 * @file Tests.hpp
 * File containing methods for handling tests functions
 */
#ifndef TESTS_HPP
#define TESTS_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Error.hpp"

#include "Vector2f.hpp"
#include "Shape.hpp"
#include "Segment.hpp"
#include "Triangle.hpp"
#include "Circle.hpp"
#include "Polygon.hpp"
#include "Group.hpp"

#include "TCP.hpp"
#include "DrawServer.hpp"
#include "DrawRaylib.hpp"

#include "SavePlainText.hpp"
#include "ExpertPlainText.hpp"
#include "ExpertPlainTextSegment.hpp"
#include "ExpertPlainTextTriangle.hpp"
#include "ExpertPlainTextCircle.hpp"
#include "ExpertPlainTextPolygon.hpp"
#include "ExpertPlainTextGroup.hpp"

class Tests {
  private:
    std::vector<Shape*> _shapes;
    ExpertPlainText* _expertPlainText;

  public:
    Tests(){
      _expertPlainText = new ExpertPlainTextPolygon(NULL);
      _expertPlainText = new ExpertPlainTextCircle(_expertPlainText);
      _expertPlainText = new ExpertPlainTextTriangle(_expertPlainText);
      _expertPlainText = new ExpertPlainTextSegment(_expertPlainText);
      _expertPlainText = new ExpertPlainTextGroup(_expertPlainText);
    }

    virtual ~Tests(){}

    std::vector<Shape*> getShapes() const { return _shapes; }

    void addShape(Shape* shape){
      _shapes.push_back(shape);
    }

    void addSavedPlainTextShape(std::string filename) {
      Shape* shape = _expertPlainText->resolve(filename);
      if (shape == NULL)
        throw Error("Tests::addSavedPlainTextShape::couldn't resolve the filename");
      else
      _shapes.push_back(shape);
    }

    void printShapes() const {
      std::cout << "\n === Shapes Content ===\n";
      for(auto &shape : _shapes)
        std::cout << *shape << '\n';
    }

    void printExportedShapes() const {
      std::cout << "\n === Export ===\n";
      for(auto &shape : _shapes)
        std::cout << shape->export_to_string() << "\n";
    }

    void printShapesArea() const {
      std::cout << "\n === Area ===\n";
      for(auto &shape : _shapes)
        std::cout << "Shape Area = " << shape->getArea() << "\n";
    }

    void drawShapesRaylib() const {
      InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Drawing with raylib");
      SetTargetFPS(60);

      DrawRaylib draw_raylib;

      while (!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for(auto &shape : _shapes)
          shape->accept(&draw_raylib);

        EndDrawing();
      }
      CloseWindow();
    }

    void drawShapesServer() const {
      TCP::getInstance()->create_socket();
      TCP::getInstance()->connect_to_server();

      DrawServer draw_server;

      for(auto &shape : _shapes)
        shape->accept(&draw_server);

      TCP::getInstance()->disconnect_from_server();
    }

    void saveShapesPlainText() const {
      SavePlainText save_text;
      save_text.remove_saves();

      for(auto &shape : _shapes)
        shape->accept(&save_text);
    }

    void translateShapes(Vector2f trans){
      for(auto &shape : _shapes)
        shape->translate(trans);
    }

    void homothetyShapes(Vector2f homo, double zoom){
      for(auto &shape : _shapes)
        shape->homothety(homo, zoom);
    }

    void rotateShapes(Vector2f rota, double rad){
      for(auto &shape : _shapes)
        shape->rotate(rota, rad);
    }
};

#endif
