#include "insect.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Insect::Insect(){
	
	type = "  ";
	armor = 0; 
	
}

string Insect :: get_type(){  return type; }
int Insect :: get_armor(){ return armor;}
void Insect::set_armor(int a){
	armor =a;
}
/*
string Insect :: get_type(){
	return type;
}
void Insect :: set_type(string t){
	type = t;
}*/
/*const Insect& Insect:: operator =(const Insect&  copy){
	type = copy.type;
	//spaces = copy.spaces;
	if (bugs != NULL)
		delete []bugs;
	
	 
		bugs = new Insect[num_bugs];
		for (int i =0;i < num_spaces;i++){
				spaces[i] = copy.spaces[i];
		}
	
	return *this;
}*/                                                                                                                                                                                              