#include <string>
#include <fstream>
#include "pizza_headers.h"
using namespace std;
/********************************************************************
** function:default construcotr 
** description:will pop if user uses not other
** parameters:none
** pre-conditions:none
** post-conditions:none

*********************************************************************/
Pizza :: Pizza(){
    name = "Pretend Pizza";
    small_cost =0;
    medium_cost =0;
    large_cost =0;
    num_ingredients = 0;
    ingredients=NULL;
}
/********************************************************************
** function:non default constructor
** description:will set for user
** parameters:all the variables
** pre-conditions:must be variable
** post-conditions:will make it
*********************************************************************/
Pizza :: Pizza (string n, int s_cost, int m_cost, int l_cost, int p, string* ing){
    name = n;
    small_cost = s_cost;
    medium_cost= m_cost;
    large_cost = l_cost;
    ingredients = new string[p];
    for (int i =0; i < p;i++){
        ingredients[i] = ing[i];
    }
}
/********************************************************************
** function:copy constructor
** description:for pizza
** parameters:const pizza copy
** pre-conditions:will copy
** post-conditions:and construct

*********************************************************************/
Pizza::Pizza(const Pizza& copy){
    name = copy.name;
    small_cost = copy.small_cost;
    medium_cost = copy.medium_cost;
    large_cost = copy.large_cost;
    num_ingredients = copy.num_ingredients;
    if (ingredients ==0){
        ingredients = NULL;
    }
    else { 
        ingredients =  new string[num_ingredients];
        for (int i =0;i<num_ingredients;i++){
                ingredients[i] = copy.ingredients[i];
        }
    }
}
/********************************************************************
** function:assignment operator overload 
** description:will make the operator valid
** parameters:the const pizza copy
** pre-conditions:aoo
** post-conditions:= now works

*********************************************************************/
const Pizza& Pizza:: operator =(const Pizza& copy){
    name = copy.name;
    small_cost = copy.small_cost;
    medium_cost = copy.medium_cost;
    large_cost = copy.large_cost;
    num_ingredients = copy.num_ingredients;
    if (ingredients != NULL)
        delete [] ingredients;
    if (num_ingredients ==0){
        ingredients = NULL;
    }
    else { 
        ingredients =  new string[num_ingredients];
        for (int i =0;i<num_ingredients;i++){
                ingredients[i] = copy.ingredients[i];
        }
    }
return *this;
}

/********************************************************************
** function:destructor for pizza
** description:will delte
** parameters:none
** pre-conditions:delete
** post-conditions:delete

*********************************************************************/
Pizza::~Pizza(){
    delete[]ingredients;
}

string Pizza :: get_name()const{return name;}
int Pizza :: get_small_cost()const{return small_cost;}
int Pizza :: get_medium_cost()const{return medium_cost;}
int Pizza :: get_large_cost()const{return large_cost;}
int Pizza :: get_num_ingredients()const{return num_ingredients;}

string Pizza :: get_ingredients(int i)const{ return ingredients[i];}
void Pizza :: set_name(string n){name = n ;}
void Pizza :: set_small_cost(int s_cost){small_cost = s_cost;}
void Pizza :: set_medium_cost(int m_cost){medium_cost = m_cost;}
void Pizza :: set_large_cost(int l_cost){large_cost = l_cost;}
void Pizza :: set_num_ingredients(int p){num_ingredients = p;}
void Pizza :: set_ingredients(string* ing){ingredients = ing;}

/********************************************************************
** function:set_from_file
** description:this will populate
** parameters:the file
** pre-conditions:must be a file
** post-conditions:will populate

*********************************************************************/
void Pizza :: set_from_file(ifstream& menu_file){
    menu_file>>name;
    menu_file>>small_cost;
    menu_file>>medium_cost;
    menu_file>>large_cost;
    menu_file>>num_ingredients;
    if (ingredients == NULL){
        ingredients = new string [num_ingredients];
    }
    for (int i =0; i < num_ingredients;i++){
        menu_file>>ingredients[i];
    }
}
