#include "menu_headers.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/********************************************************************
** function:default constructor
** description:this will set default values
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Menu :: Menu(){
    num_pizzas = 0;
    pizzas = NULL;
}
/********************************************************************
** function:none default constructor 
** description:this will set the num and array 
** parameters:the number and an array of p]izzas
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Menu :: Menu ( int num, Pizza* p){
	num_pizzas = num;
	pizzas = new Pizza[num_pizzas];
	for (int i =0; i < num_pizzas; i ++){
		pizzas[i] = p[i];
	}
}
/********************************************************************
** function:This is the copy constructor 
** description:this is the cc
** parameters:the const menu and copy
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Menu::Menu(const Menu& copy){
	num_pizzas = copy.num_pizzas;
	pizzas = copy.pizzas;
	if (pizzas ==0){
		pizzas = NULL;
	}
	else { 
		pizzas = new Pizza[num_pizzas];
		for (int i =0;i<num_pizzas;i++){
				pizzas[i] = copy.pizzas[i];
		}
	}
}
/********************************************************************
** function:assignment operator overload for menu
** description:this is the assignment operator overload
** parameters:const menu copy
** pre-conditions:none
** post-conditions:none
*********************************************************************/
const Menu& Menu:: operator=(const Menu&  copy){
	num_pizzas = copy.num_pizzas;
	pizzas = copy.pizzas;
	if (pizzas != NULL)
		delete []pizzas;
	if (num_pizzas ==0)
		pizzas = NULL;
	else { 
		pizzas = new Pizza[num_pizzas];
		for (int i =0;i<num_pizzas;i++){
				pizzas[i] = copy.pizzas[i];
		}
	}
	return *this;
}




int Menu :: get_num_pizzas()const{ return num_pizzas;}
Pizza Menu :: get_pizzas(int i)const{return pizzas[i];}
void Menu :: set_num_pizzas(int num){num_pizzas = num ;}
/********************************************************************
** function:set pizzas 
** description:this will set the array of pizzas
** parameters:the number of pizzas an array of pizzas
** pre-conditions:must have them
** post-conditions:willl allocate memory for the pizzs 
*********************************************************************/
void Menu :: set_pizzas(int num_pizzas, Pizza* pie){
   for (int i =0; i < num_pizzas;i++){
   		pizzas[i] = pie[i];
   	}
}
/********************************************************************
** function:deconstructor for menu
** description:this will delete the dynamic array 
** parameters:none
** pre-conditions:must have array 
** post-conditions:will delete
*********************************************************************/
Menu::~Menu(){
	delete[]pizzas;
}
/********************************************************************
** function:set from menu file
** description:set the menu file and populates it
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Menu :: set_from_menu_file(){
	cout<<"enter the number of pizzas"<<endl;
	cin>>num_pizzas;
	ifstream menu_file;
	menu_file.open("menu.txt",ifstream ::in);
	pizzas = new Pizza[num_pizzas];
		for (int i =0; i < num_pizzas;i++){
			pizzas[i].set_from_file(menu_file);
		}
	menu_file.close();
}
