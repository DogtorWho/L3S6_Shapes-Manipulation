#ifndef EXPERT_HPP
#define EXPERT_HPP

#include "VisitorShape.hpp"

#include <string>

class Expert {
  virtual Shape* resolve(const std::string &s) const = 0;
};

#endif
