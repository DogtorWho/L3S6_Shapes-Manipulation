#ifndef EXPERTPLAINTEXT_HPP
#define EXPERTPLAINTEXT_HPP

#include "Expert.hpp"

class ExpertPlainText : public Expert {
  public:
    ExpertPlainText* _next;

    Shape* resolve(const std::string &s) const {
      Shape* shape = this->resolve1(s);

      if(shape != NULL)
      	return shape;
      else
      	if(_next != NULL)
      		return _next->resolve(s);
      	else
      		return NULL;
    }

  protected:
    ExpertPlainText(ExpertPlainText* next) : _next(next) {}

    virtual Shape* resolve1(const std::string &s) const = 0;
};

#endif
