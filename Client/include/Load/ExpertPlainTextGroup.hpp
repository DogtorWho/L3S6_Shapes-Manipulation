#ifndef EXPERTPLAINTEXTGROUP_HPP
#define EXPERTPLAINTEXTGROUP_HPP

#include "ExpertPlainText.hpp"

#include <vector>
#include <fstream>
#include <sys/stat.h>
#include <cstdlib>
#include <dirent.h>

class ExpertPlainTextGroup : public ExpertPlainText {
  public:
    ExpertPlainTextGroup(ExpertPlainText *next) : ExpertPlainText(next) {}

  protected:
    Shape* resolve1(const std::string &s) const {
      if(s.back() == '/'){ // the string is a folder path
        DIR *pdir = NULL;
        pdir = opendir(s.c_str());
        struct dirent *pent = NULL;

        ShapeColor color = SHAPE_BLACK;
        std::vector<Shape*> shapes;

        while((pent = readdir(pdir))){ // read all the content of the folder
          if(pent->d_type == DT_DIR){ // found a child folder
            if((std::string)pent->d_name != "." && (std::string)pent->d_name != ".."){ // avoid the current and parent folder
              std::cout << "FOLDER : ";
              std::cout<< pent->d_name << std::endl;
              std::string shape_path = s + (std::string)pent->d_name + "/";
              std::cout<< "new path : " << shape_path << std::endl;
              shapes.push_back(this->resolve(shape_path));
            }
          }
          else if(pent->d_type == DT_REG){ // found a file to parse
            if((std::string)pent->d_name == "color"){ // get the color of the group
              std::string file_content;
              std::ifstream file;
              file.open(s+"color");
              if(file.is_open()){
                std::string tmp;
                getline(file, tmp);
                color = (ShapeColor)std::stoi(tmp);
                file.close();
              }
            }
            else{ // found a possible shape to parse
              std::string shape_path = s + (std::string)pent->d_name;

              Shape* shape = this->resolve(shape_path);
              if (shape != NULL)
                shapes.push_back(shape);
              /*else
                throw Error("ExpertPlainTextGroup::resolve1::couldn't resolve the filename");*/
            }
          }
          else{
            throw Error("ExpertPlainTextGroup::resolve1::problem with the directory");
          }
        }

        return new Group(shapes, color);
      }
      else{ // the string is not a folder, so not a group
        return NULL;
      }
    }
};

#endif
