#include <iostream>
#include <string>
#include "pizza_headers.h"
class Menu{
    private:
        int num_pizzas;
        Pizza* pizzas;
    public:
        Menu();
        Menu(int ,Pizza*);

        int get_num_pizzas()const;
        Pizza get_pizzas(int)const;

        void set_num_pizzas(int num);
        void set_pizzas(int num , Pizza* pie);
        void set_from_menu_file();
        Menu(const Menu&);
        const Menu& operator =(const Menu&);
        ~ Menu();
        
};

