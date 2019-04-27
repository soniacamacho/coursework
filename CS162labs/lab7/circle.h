#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include "lab7.h"
using namespace std;
class Circle : public Shape{
    private:
        int radius;
    public :
        Circle();
        Circle(int);
        int get_radius();
        void set_radius(int);
        
        virtual int calc_area();
};
#endif
