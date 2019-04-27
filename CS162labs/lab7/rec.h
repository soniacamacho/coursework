#ifndef REC_H
#define REC_H

#include <iostream>
#include "lab7.h"
using namespace std;
class Rec : public Shape{
    private:
        int width;
        int length;
    public :
        Rec();
        Rec(int, int);
        int get_width();
        int get_length();
        void set_width(int);
        void set_length(int);
        
        virtual int calc_area();
};
#endif
