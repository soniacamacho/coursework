#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Pizza{
private:
    string name;
    int small_cost;
    int medium_cost;
    int large_cost;
    int num_ingredients;
    int i;
    string* ingredients;

public:
    Pizza();
    Pizza (string ,int , int, int, int ,string*);
    Pizza (const Pizza&);
    const Pizza & operator = (const Pizza & copy);
    string get_name()const;
    int get_small_cost()const;
    int get_medium_cost()const;
    int get_large_cost()const;
    int get_num_ingredients()const;
    string get_ingredients(int i)const;
    void set_name(string n);
    void set_small_cost(int  s_cost);
    void set_medium_cost(int  m_cost);
    void set_large_cost(int  l_cost);
    void set_num_ingredients(int p);
    void set_ingredients(string* ingredients);
    void set_from_file(ifstream& menu_file);
    ~ Pizza();
};
