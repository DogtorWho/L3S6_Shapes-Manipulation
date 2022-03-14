#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>

#include "Vector2f.hpp"
#include "Shape.hpp"

Vector2f getP1(std::vector<Shape*> shapes) {
  Vector2f p1 = shapes[0]->getMin();

  for(auto &shape : shapes){
    if(shape->getMin().getPosX() < p1.getPosX())
      p1.setPosX(shape->getMin().getPosX());
    if(shape->getMin().getPosY() < p1.getPosY())
      p1.setPosY(shape->getMin().getPosY());
  }

  return p1;
}

Vector2f getP2(std::vector<Shape*> shapes) {
  Vector2f p2 = shapes[0]->getMax();

  for(auto &shape : shapes){
    if(shape->getMax().getPosX() > p2.getPosX())
      p2.setPosX(shape->getMax().getPosX());
    if(shape->getMax().getPosY() > p2.getPosY())
      p2.setPosY(shape->getMax().getPosY());
  }

  return p2;
}

#endif
