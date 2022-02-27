#ifndef EXPERTPLAINTEXTCIRCLE_HPP
#define EXPERTPLAINTEXTCIRCLE_HPP

#include "ExpertPlainText.hpp"

#include <vector>
#include <fstream>

class ExpertPlainTextCircle : public ExpertPlainText {
  public:
    ExpertPlainTextCircle(ExpertPlainText *next) : ExpertPlainText(next) {}

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

      if(parsedMessage[0] == "CIRCLE"){
        ShapeColor color = (ShapeColor)std::stoi(parsedMessage[1].c_str());

        double x1 = std::stod(parsedMessage[2].c_str());
        double y1 = std::stod(parsedMessage[3].c_str());
        Vector2f v1(x1, y1);

        double radius = std::stod(parsedMessage[4].c_str());

        return new Circle(v1, radius, color);
      }
      return NULL;
    }
};

#endif
