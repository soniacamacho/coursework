#include "./create.h"
#include <string>
using namespace std;

Pizza :: Pizza(){
    name = "peppers";
    num_ingredients = 2;
}

string Pizza :: get_name(){
    return name;
}

int Pizza :: get_num_ingredients(){
    return num_ingredients;
}

void Pizza :: set_name(string n){
    name = n ;
}

void Pizza :: set_num_ingredients(int p){
    num_ingredients = p;
}
