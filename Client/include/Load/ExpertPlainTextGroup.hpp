#ifndef EXPERTPLAINTEXTGROUP_HPP
#define EXPERTPLAINTEXTGROUP_HPP

#include "ExpertPlainText.hpp"

#include <vector>
#include <fstream>

class ExpertPlainTextGroup : public ExpertPlainText {
  public:
    ExpertPlainTextGroup(ExpertPlainText *next) : ExpertPlainText(next) {}

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

      if(parsedMessage[0] == "GROUP"){
        std::cout << "cc\n";
        ShapeColor color = (ShapeColor)std::stoi(parsedMessage[1].c_str());
        std::vector<Shape*> shapes;

        std::string shape;
        for(int i = 2; i < (int)parsedMessage.size(); i++){
          if(parsedMessage[i] != "END"){
            shape += parsedMessage[i];
            shape += ";";
          }
          else if(!shape.empty()){
            shape += "END;";
            shapes.push_back(this->resolve(shape));
            std::cout << "shape: " << shapes[0] << std::endl;
            shape = "";
          }
        }

        return new Group(shapes, color);
      }
      return NULL;
    }
};

#endif
