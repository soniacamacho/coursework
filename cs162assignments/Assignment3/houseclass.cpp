#include "househeaders.h"
#include <iostream>
#include<cstdlib>

using namespace std;
    
    
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
    House :: House() : Property (){
    	num_tenants =1;

    	mortgage = rand () % 5000 + 1;
    	tenant.type = "citizen";
    	tenant.max_budget = rand() % 4500 + 500;
    	tenant.agree_score = rand()% 5 + 1;
    	rent =0;
    	value  = rand() % 500000 + 100000;
    	months = value / mortgage;
	}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool House:: is_int(string num){
    for (int i=0;i<num.length();i++){
        if (num[i]<'0' or num[i]>'9'){
            return false;
        }
    }   
    return true;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
int House::get_int(string prompt){
    string t;
    bool in = false;

    cout<<prompt<<endl;
    while (in == false){
        getline(cin, t);
        in = is_int(t);
        if(in == false){
            cout<<"bad input try again."<<endl;
        }
    }
    int var=0;
    int exp=0;
    for(int i= t.length()-1; i>=0 ; i--){
        var+=(((int)t[i])-48)*pow(10,exp);
        exp++;
    }

return var;
}




	string House :: get_type()const{return tenant.type;}
	void House ::set_type(string c){tenant.type = c;}

	int House ::get_max_b()const{return tenant.max_budget;}
	void House ::set_max_b(int max){tenant.max_budget = max;}
		
	int House ::get_agree_score()const{return tenant.agree_score;}
	void House ::set_agree_score(int score){tenant.agree_score = score;}

	int House ::get_rent()const{return rent;}
	void House::set_rent(){get_int("input a rent: ");}
	int House::get_value()const{return value;}
	void House::set_value(int v){value= v;}

/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
	int House::collect_rent(){

		if (tenant.agree_score < 2){
			if (rent > tenant.max_budget) {
				cout<<"no payment made "<<endl;
				return 0;
			}
			if (rent < tenant.max_budget ){
				cout<<"payment made "<<endl;
				return rent;
			}
		}
		if (tenant.agree_score > 1){
			if (rent > tenant.max_budget){
				cout<<"no payment made "<<endl;
				tenant.type = "none";
				return 0;
			}
			if (tenant.type != "none"){
				cout<<"payment made "<<endl;
				return rent;
			}
		}
	}



   