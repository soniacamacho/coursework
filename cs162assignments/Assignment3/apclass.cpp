#include "apheaders.h"
//#include "tenant.h"

#include <iostream>
#include <cstdlib>
using namespace std;
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/

Apart :: Apart() : Property (){
    	num_tenants = rand() % 10 + 1;

    	tenant = new Tenant[num_tenants];
    	for(int i =0; i < num_tenants;i++){
    		tenant[i].type = "citizen";
    		tenant[i].max_budget = rand() % 4500 + 500;
    		tenant[i].agree_score = rand()% 5 + 1;
    	}
    	
    	rent =0;
    	value  = rand() % 300000 + 300000;
    	mortgage = rand () % 5000 + 1;
    	months = value / mortgage;
}
/*Apart::Apart(int num, int r):Property(){
	num_tenants = num;
	tenant = new Tenant[num_tenants];
	rent = r;
}*/
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Apart::Apart(const Apart& copy){
	num_tenants = copy.num_tenants;
	rent = copy.rent;
	//tenant = copy.tenant;
	if (num_tenants == 0){
		tenant = NULL;
	}
	else { 
		tenant = new Tenant[num_tenants];
		for (int i =0; i < num_tenants;i++){
				tenant[i] = copy.tenant[i];
		}
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
const  Apart&  Apart :: operator =(const Apart&  copy){
	num_tenants = copy.num_tenants;
	rent = copy.rent;
	//tenant = copy.tenant;
	if (tenant != NULL)
		delete []tenant;
	if (num_tenants == 0)
		tenant = NULL;
	else { 
		tenant = new Tenant[num_tenants];
		for (int i =0;i < num_tenants;i++){
				tenant[i] = copy.tenant[i];
		}
	}
	return *this;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Apart::~Apart(){
	delete [] tenant;
	tenant = NULL;
}
bool Apart::is_int(string num){
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
int Apart::get_int(string prompt){
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

string Apart :: get_type(int i )const{return tenant[i].type;}
void Apart ::set_type(int i , string c){tenant[i].type = c;}

int Apart ::get_max_b(int i)const{return tenant[i].max_budget;}
void Apart ::set_max_b(int i, int max){tenant[i].max_budget = max;}

int Apart ::get_agree_score(int i )const{return tenant[i].agree_score;}
void Apart ::set_agree_score(int i , int score){tenant[i].agree_score = score;}

int Apart ::get_rent()const{return rent;}
void Apart ::set_rent(){get_int("input a rent: ");}
		
int Apart::get_value()const{return value;}
void Apart::set_value(int v){value= v;}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
int Apart::collect_rent(){
	for (int i =0; i < num_tenants ; i++){
		if (tenant[i].type != "none"){
			if (tenant[i].agree_score < 2){
			if (rent > tenant[i].max_budget) {
				cout<<"no payment made "<<endl;
				return 0;
			}
			if (rent < tenant[i].max_budget ){
				cout<<"payment made "<<endl;
				return rent;
			}
		}
		if (tenant[i].agree_score > 1){
			if (rent > tenant[i].max_budget){
				cout<<"no payment made "<<endl;
				tenant[i].type = "none";
				return 0;
			}
			if (tenant[i].type != "none"){
				cout<<"payment made "<<endl;
				return rent;
			}
		}
	}
}
}






















 