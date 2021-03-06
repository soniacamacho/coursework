//#include "playerheaders.h"
#include "propertyheaders.h"
#include<iostream>
#include<cstdlib>

using namespace std;
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Property::Property(){
	value = 0;
	location = rand_loc();
	tax = 0.015;
	num_tenants = 0;
	rent=0;
	mortgage = 0;
	months = 0;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Property::Property(int v,string loc,int ta,int num_t,int r,int m, int mon){
	value =v;
	location=loc;
	tax=ta;
	num_tenants=num_t;
	rent = r;
	mortgage = m;
	months = mon;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/

string Property :: rand_loc(){
    	int loca = rand()%5+1;
    	if (loca == 1){
    		return "SE";
    	}
    	if (loca == 2){
    		return "NE";
    	}
    	if (loca == 3){
    		return "Midwest";
    	}
    	if (loca == 4){
    		return "SW";
    	}
    	if (loca == 5){
    		return "NW";
    	}
    }





int Property::get_month()const{return months;}
int Property::get_mor()const{return mortgage;}
int Property::get_value()const{return value;}
string Property::get_location()const{return location;}
int Property::get_tax()const{return tax;}
int Property::get_num_tenants()const{return num_tenants;}
int Property::get_rent_amt()const{return rent;}

void Property::set_month(int mon){months = mon;}
void Property::set_mor(int m){mortgage = m;}
void Property::set_value(int v){ value = v;}
void Property::set_location(string loc){ location = loc;}
void Property::set_num_tenants(int num_t){ num_tenants = num_t;}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
int Property::pay_mortgage(){
    if (months > 0){
        months -- ;
        return mortgage;
    }
}



 