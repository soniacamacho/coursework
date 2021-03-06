#ifndef BUSINESSHEADERS_H
#define BUSINESSHEADERS_H
#include "propertyheaders.h"
#include "tenant.h"
#include "spaces.h"

#include <iostream>
#include <string>
using namespace std;

class Busi : public Property {
	private:
		Tenant tenant;
		int num_spaces;
		Space* spaces;
	public:
		Busi();
		//Busi(int n);
    	int get_num_spaces()const;
		void set_num_spaces(int num);
		string rand_size();

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







		Busi(const Busi&);
        const Busi&  operator =(const Busi&);
        ~ Busi();


};
#endif
 