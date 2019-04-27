#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <cmath>
#include "headers.h"
using namespace std;
int main(int argc, char**argv){
    int choice=0; 
    if (argc != 5){
        cout<<"invalid arguments"<<endl;
        return 0;
    }
    else if (is_valid_arguments(argc,argv) == false){
        cout<<"invalid arguments"<<endl;
        return 0;
    }
    string filename;
    filename = get_filename(argc,argv);
    int num_states=0;
    num_states = get_numstates(argc,argv);
    state *states;    
    
    ifstream myfile;
    myfile.open(filename.c_str());
    while (myfile.fail()){
        myfile.clear();
        cout<<"error file doesnt exist please input a valid file name "<<endl;
        cin>>filename;
        myfile.open(filename.c_str());
    }
    
    if (myfile.is_open()){ 
        states = create_states(num_states);
        get_state_data(states,num_states, myfile);
        bubble_sort_state_population(states,num_states);
        bubble_sort_county_population(states,num_states);
        bubble_sort_county_name(states,num_states);
        insertionSort(states,num_states);
        get_county_income(states,num_states);
        cout<<"would you like to print to a file"<<endl;
        cout<<"[1] yes [2] for no"<<endl;
        cout<<"if you chose yes the file will be info.txt"<<endl;
        cin>>choice;
        if (choice == 2){
            print_state(states,num_states);
        }
        else{
            ofstream file("info.txt");
 
     file<<"STATES IN ALPHABETICAL ORDER:"<<endl;
    for (int i=0; i < num_states; i++){
        file<<states[i].name<<endl;
    }

    file<<endl;
    file<<"STATES IN POPULATION ORDER:"<<endl;
    for (int i =0; i < num_states; i++){
        file<<states[i].population<<endl;
    }
    file<<endl;
    file<<"STATE WITH LARGEST POPULATION"<<endl;
     for (int i =num_states -1 ; i < num_states; i++){
        file<<states[num_states-1].name<<endl;
        file<<states[num_states-1].population<<endl;
    }
    file<<endl;
    file<<"COUNTIES IN POPULATION ORDER"<<endl;
    for (int i =0;i<num_states;i++){
        file<<endl;
        file<<"county:"<<endl;
        for (int j=0;j<states[i].counties;j++){
            file<<states[i].c[j].name<<endl;  
        }
    }
    file<<endl;
    file<<"COUNTIES WITH LARGEST POPULATION:"<<endl;
    for (int i =0;i<num_states;i++){
        file<<endl;
        file<<"county:"<<endl;
        for (int j=states[i].counties-1;j<states[i].counties;j++){
            file<<states[i].c[j].name<<endl;  
        }
    }
 

    file<<endl;
     file<<"COUNTIES IN ALPHABETICAL ORDER"<<endl;
    for (int i =0;i<num_states;i++){
        file<<endl;
        file<<"county:"<<endl;
        for (int j=0;j<states[i].counties;j++){
            file<<states[i].c[j].name<<endl;  
        }
    }
 
    }     
    }
    myfile.close();
    delete_info(&states,num_states);  
return 0;
}
