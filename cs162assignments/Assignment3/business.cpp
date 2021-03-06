#include "businessheaders.h"
//#include "spaces.h"
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
string Busi::rand_size(){
	int s = rand ()% 3+1;
	if (s == 1){
		return "small";
	}
	if (s ==2 ){
		return "medium";
	}
	if (s == 3){
		return "large";
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
    Busi :: Busi() : Property (){
    	num_spaces = rand() % 5 +1;
    	value = rand() % 400000 + 200000;
    	mortgage = rand () % 5000 + 1;
    	months = value / mortgage;
    	spaces = new Space[num_spaces]; 
    	for (int i =0;i<num_spaces;i++){
    		spaces[i].tenant.type = "Business";
    		spaces[i].tenant.max_budget = rand () % 80000 + 20000;
    		spaces[i].tenant.agree_score = rand() % 5 +1;
    		spaces[i].space_rent =0;
    		spaces[i].size = rand_size();
    	}
    	
}
/*Busi::Busi(int num):Property(){
	num_spaces = num;
	spaces = new Space[num_spaces];
}*/
int Busi:: get_num_spaces()const{return num_spaces;}
void Busi:: set_num_spaces(int num){ num_spaces = num;}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Busi::Busi(const Busi& copy){
	num_spaces = copy.num_spaces;
	//spaces = copy.spaces;
	if (num_spaces ==0){
		spaces = NULL;
	}
	else { 
		spaces = new Space[num_spaces];
		for (int i =0;i<num_spaces;i++){
				spaces[i] = copy.spaces[i];
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
const Busi& Busi:: operator =(const Busi&  copy){
	num_spaces = copy.num_spaces;
	//spaces = copy.spaces;
	if (spaces != NULL)
		delete []spaces;
	if (num_spaces == 0)
		spaces = NULL;
	else { 
		spaces = new Space[num_spaces];
		for (int i =0;i < num_spaces;i++){
				spaces[i] = copy.spaces[i];
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
Busi::~Busi(){
	delete [] spaces;
	spaces = NULL;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool Busi::is_int(string num){
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
int Busi::get_int(string prompt){
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

string Busi :: get_type(int i )const{return spaces[i].tenant.type;}
void Busi ::set_type(int i , string c){spaces[i].tenant.type = c;}

int Busi ::get_max_b(int i)const{return spaces[i].tenant.max_budget;}
void Busi ::set_max_b(int i, int max){spaces[i].tenant.max_budget = max;}

int Busi ::get_agree_score(int i )const{return spaces[i].tenant.agree_score;}
void Busi ::set_agree_score(int i , int score){ spaces[i].tenant.agree_score = score;}

int Busi ::get_rent()const{return rent;}
void Busi ::set_rent(){get_int("input a rent: ");}
		
int Busi::get_value()const{return value;}
void Busi::set_value(int v){value= v;}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
int Busi::collect_rent(){
	for (int i =0; i < num_spaces ; i++){
		if (spaces[i].tenant.type != "none"){
			if (spaces[i].tenant.agree_score < 2){
			if (rent > spaces[i].tenant.max_budget) {
				cout<<"no payment made "<<endl;
				return 0;
			}
			if (rent < spaces[i].tenant.max_budget ){
				cout<<"payment made "<<endl;
				value = value * 1.01;
				return rent;
			}
		}
		if (spaces[i].tenant.agree_score > 1){
			if (rent > spaces[i].tenant.max_budget){
				cout<<"no payment made "<<endl;
				spaces[i].tenant.type = "none";
				return 0;
			}
			if (spaces[i].tenant.type != "none"){
				cout<<"payment made "<<endl;
				value = value * 1.01;
				return rent;
			}
		}
	}
}
}













































 