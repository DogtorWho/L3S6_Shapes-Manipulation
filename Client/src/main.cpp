#include <iostream>

#include "Error.hpp"
#include "Tests.hpp"

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

int main() {
  try {
    Tests *tests = new Tests();

    /*Vector2f v1_s(20.f, 80.f);
    Vector2f v2_s(60.f, 120.f);
    tests->addShape(new Segment(v1_s, v2_s, SHAPE_BLUE));

    Vector2f v1_t(150.f, 15.f);
    Vector2f v2_t(180.f, 70.f);
    Vector2f v3_t(250.f, 25.f);
    tests->addShape(new Triangle(v1_t, v2_t, v3_t, SHAPE_RED));

    Vector2f v1_c(100.f, 220.f);
    tests->addShape(new Circle(v1_c, 30, SHAPE_CYAN));

    std::vector<Vector2f*> points;
    points.push_back(new Vector2f(300.f, 150.f));
    points.push_back(new Vector2f(400.f, 150.f));
    points.push_back(new Vector2f(420.f, 200.f));
    points.push_back(new Vector2f(380.f, 240.f));
    points.push_back(new Vector2f(320.f, 250.f));
    points.push_back(new Vector2f(280.f, 190.f));
    tests->addShape(new Polygon(points, SHAPE_GREEN));

    Vector2f v1_shp(10.f, 90.f);
    Vector2f v2_shp(50.f, 300.f);
    Segment shp1(v1_shp, v2_shp, SHAPE_GREEN);
    Vector2f v3_shp(420.f, 200.f);
    Vector2f v4_shp(380.f, 240.f);
    Segment shp2(v3_shp, v4_shp, SHAPE_YELLOW);
    std::vector<Shape*> shps = {&shp1, &shp2};
    Group grp(shps, SHAPE_BLUE);
    tests->addShape(&grp);

    Vector2f v1_shp(10.f, 90.f);
    Vector2f v2_shp(50.f, 300.f);
    Segment shp1(v1_shp, v2_shp, SHAPE_GREEN);
    std::vector<Shape*> shps = {&shp1};
    Group grp(shps, SHAPE_RED);
    Vector2f v3_shp(420.f, 200.f);
    Vector2f v4_shp(380.f, 240.f);
    Segment shp2(v3_shp, v4_shp, SHAPE_YELLOW);
    std::vector<Shape*> shapes = {&shp2, &grp};
    Group group(shapes, SHAPE_BLUE);
    tests->addShape(&group);*/

    tests->addSavedPlainTextShape("build/objects/save/plainText/segment_0");
    tests->addSavedPlainTextShape("build/objects/save/plainText/triangle_0");
    tests->addSavedPlainTextShape("build/objects/save/plainText/circle_0");
    tests->addSavedPlainTextShape("build/objects/save/plainText/polygon_0");
    tests->addSavedPlainTextShape("build/objects/save/plainText/group_0/");

    Vector2f vect(50, 50);
    tests->translateShapes(vect);
    //tests->homothetyShapes(vect, 1.5f);
    //tests->rotateShapes(vect, 1.5f);

    tests->printExportedShapes();
    tests->printShapes();
    tests->printShapesArea();

    //tests->drawShapesRaylib();
    tests->drawShapesServer();

    //tests->saveShapesPlainText();

  }
  catch(Error &e) {
    std::cout << "ERROR : " << e << "\n";
  }

  return 0;
}
