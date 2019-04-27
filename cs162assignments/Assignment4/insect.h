#ifndef INSECT_H
#define INSECT_H
#include <iostream>
#include <string>

//insect class
using namespace std;

class Insect{
	protected:
		string type;
		int armor;
	public:
		//string type;
		Insect();
		virtual string get_type();
		virtual int get_armor();
		virtual void set_armor(int a);
		//void set_type(string);
};
#endif
