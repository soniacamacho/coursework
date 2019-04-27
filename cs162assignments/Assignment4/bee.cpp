#include "bee.h"
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
Bee::Bee():Insect(){
	
	type = "b";
	armor = 3;
	
}
string Bee :: get_type(){ return type; }

int Bee :: get_armor(){ return armor; }

void Bee :: set_armor(int a){ armor =a; }                                