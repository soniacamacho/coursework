#ifndef PROPERTYHEADERS_H
#define PROPERTYHEADERS_H
#include <iostream>
#include <string>
#include <cmath>

//#include "househeaders.h"
using namespace std;

class Property{
	protected:
		int value;
		string location;
		int tax;
		int num_tenants;
		int rent;
		int mortgage;
		int months;
	public:
		Property();
		Property(int,string,int,int,int,int,int);
		
		int get_mor()const;
		int get_value()const;
		string get_location()const;
		int get_tax()const;
		int get_num_tenants()const;
		int get_rent_amt()const;
		int get_month()const;

		int pay_mortgage();
		void set_mor(int m);
		void set_value(int v);
		void set_location(string loc);
		void set_num_tenants(int num_t);
		string rand_loc();
		void set_month(int mon);

		
};
#endif
