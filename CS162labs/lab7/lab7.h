#ifndef LAB7_H
#define LAB7_H
#include <iostream>
using namespace std;

class Shape{
protected:    
string name;
    string color;
public: 
    Shape();
    string get_name();
    string get_color();
    void set_name(string );
    void set_color(string);
    virtual int calc_area()=0;
};
#endif
