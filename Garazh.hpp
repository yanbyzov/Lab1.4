#pragma once
#include <string>
#include <iostream>
#include "Exception.hpp"

class Garazh{
protected:
  std::string brand;//marka
  std::string model;//model
  int v;//obyem dvigatelya
  void read(std::istream& in);//schitivaniye
  void write(std::ostream& out) const;//vivod
public:
  Garazh(const std::string& brand = "", const std::string& model = "", int v = 0);
  Garazh(const Garazh& g);
  virtual ~Garazh();
  /*getteri i setteri*/
  std::string& Brand();
  std::string Model();
  int& V();
};