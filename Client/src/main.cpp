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
    tests->addShape(new Polygon(points, SHAPE_GREEN));*/

    tests->addSavedPlainTextShape("build/objects/save/plainText/segment_0");
    tests->addSavedPlainTextShape("build/objects/save/plainText/triangle_0");
    tests->addSavedPlainTextShape("build/objects/save/plainText/circle_0");
    tests->addSavedPlainTextShape("build/objects/save/plainText/polygon_0");
    //tests->addSavedPlainTextShape("build/objects/save/plainText/group_0");

    Vector2f v1_shp(10.f, 90.f);
    Vector2f v2_shp(50.f, 300.f);
    Segment shp1(v1_shp, v2_shp, SHAPE_GREEN);
    Vector2f v3_shp(420.f, 200.f);
    Vector2f v4_shp(380.f, 240.f);
    Segment shp2(v3_shp, v4_shp, SHAPE_YELLOW);
    std::vector<Shape*> shps = {&shp1, &shp2};
    Group grp(shps, SHAPE_BLUE);
    tests->addShape(&grp);

    tests->printExportedShapes();
    tests->printShapes();

    //tests->drawShapesRaylib();
    tests->drawShapesServer();

    //tests->saveShapesPlainText();



    // TEST GROUP VISIT
    /*Vector2f v1_s(20.f, 80.f);
    Vector2f v2_s(60.f, 120.f);
    Segment s1(v1_s, v2_s, SHAPE_BLUE);

    Vector2f v1_t(150.f, 15.f);
    Vector2f v2_t(180.f, 70.f);
    Vector2f v3_t(250.f, 25.f);
    Triangle t1(v1_t, v2_t, v3_t, SHAPE_RED);

    Vector2f v1_c(100.f, 220.f);
    Circle c1(v1_c, 30, SHAPE_CYAN);

    Vector2f v1_p(300.f, 150.f);
    Vector2f v2_p(400.f, 150.f);
    Vector2f v3_p(420.f, 200.f);
    Vector2f v4_p(380.f, 240.f);
    Vector2f v5_p(320.f, 250.f);
    Vector2f v6_p(280.f, 190.f);
    Polygon p1(SHAPE_GREEN);
    p1 += v1_p;
    p1 += v2_p;
    p1 += v3_p;
    p1 += v4_p;
    p1 += v5_p;
    p1 += v6_p;

    Vector2f v1_shp(10.f, 90.f);
    Vector2f v2_shp(50.f, 300.f);
    Segment shp1(v1_shp, v2_shp, SHAPE_GREEN);
    Vector2f v3_shp(420.f, 200.f);
    Vector2f v4_shp(380.f, 240.f);
    Segment shp2(v3_shp, v4_shp, SHAPE_YELLOW);
    std::vector<Shape*> shps = {&shp1, &shp2};
    Group grp(shps, SHAPE_BLUE);

    std::vector<Shape*> shapes = {&s1, &t1, &c1, &p1, &grp};
    Group g1(shapes, SHAPE_RED);
    std::cout << g1.export_to_string() << "\n";

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Drawing with raylib");
    SetTargetFPS(60);

    DrawRaylib draw_raylib;
    while (!WindowShouldClose()){
      BeginDrawing();
      ClearBackground(RAYWHITE);
      draw_raylib.visit(&g1);
      EndDrawing();
    }
    CloseWindow();*/


    /* ------------------------ LOADING ------------------------------------- */
    /*std::cout << "\n === Loading ===\n";
    ExpertPlainText *expert;
    expert = new ExpertPlainTextPolygon(NULL);
    expert = new ExpertPlainTextCircle(expert);
    expert = new ExpertPlainTextTriangle(expert);
    expert = new ExpertPlainTextSegment(expert);
    Shape *seg = expert->resolve("build/objects/save/plainText/segment_0");
    std::cout << seg->export_to_string() << "\n";
    Shape *tri = expert->resolve("build/objects/save/plainText/triangle_0");
    std::cout << tri->export_to_string() << "\n";
    Shape *cir = expert->resolve("build/objects/save/plainText/circle_0");
    std::cout << cir->export_to_string() << "\n";
    Shape *pol = expert->resolve("build/objects/save/plainText/polygon_0");
    std::cout << pol->export_to_string() << "\n";*/

    /* ------------------------ EXPORT -------------------------------------- */
    /*std::cout << "\n === ToString ===\n";
    std::cout << s1.export_to_string() << "\n";
    std::cout << t1.export_to_string() << "\n";
    std::cout << c1.export_to_string() << "\n";
    std::cout << p1.export_to_string() << "\n";
    std::cout << g1.export_to_string() << "\n";*/

    /* ------------------------ AREA ---------------------------------------- */
    /*std::cout << "\n === Area ===\n";
    std::cout << "Segment Area : " << s1.getArea() << "\n";
    std::cout << "Triangle Area : " << t1.getArea() << "\n";
    std::cout << "Circle Area : " << c1.getArea() << "\n";
    std::cout << "Polygon Area : " << p1.getArea() << "\n";
    std::cout << "Group Area : " << g1.getArea() << "\n";*/

    /* ------------------------ TRANSLATE ----------------------------------- */
    /*std::cout << "\n === Translate ===\n";
    Vector2f trans(50.f, 50.f);
    s1.translate(trans);
    std::cout << "Translate Segment : " << s1 << "\n";
    t1.translate(trans);
    std::cout << "Translate Triangle : " << t1 << "\n";
    c1.translate(trans);
    std::cout << "Translate Circle : " << c1 << "\n";
    p1.translate(trans);
    std::cout << "Translate Polygon : " << p1 << "\n";
    g1.translate(trans);
    std::cout << "Translate Group : " << g1 << "\n";*/

    /* ------------------------ HOMOTHETY ----------------------------------- */
    /*std::cout << "\n === Homothety ===\n";
    Vector2f home(25.f, 25.f);
    double zoom = 1.5f;
    s1.homothety(home, zoom);
    std::cout << "Homothety Segment : " << s1 << "\n";
    t1.homothety(home, zoom);
    std::cout << "Homothety Triangle : " << t1 << "\n";
    c1.homothety(home, zoom);
    std::cout << "Homothety Circle : " << c1 << "\n";
    p1.homothety(home, zoom);
    std::cout << "Homothety Polygon : " << p1 << "\n";
    g1.homothety(home, zoom);
    std::cout << "Homothety Group : " << g1 << "\n";*/

    /* ------------------------ ROTATE -------------------------------------- */
    /*std::cout << "\n === Rotate ===\n";
    Vector2f rot(25.f, 25.f);
    double radian = 0.5f;
    s1.rotate(rot, radian);
    std::cout << "Rotate Segment : " << s1 << "\n";
    t1.rotate(rot, radian);
    std::cout << "Rotate Triangle : " << t1 << "\n";
    c1.rotate(rot, radian);
    std::cout << "Rotate Circle : " << c1 << "\n";
    p1.rotate(rot, radian);
    std::cout << "Rotate Polygon : " << p1 << "\n";
    g1.rotate(rot, radian);
    std::cout << "Rotate Group : " << g1 << "\n";*/

    /* ------------------------ DRAW SERVER --------------------------------- */
    /*TCP::getInstance()->create_socket();
    TCP::getInstance()->connect_to_server();

    DrawServer draw_server;

    draw_server.visit(&s1);
    draw_server.visit(&t1);
    draw_server.visit(&c1);
    draw_server.visit(&p1);

    TCP::getInstance()->disconnect_from_server();*/


    /* ------------------------ DRAW RAYLIB --------------------------------- */
    /*InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Drawing with raylib");
    SetTargetFPS(60);

    DrawRaylib draw_raylib;

    while (!WindowShouldClose()){
      BeginDrawing();
      ClearBackground(RAYWHITE);
      draw_raylib.visit((Segment*)seg);
      draw_raylib.visit((Triangle*)tri);
      draw_raylib.visit((Circle*)cir);
      draw_raylib.visit((Polygon*)pol);

      draw_raylib.visit(&s1);
      draw_raylib.visit(&t1);
      draw_raylib.visit(&c1);
      draw_raylib.visit(&p1);
      draw_raylib.visit(&g1);

      EndDrawing();
    }
    CloseWindow();*/

    /* ------------------------ SAVING -------------------------------------- */
    /*SavePlainText save_text;
    save_text.remove_saves();

    save_text.visit(&s1);
    save_text.visit(&t1);
    save_text.visit(&c1);
    save_text.visit(&p1);
    save_text.visit(&g1);*/

  }
  catch(Error &e) {
    std::cout << "ERROR : " << e << "\n";
  }

  return 0;
}
