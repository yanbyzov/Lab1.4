#pragma once
#include "Garazh.hpp"

class Bus: public Garazh{
protected:
  std::string place;//punkt
  int cnt_seet;//kolichestvo sidyachih mest
  int cnt; //vsego mest
public:
  Bus(const std::string& brand = "", const std::string& model = "", int v = 0, const std::string& place = "", int cnt_seet = 0, int cnt = 0);
  Bus(const Bus& g);
  virtual ~Bus();
  /*getteri i setteri*/
  std::string& Place();
  int& CntSeet();
  int& Cnt();
  friend std::istream& operator>>(std::istream& in, Bus& g);
  friend std::ostream& operator<<(std::ostream& out, const Bus& g); 
};