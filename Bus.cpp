#include "Bus.hpp"
/*public*/
  Bus::Bus(const std::string& brand, const std::string& model, int v, const std::string& place, int cnt_seet, int cnt)
	  :Garazh(brand, model, v), place(place), cnt_seet(cnt_seet), cnt(cnt){}
  Bus::Bus(const Bus& g):Garazh(g.brand, g.model, g.v), place(g.place), cnt_seet(g.cnt_seet), cnt(g.cnt){}
  Bus::~Bus(){}
/*getteri i setteri*/
  std::string& Bus::Place(){
	   return place;
  }
  int& Bus::CntSeet(){
	   return cnt_seet;
  }
  int& Bus::Cnt(){
	   return cnt;
  }

std::istream& operator>>(std::istream& in, Bus& g){
   g.read(in);
   if(!(in >> g.place >> g.cnt_seet >> g.cnt)) throw Exception("Input data EROR");
   return in;
}
std::ostream& operator<<(std::ostream& out, const Bus& g){
	g.write(out);
	out << g.place << ' ' << g.cnt_seet << ' ' << g.cnt;
	return out;

}