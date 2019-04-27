#include "lab7.h"
#include <iostream>
using namespace std;

Shape :: Shape(){
    name="shape";
    color = "color";
}
string Shape :: get_name(){
    return name;
}

string Shape :: get_color(){
    return color;
}

void Shape :: set_name(string n){
    name = n;
}

void Shape :: set_color(string c){
    color = c;
}
