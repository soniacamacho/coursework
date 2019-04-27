#include <iostream>
#include "rec.h"
#include <cmath>

using namespace std;
Rec :: Rec() : Shape() {
    name = "rectangle";
    color = "yellow";  
    width =0;
    length =0;
}
Rec :: Rec(int w, int l ) : Shape() {
    name = "rectangle";
    color = "yellow";
    width = w;
    length =l;
}



int Rec :: get_width(){
    return width;
}
int Rec :: get_length(){
    return length;
}
void Rec :: set_width(int w){
    width =w;
}
void Rec :: set_length(int l){
    length = l;
}

int Rec :: calc_area(){
    int area;
    area = length * width;
    return area;
}

