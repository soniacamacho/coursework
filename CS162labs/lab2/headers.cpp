#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
state *create_states(int num_states);
struct state{
    int id_num;
    string first_name;
    string last_name;
    string major;
};

void bubble_sort_id_nums(state* states, int num_states);
void get_state_data(state* states,int num_states,ifstream &input);
void bubble_sort_last_name(state* states, int num_states);
int sort_majors(state* states, int num_states);
void print_struct(state* states, int num_states,int hi);
void delete_info(state ** states,int num_states);


