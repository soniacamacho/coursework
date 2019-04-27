#include <iostream>

int * initialize_array(){
    int * arr = new int;
return arr;
}

void populate_array(int * pointer){
    * pointer = 15;
}

void delete_array(int * p){
    delete p;
    p = NULL;
}

int main(){
    int * ar = initialize_array();
    populate_array(ar);
    delete_array(ar);
return 0;
}
