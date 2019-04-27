#include<iostream>
#include <string>
#include <cmath>
#include "restaurant_headers.h"
using namespace std;

Restaurant r;
/********************************************************************
** function:get int 
** description:will make a string into and int
** parameters:stirng
** pre-conditions:none
** post-conditions:none
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
** function:valid choice 
** description:will see if the choice is valid
** parameters:choice
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool valid_choice(string choice){
    for (int i =0; i < choice.length(); i++){
        if (choice[i] == 'C' or choice[i] == 'E' or choice[i] == 'Q'){
            return true;
        }
    }
    return false;       
}
/********************************************************************
** function:cust choice 
** description:will make sure the inpyt is 1-8
** parameters:num
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool valid_cust_choice(int num){
 if (num > 0 and num < 9){
    return true;
 }
 return false;
  
}
/********************************************************************
** function:valid emp choice
** description:will check if the employee choice is valid
** parameters:num
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool valid_emp_choice(int num){
    if (num > 0 and num < 11){
        return true;
    } 
    return false;     
}
/********************************************************************
** function:customer choice
** description:will give all choices 
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
int customer_options(){
    string choice;
    int num=0;
    do {
        cout<<"**********************************************************"<<endl;
        cout<<"what would you like to do? \n 1. View Menu \n 2. Search by Cost \n 3. Search by Ingredients \n 4. Place Order \n 5. View Hours \n 6. View Address \n 7. View Phone \n 8. Log out" <<endl;
        cout<<"**********************************************************"<<endl;
        getline(cin,choice);
        num = get_int(choice);
    }

    while (valid_cust_choice(num) == false);
    return num;
}
/********************************************************************
** function:employee optuons
** description:will provide all the employee optuions
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
int employee_options(){
    int num=0;
    string choice;
    do{
        cout<<"**********************************************************"<<endl;
        cout<<"What would you like to do? \n 1. Change hours \n 2. View Orders \n 3. Remove Order \n 4. Add Item to Menu \n 5. Remove Item from Menu \n 6. View Menu \n 7. View Hours \n 8. View Address \n 9. View Phone \n 10. Log out"<<endl;
        cout<<"**********************************************************"<<endl;
        getline(cin,choice);
        num = get_int(choice);
    }
    while(valid_emp_choice(num) == false);
    return num;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void funcs(int sub_op){
    int cost=0;
    int size=0;
    string ig ="";
    
        if (sub_op == 1){
            r.read_menu();
        }
        if (sub_op == 2){
            cout<<"Enter a price"<<endl;
            cin>>cost; 
            cout<<"Enter a size[1]small [2]medium [3] large"<<endl;
            cin>>size;
            if(size == 1){
                r.search_by_small_cost(cost);
            }   
            else if(size == 2){
                r.search_by_med_cost(cost); 
            }
            else{
                r.search_by_lar_cost(cost);
            }
        }
                
        if (sub_op == 3){
            int choi=0;
            cout<<"Do you want to include[1] or exclude[2] this Ingredient? "<<endl;
            cin>>choi;
            cout<<"Enter an Ingredient"<<endl;
            cin>>ig;
            if(choi == 1)
                r.search_by_ing(ig);
      
        }
        if (sub_op == 4){
            r.make_an_order();
        }
}
/********************************************************************
** function:fivef
** description:thisis the function calls if it is choice 5>
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void fivef(int sub_op){

        if (sub_op == 5){
            r.view_hours();
            r.set_from_file();
            for(int i =0;i < r.get_num_days();i++){
                cout<<r.get_num_week(i).days<<" ";
                cout<<r.get_num_week(i).open_hour<<" ";
                cout<<r.get_num_week(i).close_hour<<" ";
                cout<<endl;
            }
            cin.clear();
        }
                
        if(sub_op == 6){
                    r.view_ad();
                    r.set_from_file();
                    cout<<r.get_address()<<endl;
                }
                if(sub_op == 7){
                    r.view_ph();
                    r.set_from_file();
                    cout<<r.get_phone()<<endl;
                }                    
}
/********************************************************************
** function:funcs2
** description:this is all options for emps
** parameters:op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void funcs2(int op){
    if (op == 1){      
        r.change_hours();

    }
    if (op == 2){       
        r.view_ord();
    }
    if (op == 3){
       // r.rmv_ord();
    }
    if(op ==4){
        r.add_ord();
    }
}
/********************************************************************
** function:funcs3
** description:this iwll do it for optuons 6>
** parameters:op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void funcs3(int op){
    if (op == 6){
        r.read_menu();
    }
    if (op == 7){
        r.view_hours();
            r.set_from_file();
            for(int i =0;i < r.get_num_days();i++){
                cout<<r.get_num_week(i).days<<" ";
                cout<<r.get_num_week(i).open_hour<<" ";
                cout<<r.get_num_week(i).close_hour<<" ";
                cout<<endl;
            }
            cin.clear();
    }
    if(op == 8){
        r.view_ad();
        r.set_from_file();
        cout<<r.get_address()<<endl;
    }
    if (op == 9){
         r.view_ph();
         r.set_from_file();
         cout<<r.get_phone()<<endl;
    }
}
/********************************************************************
** function:main
** description:this is the driver of it all 
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
int main(){
    Restaurant r;
    cout<<endl;
    cout<<"********************************************************************"<<endl;
    cout<<"*************************** WELCOME! *******************************"<<endl;
    cout<<endl;
    int sub_op=0;
    int cost=0;
    int op=0;
    int hi=0;
    int size=0;
    string ig ="";
    string choice;
    do {
        cout<<"Are you a customer (C) or employee (E) or would you like to quit (Q)?"<<endl;
        getline(cin,choice);
    }
    while (valid_choice(choice) == false);
    for (int i =0; i < choice.length(); i++){
        if (choice[i] == 'C') {  
            do{
                sub_op = customer_options();
                if (sub_op == 8){
                    cout<<"logged out"<<endl;
                    return 0;
                }
                else if(sub_op >0 and sub_op<5){
                funcs(sub_op);
                
                cin.ignore();
                cin.clear();
                }
                else{
                    fivef(sub_op);
                    cin.ignore();
                    cin.clear();
                }
            }
            while(hi != 8); 

        }    
        else if (choice[i] == 'E') {
            r.get_num_employee();
            bool ii=false;
            r.set_from_emp_file();
                do {
                    ii= r.get_log();
                }
            while(ii == false);
            if(ii == true){
            do{
                op = employee_options();
                
                if (op == 10){
                    cout<<"logged out"<<endl;
                    return 0;
                }
                else if(op > 0 and op < 5){
                    funcs2(op);
                    cin.ignore();
                    cin.clear();
                }
                else{
                    funcs3(op);
                    cin.ignore();
                    cin.clear();
                }
            }
            while(hi != 10);
        
              
        }
    }   
    else {
            cout<<"goodbye"<<endl;
            return 0; }
        }
return 0;
}
