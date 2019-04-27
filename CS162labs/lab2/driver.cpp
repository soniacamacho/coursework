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
int main(){
    string new_name;
    ifstream input;
    state* states;
    int num_states;
    
     cout<<"enter a file name:"<<endl;
    cin>>new_name;
    input.open(new_name.c_str());
    while (input.fail()){
        input.clear();
        cout<<"error file doesnt exist please input a valid file name "<<endl;
        cin>>new_name;
        input.open(new_name.c_str());
    }
    if (input.is_open())
    {
        input>>num_states;
        states = create_states(num_states); 
        get_state_data(states,num_states,input);
        bubble_sort_id_nums(states,num_states);
        bubble_sort_last_name(states,num_states);

        cout<<"open newfile.txt to see answers"<<endl;
        ofstream file("newfile.txt");
            file<<"number of unique majors: "<< sort_majors(states,num_states)<<endl;
        file<<"sorted id numbers"<<endl;
        file<<endl;
    for (int i =0; i< num_states;i++){
        file<<states[i].id_num<<endl;
    }
        file<<endl;
        file<<"sorted last names"<<endl;
        file<<endl;
    for (int i =0; i< num_states;i++){
        file<<states[i].last_name<<endl;
    }
 
    
    }
    input.close();
    delete_info(&states,num_states);
    
return 0;
}
