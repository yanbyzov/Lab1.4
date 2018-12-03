#pragma once
#inlide "List.cpp"

template<typename T>
struct Element{//element spiska
  	T _data; // znachenie elementa
	Element *_next;	//ssilka na sleduyushiy elenet
	Element *_prev;	//ssila na predidushiy elenent
};

template<typename T>
class List {
private:
    Element<T> *_head; //nachalo spiska
	Element<T> *_tail; //konec spiska
    int _size; //razmer
public:
   List();//konstructor
   void add(const T &_data);//zanosim element v konec spiska
   T remove(int index);//udalyaem perviy element
   int size(); //razmer
   T operator[](int index)const;//polucheniye itogo elementa
   T & operator[](int index);//polucheniye itogo elementa
   void clear();
   ~List(); //destructor
};


