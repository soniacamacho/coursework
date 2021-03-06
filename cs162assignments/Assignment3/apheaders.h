#ifndef APHEADERS_H
#define APHEADERS_H
#include "propertyheaders.h"
#include "tenant.h"
#include <iostream>
#include <string>
using namespace std;

class Apart : public Property {
	private:
		Tenant* tenant;
	public:
		Apart();
		//Apart(int num, int r);

		string get_type(int i )const;
		void set_type(int i, string c);
		int get_max_b(int i)const;
		void set_max_b(int i, int max);
		int get_agree_score(int i)const;
		void set_agree_score(int i,int score);
		bool is_int(string);
		int get_int(string prompt);

		int collect_rent();
		int get_rent()const;
	    void set_rent();

	    int get_value()const;
	    void set_value(int v);




		Apart(const Apart&);
        const Apart& operator = (const Apart&);
        ~ Apart();

};
#endif
     