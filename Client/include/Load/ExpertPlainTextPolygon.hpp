#ifndef EXPERTPLAINTEXTPOLYGON_HPP
#define EXPERTPLAINTEXTPOLYGON_HPP

#include "ExpertPlainText.hpp"

#include <vector>
#include <fstream>

class ExpertPlainTextPolygon : public ExpertPlainText {
  public:
    ExpertPlainTextPolygon(ExpertPlainText *next) : ExpertPlainText(next) {}

  protected:
    Shape* resolve1(const std::string &s) const {
      std::string file_content;
      std::ifstream file;
      file.open(s);
      if(file.is_open()){
        std::string tmp;
        while(getline(file, tmp)){
          file_content += tmp;
        }
        file.close();
      }

      std::vector<std::string> parsedMessage;
      std::stringstream s_stream(file_content);

      while(s_stream.good()){
        std::string substr;
        getline(s_stream, substr, ';');
        parsedMessage.push_back(substr);
      }

      if(parsedMessage[0] == "POLYGON"){
        ShapeColor color = (ShapeColor)std::stoi(parsedMessage[1].c_str());

        std::vector<Vector2f*> points;

        for(int i=2; i < (int)parsedMessage.size()-2; i+=2){
          double x = std::stod(parsedMessage[i].c_str());
          double y = std::stod(parsedMessage[i+1].c_str());
          Vector2f* v = new Vector2f(x, y);

          points.push_back(v);
        }

        return new Polygon(points, color);
      }
      return NULL;
    }
};

#endif
