#include <iostream>
#include <string>
using namespace std;

class Pizza{
private:
    string name;
    int num_ingredients;
public:
    Pizza();
    string get_name();
    int get_num_ingredients();
    void set_name(string n);
    void set_num_ingredients(int p);
};

