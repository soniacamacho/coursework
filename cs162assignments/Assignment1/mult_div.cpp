/******************************************************
** program: assignment 1
** author: Sonia Camacho
** Date: 04/08/2017
** Description:assignment 1 yeah yeah
** Input:
** Output: 
*****************************************************/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <fstream>
#include <cmath>
#include "headers.h"
using namespace std;
/********************************************************************
** function: boool is int 
** description:checks to see if a char string is a valid int
** Parameters:char * int 
** Pre-Conditions: must have something entered
** Post-Conditions: will return true or false 
*********************************************************************/
bool is_int(char argv){
    if (argv < 48 or argv > 57){      
        return false;
    }
return true;
}
/********************************************************************
** function: bool get int 
** description:checks to see if a char string is a valid int
** Parameters:char * int 
** Pre-Conditions: must have something entered
** Post-Conditions: will return true or false 
*********************************************************************/
int get_int(string coordinate){
    int var=0;
    int exp= coordinate.length()-1;
    for(int i= 0; i < coordinate.length() ; i++){
        var+=((int)coordinate[i]-48)*pow(10,exp);
        exp--;
    }
    return var;
}
/********************************************************************
** function: boool is valid arguments 
** description:checks to see if the arguments are valid in the command line
** Parameters:char * int 
** Pre-Conditions: must have something entered
** Post-Conditions: will return true or false 
*********************************************************************/
bool is_valid_arguments(int argc, char** argv){
    char dash_s[] = "-s";
    char dash_f[] = "-f";
    int res = strcmp(argv[1], dash_s);
    int res1 = strcmp(argv[1] , dash_f);
    int res2 = strcmp(argv[3] , dash_s);
    int res3 = strcmp(argv[3] , dash_f);
    if ((res != 0) and (res1 != 0)){
        return false;
    }
    if ((res2 != 0) and (res3 != 0)){
        return false;
    }
    if (res == 0){
        if(is_int(*argv[2]) == true){
            return true;
        }
        else {
            return false;}
    }
return true;
}
/********************************************************************
** function: string  get file name 
** description:checks to see if a char string is a valid file name
** Parameters:char * int 
** Pre-Conditions: must have something entered
** Post-Conditions: will return true or false 
*********************************************************************/
string get_filename(int argc,char** argv){
    string file_name;
    char dash_f[] = "-f";
    int res1 = strcmp(argv[1] , dash_f);
    int res2 = strcmp(argv[3] , dash_f);
    if (res1 == 0){
        file_name = string(argv[2]);
    }
    else if (res2 == 0){
        file_name = string(argv[4]);
    }
return file_name;
}
/********************************************************************
** function: string  get num states 
** description:checks to see if a char string is a number of states
** Parameters:char * int 
** Pre-Conditions: must have something entered
** Post-Conditions: will return true or false 
*********************************************************************/
int get_numstates(int argc,char** argv){
    string temp;
    int num_temp=0;
    char dash_s[] = "-s";
    int res = strcmp(argv[1], dash_s);
    int res2 = strcmp(argv[3] , dash_s);
    if (res == 0){
        temp = string(argv[2]);
        num_temp = get_int(temp);
    }
    else if (res2 ==0){
        temp = string(argv[4]);
        num_temp = get_int(temp);
    }
return num_temp;
} 
/********************************************************************
** function:state create states
** description:this is the struct that will create a state
** Parameters:int 
** Pre-Conditions:must have input
** Post-Conditions:none
*********************************************************************/
state *create_states(int num_states){
    state * states = new state[num_states];
return states;
}
/********************************************************************
** function:country create countries
** description:this function will be creating the countries
** Parameters:int
** Pre-Conditions:must have valid input 
** Post-Conditions:will have the countries
*********************************************************************/
county *create_counties(int num_county){
    county * c = new county[num_county];
return c;
}
/********************************************************************
** function:void pop counties
** description:this function will be getting the country data 
** Parameters:country and int ifstream 
** Pre-Conditions:must be clear
** Post-Conditions:will have the country data
*********************************************************************/
void pop_counties(string *city,int num_cities, ifstream &myfile){
    for (int i =0;i < num_cities; i++){
        myfile>>city[i];   
    }
}
/********************************************************************
** function:void get country data
** description:this function will be getting the country data 
** Parameters:country and int ifstream 
** Pre-Conditions:must be clear
** Post-Conditions:will have the country data
*********************************************************************/
void get_county_data(county * counties,int num_counties, ifstream &myfile){
    for (int i =0;i <num_counties;i++){
        myfile>>counties[i].name;
        myfile>>counties[i].population;
        myfile>>counties[i].avg_income;
        myfile>>counties[i].avg_house;
        myfile>>counties[i].cities;
        counties[i].city = new string [counties[i].cities];
        pop_counties(counties[i].city, counties[i].cities,myfile);
    }
}
/********************************************************************
** function:void get state data
** description:this function will be getting the state data
** Parameters:state and int
** Pre-Conditions:must have clear input
** Post-Conditions:will have the state information
*********************************************************************/
void get_state_data(state* states,int num_states,ifstream & myfile){
    for (int i =0;i<num_states;i++){
        myfile>>states[i].name;
        myfile>>states[i].population;
        myfile>>states[i].counties;
        county *counties = create_counties(states[i].counties);
        get_county_data(counties,states[i].counties, myfile);
        states[i].c = counties;
    }
}
/********************************************************************
** function:bubble sort state pop
** description:This function will sort the states in order by population 
** Parameters:the sates
** Pre-Conditions:must be valid
** Post-Conditions:return the ordered states
*********************************************************************/
void bubble_sort_state_population(state* states, int num_states){
    state temp;
    for (int i =1;i < num_states;i++){
        for (int j =0;j < num_states - i ; j++){
            if(states[j].population > states[j+1].population){
                temp.population = states[j].population;
                states[j].population = states[j+1].population;
                states[j+1].population = temp.population;
            }
        }
    }
}
/********************************************************************
** function:insertion sort
** description:This function will sort the states in order by name
** Parameters:the sates
** Pre-Conditions:must be valid
** Post-Conditions:return the ordered states
*********************************************************************/
void insertionSort(state* states, int n)
{
   string key;
    int  i, j;
   for (i = 1; i < n; i++)
   {
       key = states[i].name;
       j = i-1;
 while (j >= 0 && states[j].name > key)
       {
           states[j+1].name = states[j].name;
           j = j-1;
       }
       states[j+1].name = key;
   }
}
/********************************************************************
** function:bubble sort county population
** description:This function will sort the counties in order by population
** Parameters:the counties
** Pre-Conditions:must be valid
** Post-Conditions:return the ordered counties 
*********************************************************************/
void bubble_sort_county_population(state*states, int num_states){
    county temp;
    for (int i =0;i < num_states;i++){
        for (int j =1;j < states[i].counties ; j++){
            for (int m=0; m<(states[i].counties-1);m++){
                if(states[i].c[m].population > states[i].c[m+1].population){
                    temp = states[i].c[m];
                    states[i].c[m] = states[i].c[m+1];
                    states[i].c[m+1] = temp;
                }
            }
 
        }
    }
}
/********************************************************************
** function: bubble sort counties name
** description:This function will sort the counties in order by name
** Parameters:the counties
** Pre-Conditions:must be valid
** Post-Conditions:return the ordered counties 
*********************************************************************/
void bubble_sort_county_name(state*states, int num_states){
    county temp;
    for (int i =0;i < num_states;i++){
        for (int j =1;j < states[i].counties ; j++){
            for (int m=0; m<(states[i].counties-1);m++){
                if(states[i].c[m].name > states[i].c[m+1].name){
                    temp = states[i].c[m];
                    states[i].c[m] = states[i].c[m+1];
                    states[i].c[m+1] = temp;
                }
            }
 
        }
    }
}
/********************************************************************
** function: boool is valid income 
** description:checks to see if the arguments are valid in the command line
** Parameters:char * int 
** Pre-Conditions: must have something entered
** Post-Conditions: will return true or false 
*********************************************************************/
bool valid_income( int income){
    if (income > 0 ){
            return true;
    }
    else{
        return false;
    }
}
/********************************************************************
** function:get county inocome
** description:this function will determine the counties with an income above a certain amount
** Parameters:user input
** Pre-Conditions:must have valid input
** Post-Conditions:will return the counties that have that income
*********************************************************************/
void get_county_income(state *states,int num_states){
    int income=0;
    int new_income=0;
    cout<<"Enter an income"<<endl;
    cin>>income;
    while (valid_income(income) == false){
        cout<<"invalid income try again"<<endl;
        cin>> new_income;
    }
    income = new_income;
}
/********************************************************************
** function:print states
** description:This function will sort the counties in order by population
** Parameters:the counties
** Pre-Conditions:must be valid
** Post-Conditions:return the ordered counties 
*********************************************************************/
void print_state(state *states,int num_states){
    cout<<"STATES IN ALPHABETICAL ORDER:"<<endl;
    for (int i=0; i < num_states; i++){
        cout<<states[i].name<<endl;
    }
    cout<<endl;
    cout<<"STATES IN POPULATION ORDER:"<<endl;
    for (int i =0; i < num_states; i++){
        cout<<states[i].population<<endl;
    }
    cout<<endl;
    cout<<"STATE WITH THE LARGEST POPULATION:"<<endl;
     for (int i =num_states -1 ; i < num_states; i++){
        cout<<states[num_states-1].name<<endl;
        cout<<states[num_states-1].population<<endl;
    }

    cout<<endl;
    cout<<"COUNTIES IN POPULATION ORDER:"<<endl;
    for (int i =0;i<num_states;i++){
        cout<<endl;
        cout<<"county:"<<endl;
        for (int j=0;j<states[i].counties;j++){
            cout<<states[i].c[j].name<<endl;  
        }
    }
    cout<<endl;
    cout<<"COUNTIES WITH LARGEST POPULATION:"<<endl;
    for (int i =0;i<num_states;i++){
        cout<<endl;
        cout<<"county:"<<endl;
        for (int j=states[i].counties-1;j<states[i].counties;j++){
            cout<<states[i].c[j].name<<endl;  
        }
    }
 
    cout<<endl;
 
    cout<<"COUNTIES IN ALPHABETICAL ORDER:"<<endl;
    for (int i =0;i<num_states;i++){
        cout<<endl;
        cout<<"county:"<<endl;
        for (int j=0;j<states[i].counties;j++){
            cout<<states[i].c[j].name<<endl;  
        }    
    }
 

}
/********************************************************************
** function:delete info
** description:this will free all the memory 
** Parameters:the counties
** Pre-Conditions:must be stuff to delete
** Post-Conditions:return the free space 
*********************************************************************/
void delete_info(state ** states,int num_states){
    for (int i =0; i < num_states;i++){
        for (int j =0; j< (*states)[i].counties;j++){
            delete [] (*states)[i].c[j].city;
        }
        delete [] (*states)[i].c;
    }
    delete [] (*states);
    states = NULL;
}
