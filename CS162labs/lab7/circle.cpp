#include <iostream>
#include "circle.h"
#include <cmath>

using namespace std;
Circle :: Circle() : Shape() {
    name = "circle";
    color = "red";  
    radius = 0;
}
Circle :: Circle(int i ) : Shape() {
    name = "circle";
    color = "red ";  
    radius = i;
}



int Circle :: get_radius(){
    return radius;
}


void Circle :: set_radius(int r){
    radius = r;
}

int Circle :: calc_area(){
    int area;
    area = 3.14 * radius*radius;
    return area;
}

