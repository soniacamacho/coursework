#ifndef HOUSEHEADERS_H
#define HOUSEHEADERS_H
#include "propertyheaders.h"
#include "tenant.h"
#include <iostream>
#include <string>
using namespace std;

class House : public Property {
	private:
		Tenant tenant;
		

	public:
		House();
		string get_type()const;
		void set_type(string c);
		int get_max_b()const;
		void set_max_b(int max);
		int get_agree_score()const;
		void set_agree_score(int score);
		bool is_int(string);
		int get_int(string prompt);

		int collect_rent();
		int get_rent()const;
	    void set_rent();

	    int get_value()const;
	    void set_value(int v);
};
#endif
