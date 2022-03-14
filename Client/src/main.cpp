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

#include "WorldToScreen.hpp"
#include "utils.hpp"

int main() {
  try {
    //Tests *tests = new Tests();

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

    /*tests->addSavedPlainTextShape("build/objects/save/plainText/segment_0");
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

    tests->drawShapesRaylib();
    //tests->drawShapesServer();

    //tests->saveShapesPlainText();*/

    std::vector<Vector2f*> points;
    points.push_back(new Vector2f(1.f, -1.f));
    points.push_back(new Vector2f(5.f, -1.f));
    points.push_back(new Vector2f(5.f, 1.f));
    points.push_back(new Vector2f(1.f, 1.f));
    Polygon *R1 = new Polygon(points, SHAPE_BLUE);

    Vector2f v1_t(6.f, -1.f);
    Vector2f v2_t(8.f, 0.f);
    Vector2f v3_t(6.f, 1.f);
    Triangle *T1 = new Triangle(v1_t, v2_t, v3_t, SHAPE_GREEN);

    Vector2f v1_c(11.f, 0.f);
    Circle *C1 = new Circle(v1_c, 2, SHAPE_YELLOW);

    std::vector<Shape*> shapes = {R1, T1, C1};
    Group *G1 = new Group(shapes, SHAPE_RED);


    Vector2f trans(-1.f, 0.f);
    G1->translate(trans);

    Vector2f pp1(0, SCREEN_HEIGHT);
    Vector2f pp2(SCREEN_WIDTH, 0);
    WorldToScreen wtos(getP1(shapes), getP2(shapes), pp1, pp2);
    G1->accept(&wtos);


    TCP::getInstance()->create_socket();
    TCP::getInstance()->connect_to_server();

    DrawServer draw_server;
    G1->accept(&draw_server);

    TCP::getInstance()->disconnect_from_server();

    /*SavePlainText save_text;
    save_text.remove_saves();
    G1->accept(&save_text);

    ExpertPlainText* _expertPlainText;
    _expertPlainText = new ExpertPlainTextPolygon(NULL);
    _expertPlainText = new ExpertPlainTextCircle(_expertPlainText);
    _expertPlainText = new ExpertPlainTextTriangle(_expertPlainText);
    _expertPlainText = new ExpertPlainTextSegment(_expertPlainText);
    _expertPlainText = new ExpertPlainTextGroup(_expertPlainText);

    Group *G2 = (Group*)_expertPlainText->resolve("build/objects/save/plainText/group_0/");
    G2->translate(trans);

    TCP::getInstance()->create_socket();
    TCP::getInstance()->connect_to_server();

    G2->accept(&draw_server);

    TCP::getInstance()->disconnect_from_server();*/

  }
  catch(Error &e) {
    std::cout << "ERROR : " << e << "\n";
  }

  return 0;
}
