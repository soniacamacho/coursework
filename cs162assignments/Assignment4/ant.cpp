#include "ant.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Ant::Ant():Insect(){
	
	type = "_";
	cost = 0;
	armor = 0;
}

string Ant :: get_type(){
	//cout<<"ANT TYPE"<<endl;
	return type;
}
int Ant :: get_armor(){
	
	return armor;
}
void Ant :: set_armor(int a){
	armor =a;
}

int Ant:: two_dolla(){
	cost = 2;
	return cost;
}
int Ant:: four_dolla(){
	cost = 4;
	return cost;
}   
int Ant:: three_dolla(){
	cost =3;
	return cost;
}
int Ant:: six_dolla(){
	cost =6;
	return cost;
}

Harvester::Harvester():Ant(){
	type = "H";
	armor = 1;
}

Thrower::Thrower():Ant(){
	type = "T";
	armor = 1;
}
Fire::Fire():Ant(){
	type = "F";
	armor = 1;
}
Long_Thrower::Long_Thrower():Ant(){
	type = "LT";
	armor = 1;
}
Short_Thrower::Short_Thrower():Ant(){
	type = "ST";
	armor = 1;
}
Wall::Wall():Ant(){
	type = "W";
	armor = 4;
}
Ninja::Ninja():Ant(){
	type = "N";
	armor = 1;
}


                                                                                                      