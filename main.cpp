#include "List.hpp"
#include "Bike.hpp"
#include "Bus.hpp"
#include "Car.hpp"
#include <fstream>
#include <iomanip>

using namespace std;


int main(){
   setlocale(LC_ALL, "");
   List<Car> cars;
   List<Bus> bus;
   List<Bike> bikes;
   Car ct;
   Bus bt;
   Bike bit;
   ifstream in;
   ofstream out;
   int ch1, ch2, n;
   while(true){
		cout << "\n\n1. Dobavit\n2. Udalit\n3. Izmenit\n4. Sohranit\n5. Zagruzit\n6. Vivwsti\n7. Vihod\n";
		while(!(cin >> ch1) && ch1 > 0 && ch1 < 7);
		if(ch1 == 7) return 0;
		cout << "1. Mashina\n2. Avtobus\n3. Motocikl\n";
		while(!(cin >> ch2) && ch2 > 0 && ch2 < 4);
		switch(ch1){
		case 1:
			try{
			   switch(ch2){
			   case 1:
				   cout << "Marka model obyem cvet tip_KPP\n";
				   cin >> ct;
				   cars.add(ct);
				   break;
			   case 2:
				   cout << "Marka model obyem punkt_naznacheniya sidyachie vsego_mest\n";
				   cin >> bt;
				   bus.add(bt);
				   break;
			   case 3:
				   cout << "Marka model obyem mestnost moshnost\n";
				   cin >> bit;
				   bikes.add(bit);
				   break;
			   }
			}
			catch(const Exception& exc){
				cout << exc.what();
			}
			break;
		case 2:
			cout << "Индекс\n";
			switch(ch2){
			   case 1:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < cars.size());
				   cars.remove(ch1);
				   break;
			   case 2:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < bus.size());
				   bus.remove(ch1);
				   break;
			   case 3:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < bikes.size());
				   bikes.remove(ch1);
				   break;
			   }
			break;
		case 3:
			try{
			   cout << "Индекс\n";
			   switch(ch2){
			   case 1:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < cars.size());
				   cout << "Marka model obyem cvet tip_KPP\n";
				   cin >> cars[ch1];
				   break;
			   case 2:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < bus.size());
				   cout << "Marka model obyem punkt_naznacheniya sidyachie vsego_mest\n";
				   cin >> bus[ch1];
				   break;
			   case 3:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < bikes.size());
				   cout << "Marka model obyem mestnost moshnost\n";
				   cin >> bikes[ch1];
				   break;
			   }
			}
			catch(const Exception& exc){
				cout << exc.what();
			}
			break;
		case 4:
			switch(ch2){
			   case 1:
				   out.open("cars");
				   out << cars.size() << '\n';
				   for(int i = 0; i < cars.size(); ++i)
						out << cars[i] << '\n';
				   break;
			   case 2:
				   out.open("bus");
				   out << bus.size() << '\n';
				   for(int i = 0; i < bus.size(); ++i)
						out << bus[i] << '\n';
				   break;
			   case 3:
				   out.open("bikes");
				   out << bikes.size() << '\n';
				   for(int i = 0; i < bikes.size(); ++i)
						out << bikes[i] << '\n';
				   break;
			   }
			out.close();
			break;
		case 5:
			try{
			   switch(ch2){
			   case 1:
				   in.open("cars");
				   in >> n;
				   for(int i = 0; i < n; ++i){
					   in >> ct;
					   cars.add(ct);
				   }
				   break;
			   case 2:
				   in.open("bus");
				   in >> n;
				   for(int i = 0; i < n; ++i){
					   in >> bt;
					   bus.add(bt);
				   }
				   break;
			   case 3:
				   in.open("bikes");
				   in >> n;
				   for(int i = 0; i < n; ++i){
					   in >> bit;
					   bikes.add(bit);
				   }
				   break;
			   }
			}
			catch(const Exception& exc){
				cout << exc.what();
			}
			in.close();
			break;
		case 6:
			cout << setw(2) << "№" << setw(10) << "marka" << setw(10) << "model" << setw(10) << "obyem";
			switch(ch2){
			   case 1:
				   cout<< setw(10) << "Cvet" << setw(12) << "tip_KPP";
				   for(int i = 0; i < cars.size(); ++i)
						cout << '\n' << setw(2) << i
						<< setw(10)  << cars[i].Brand()
						<< setw(10)  << cars[i].Model()
						<< setw(10)  << cars[i].V()
						<< setw(10)  << cars[i].Color()
						<< setw(12)  << cars[i].Type();
				   break;
			   case 2:
				   cout<< setw(8) << "Punkt" << setw(13) << "Sidyachih" << setw(9) << "Vsego";
				   for(int i = 0; i < bus.size(); ++i)
						cout << '\n' << setw(2) << i
						<< setw(10)  << bus[i].Brand()
						<< setw(10)  << bus[i].Model()
						<< setw(10)  << bus[i].V()
						<< setw(12)  << bus[i].Place()
						<< setw(4)  << bus[i].CntSeet()
						<< setw(11)  << bus[i].Cnt();
				   break;
			   case 3:
				   cout<< setw(10) << "Mestnost" << setw(10) << "Moshnost";
				   for(int i = 0; i < bikes.size(); ++i)
						cout << '\n' << setw(2) << i
						<< setw(10)  << bikes[i].Brand()
						<< setw(10)  << bikes[i].Model()
						<< setw(10)  << bikes[i].V()
						<< setw(10)  << bikes[i].Place()
						<< setw(8)  << bikes[i].Power();
				   break;
			   }
			break;
		}
   }
}

