#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
struct county {
    string name;
    string *city;
    int cities;
    int population;
    float avg_income;
    float avg_house;
};
struct state{
    string name;
    struct county *c;
    int counties;
    int population;
};
state *create_states(int num_states);
county *create_counties(int num_county);
void pop_counties(string *city,int num_cities, ifstream &myfile);
void get_county_data(county * counties,int num_counties, ifstream &myfile);
void get_state_data(state* states,int num_states,ifstream & myfile);
void delete_info(state ** states,int num_states); 
bool is_int(char argv);
int get_int(string coordinate);
bool is_valid_arguments(int argc, char** argv);
string get_filename(int argc,char** argv);
int get_numstates(int argc,char** argv);
void bubble_sort_state_population(state* states, int num_states);
void insertionSort(state* states, int n);
void bubble_sort_county_population(state*states, int num_states);
void bubble_sort_county_name(state*states, int num_states);
bool valid_income( int income);
void get_county_income(state *states,int num_states);
void print_state(state *states,int num_states);
