#ifndef BEE_H
#define BEE_H
#include <iostream>
#include <string>
#include "insect.h"
using namespace std;

class Bee : public Insect {
	private:

	public:
		Bee();
		virtual string get_type();

		virtual int get_armor();
		virtual void set_armor(int a);
};
#endif 