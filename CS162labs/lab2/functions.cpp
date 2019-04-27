#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include "headers.h"
using namespace std;
state* create_states(int num_states){
    state * states = new state[num_states];
return states;
}

void get_state_data(state* states,int num_states,ifstream &input){
    for (int i =0;i<num_states;i++){
        input>>states[i].id_num;
        input>>states[i].first_name;
        input>>states[i].last_name;
        input>>states[i].major;
    }
}

void bubble_sort_id_nums(state* states, int num_states){
    state temp;
    for (int i =1;i < num_states;i++){
        for (int j =0;j < num_states - i ; j++){
            if(states[j].id_num > states[j+1].id_num){
                temp.id_num = states[j].id_num;
                states[j].id_num = states[j+1].id_num;
                states[j+1].id_num = temp.id_num;
            }
        }
    }
}
void bubble_sort_last_name(state* states, int num_states){
    state temp;
    for (int i =1;i < num_states;i++){
        for (int j =0;j < num_states - i ; j++){
            if(states[j].last_name > states[j+1].last_name){
                temp.last_name = states[j].last_name;
                states[j].last_name = states[j+1].last_name;
                states[j+1].last_name = temp.last_name;
            }
        }
    }
}
int sort_majors(state* states, int num_states){
    string* compare = new string[num_states];
    int counter=0;
    bool flag = false;
    for (int i =0; i < num_states ; i++){
        for(int j=0;j<num_states;j++){
            if(states[j].major == compare[i]){
                flag = true;
            }
            if(flag == false){
                compare[counter] = states[i].major;
                counter++;
            }
        }
    }
counter = counter -1;
return counter;
} 
void print_struct(state* states, int num_states){
        cout<<"sorted id numbers"<<endl;
        cout<<endl;
    for (int i =0; i< num_states;i++){
        cout<<states[i].id_num<<endl;
    }
        cout<<endl;
        cout<<"sorted last names"<<endl;
        cout<<endl;
    for (int i =0; i< num_states;i++){
        cout<<states[i].last_name<<endl;
    }
 
cout<<endl;
}
void delete_info(state ** states,int num_states){
    delete [] (*states);
    states = NULL;
}

