#include <string>
#include <fstream>
#include <iostream> 
#include "restaurant_headers.h"
using namespace std;
/********************************************************************
** function:this is the default constructor
** description:will set default values
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Restaurant::Restaurant(){    
    employees = NULL;
	week = NULL;
    name = " ";
    phone = " ";
    address = " ";
    num_emp =0;
    num_days=0;
    num_emp=0;
    num_days=0;
}
/********************************************************************
** function:non default constructor
** description:will have user set the vlas
** parameters:all the variables
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Restaurant::Restaurant(string n, string p, string a,int e,int d){
	//menu = m;
	name = n ;
	phone = p;
	address = a;
	num_emp = e;
	num_days= d;
	employees = new employee[num_emp];        	
	week = new hours[num_days];
}
/********************************************************************
** function:copy constructor 
** description:this is the cc
** parameters:const restarurant
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Restaurant::Restaurant(const Restaurant& copy){
	name = copy.name;
	phone = copy.phone;
	address = copy.address;
	employees = copy.employees;
	if (employees ==0){
		employees = NULL;
	}
	else { 
		employees = new employee[num_emp];
		for (int i =0;i<num_emp;i++){
				employees[i] = copy.employees[i];
		}
	}
}
/********************************************************************
** function:assignment operator overload
** description:this is the asoo
** parameters:const rest and copy
** pre-conditions:none
** post-conditions:none
*********************************************************************/
const Restaurant& Restaurant:: operator=(const Restaurant&  copy){
	name = copy.name;
	phone = copy.phone;
	address = copy.address;
	employees = copy.employees;
	if (employees != NULL)
		delete []employees;
	if (num_emp ==0)
		employees = NULL;
	else { 
		employees = new employee[num_emp];
		for (int i =0;i<num_emp;i++){
				employees[i] = copy.employees[i];
		}
	}
	return *this;
}
/*
Restaurant::~Restaurant(){
	delete[]employees;
	delete[] week;
	menu.Menu::~Menu();
}*/
string Restaurant::get_name()const{return name;}
int Restaurant::get_num_employee()const{return num_emp;}
void Restaurant::set_name(const string n){name = n ;}
int Restaurant::get_num_days()const{return num_days;}
void Restaurant::set_num_days(const int d){num_days = d;}
void Restaurant::set_num_employee(const int e){num_emp = e;}
/********************************************************************
** function:set from employee file
** description:this will get data from the employee file
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::set_from_emp_file(){
	ifstream employees_file;
	employees_file.open("employee.txt", ifstream ::in);
	cout<<"enter the number of employees"<<endl;
	cin>>num_emp;
	cin.ignore();
	employees = new employee[num_emp];
	for (int i =0; i < num_emp;i++){
		employees_file>>employees[i].id;
		employees_file>>employees[i].first_name;
		employees_file>>employees[i].last_name;
		employees_file>>employees[i].password;

	}
	employees_file.close();
}
/********************************************************************
** function:get log ing information
** description:this will get the employee log in info
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool Restaurant::get_log(){
	string id;
	string pass;
	cout<<"enter an id"<<endl;
	cin>>id;
	cin.ignore();
	cout<<"enter a password"<<endl;
	cin>>pass;
	cin.ignore();
	for (int i =0; i < num_emp;i++){
		if(employees[i].id == id and employees[i].password == pass){return true;}
	}
	return false;
}
/********************************************************************
** function:read_menu
** description:reads the menu 
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::read_menu(){
		//ifstream menu_file("menu.txt");
		cout<<"********************************************************************"<<endl;
        cout<<"******************************** MENU ******************************"<<endl;
      
		menu.set_from_menu_file();
        //cout<<menu.get_num_pizzas()<<endl;
        cout<<endl;
        for (int i =0; i < menu.get_num_pizzas();i++){
        cout<<menu.get_pizzas(i).get_name()<<" ";
        cout<<endl;
        cout<<"$"<<menu.get_pizzas(i).get_small_cost()<<" ";
        cout<<"$"<<menu.get_pizzas(i).get_medium_cost()<<" ";
        cout<<"$"<<menu.get_pizzas(i).get_large_cost()<<" ";
        cout<<endl;
        for (int m =0; m < menu.get_pizzas(i).get_num_ingredients();m++){
        	cout<<menu.get_pizzas(i).get_ingredients(m)<<" ";
        }
        cout<<endl;
        }
}
/********************************************************************
** function:search by small cost
** description:this will search by small cost
** parameters:int cost
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::search_by_small_cost(int cost){
	menu.set_from_menu_file();
	cout<<endl;
	cout<<"SEARCHING FOR A SMALL PIZZA $"<<cost<<endl;
	cout<<endl;
		cout<<"********************************************************************"<<endl;
		cout<<"*********************** SMALL PIZZAS *******************************"<<endl;
		for (int i =0; i< menu.get_num_pizzas();i++){	
			if (menu.get_pizzas(i).get_small_cost() <= cost ){
				cout<<menu.get_pizzas(i).get_name()<<" ";
				cout<<menu.get_pizzas(i).get_small_cost()<<" ";
				for (int i =0; i < menu.get_pizzas(i).get_num_ingredients();i++){
        			cout<<menu.get_pizzas(i).get_ingredients(i)<<" ";
        		}
        		cout<<endl;
			}
		}
}
/********************************************************************
** function:search by medium cost
** description:this will search by the medium cost
** parameters:int cost
** pre-conditions:none
** post-conditions:nnone
*********************************************************************/
void Restaurant::search_by_med_cost(int cost){
	menu.set_from_menu_file();
	cout<<endl;
	cout<<"SEARCHING FOR A MEDIUM PIZZA $"<<cost<<endl;
	cout<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<"***********************  MEDIUM PIZZAS *****************************"<<endl;
	
	for (int i =0; i< menu.get_num_pizzas();i++){	
			if (menu.get_pizzas(i).get_medium_cost() <= cost ){
				cout<<menu.get_pizzas(i).get_name()<<" ";
				cout<<menu.get_pizzas(i).get_medium_cost()<<" ";
				for (int i =0; i < menu.get_pizzas(i).get_num_ingredients();i++){
        			cout<<menu.get_pizzas(i).get_ingredients(i)<<" ";
        		}
        		cout<<endl;
			}
		}	
}
/********************************************************************
** function:search by large cost
** description:this will get the cost of the large pizza
** parameters:int cost
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::search_by_lar_cost(int cost){
	menu.set_from_menu_file();
	cout<<endl;
	cout<<"SEARCHING FOR A LARGE PIZZA $"<<cost<<endl;
	cout<<endl;
	cout<<"********************************************************************"<<endl;
	cout<<"***********************  LARGE PIZZAS ******************************"<<endl;

	for (int i =0; i< menu.get_num_pizzas();i++){	
			if (menu.get_pizzas(i).get_large_cost() <= cost ){
				cout<<menu.get_pizzas(i).get_name()<<" ";
				cout<<menu.get_pizzas(i).get_large_cost()<<" ";
				for (int i =0; i < menu.get_pizzas(i).get_num_ingredients();i++){
        			cout<<menu.get_pizzas(i).get_ingredients(i)<<" ";
        		}
        		cout<<endl;
			}
		}	
}
/********************************************************************
** function:search by ingredients
** description:this will search by ingredients
** parameters:string ing
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::search_by_ing(string ing){
	menu.set_from_menu_file();
	cout<<endl;
	cout<<"SEARCHING FOR A PIZZA WITH "<<ing<<endl;
	cout<<endl;
	for (int k =0; k< menu.get_num_pizzas();k++){	
		for (int i =0; i < menu.get_pizzas(k).get_num_ingredients();i++){
        	if (menu.get_pizzas(k).get_ingredients(i) == ing ){

        		cout<<menu.get_pizzas(k).get_name()<<" ";
        		cout<<endl;
        		cout<<"$"<<menu.get_pizzas(k).get_small_cost()<<" ";
        		cout<<"$"<<menu.get_pizzas(k).get_medium_cost()<<" ";
        		cout<<"$"<<menu.get_pizzas(k).get_large_cost()<<" ";
        		cout<<endl;
        		for (int m =0; m < menu.get_pizzas(k).get_num_ingredients();m ++){
        		cout<<menu.get_pizzas(k).get_ingredients(m)<<" ";
        		}
        		cout<<endl;
        		}
        	}
        }
 }
 /*void Restaurant::search_by_ex_ing(string ing){
	menu.set_from_menu_file();
	cout<<endl;
	int counter=0;
	cout<<"SEARCHING FOR A PIZZA WITHOUT "<<ing<<endl;
	cout<<endl;

	for (int k =0; k< menu.get_num_pizzas();k++){	
		for (int i =0; i < menu.get_pizzas(k).get_num_ingredients();i++){
        	if ( menu.get_pizzas(k).get_ingredients(i) != ing){
        		
        		cout<<menu.get_pizzas(k).get_name()<<" ";
        		cout<<endl;
        		cout<<"$"<<menu.get_pizzas(k).get_small_cost()<<" ";
        		cout<<"$"<<menu.get_pizzas(k).get_medium_cost()<<" ";
        		cout<<"$"<<menu.get_pizzas(k).get_large_cost()<<" ";
        		cout<<endl;
        		for (int m =0; m < menu.get_pizzas(k).get_num_ingredients();m ++){
        		cout<<menu.get_pizzas(k).get_ingredients(m)<<" ";
        		}
        	}
        
        }
      cout<<counter<<endl;
      }}  
*/
 

/********************************************************************
** function:set from file
** description:this will set data from the restarant file
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::set_from_file(){		
		ifstream restaurant_file ;
		restaurant_file.open("restaurant_info.txt", ifstream ::in);
		getline(restaurant_file,name);
		getline(restaurant_file,phone);
		getline(restaurant_file,address);
		
		restaurant_file>>num_days;
		week = new hours[num_days];
		for (int i =0; i < num_days;i++){
			restaurant_file>>week[i].days;
			restaurant_file>>week[i].open_hour;
			restaurant_file>>week[i].close_hour;
		}
		restaurant_file.close();
}


hours Restaurant::get_num_week(int i)const{	return week[i];}
/********************************************************************
** function:set week
** description:this will set the week
** parameters:num days and hours w
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::set_week(int num_days, hours* w){
	week = new hours[num_days];
	for (int i =0; i <num_days;i++){
		week[i] = w[i];
	}
}
/********************************************************************
** function:view hours
** description:lets you view hours
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::view_hours(){	
	cout<<"********************************************************************"<<endl;
    cout<<"****************************** HOURS *******************************"<<endl;
    cout<<endl;
}

string Restaurant::get_address()const{  return address;}
void Restaurant::set_address(string a){address = a;}
/********************************************************************
** function:view add
** description:lets you view the address
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::view_ad(){
	cout<<"********************************************************************"<<endl;
    cout<<"**************************** ADDRESS *******************************"<<endl;
    cout<<endl;
}
string Restaurant::get_phone()const{return phone;}
void Restaurant::set_phone(string p){phone = p;}
/********************************************************************
** function:view ph
** description:lets you view the phone number
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::view_ph(){
	cout<<"********************************************************************"<<endl;
    cout<<"************************* PHONE NUMBER *****************************"<<endl;
    cout<<endl;
}
/********************************************************************
** function:make an order
** description:lets the user manke an order to the order file
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::make_an_order(){
	ofstream orders;
	menu.set_from_menu_file();
    orders.open("order.txt", ofstream::app);
	string pn;
	string user_name;
	string crd;
	int si;
	cout<<"********************************************************************"<<endl;
    cout<<"************************** PLACE ORDER *****************************"<<endl;
    cout<<endl;
    cout<<"Enter you name"<<endl;
    cin>>user_name;
    cout<<"Enter your credit card number ex:1111_111"<<endl;
    cin>>crd;
    cout<<"Enter the name of the pizza you would like to order"<<endl;
    cin>>pn;
    cout<<"Enter what size you would like [1] small [2] medium [3] large"<<endl;
    cin>>si;
    orders<<user_name<<endl;
    orders<<crd<<endl;
    for (int i =0; i < menu.get_num_pizzas();i++){
    	if (menu.get_pizzas(i).get_name() == pn){
    		orders<<pn<<endl;
    		if (si == 1){
    	    	orders<<"$"<<menu.get_pizzas(i).get_small_cost()<<" ";
    		}
    		else if(si ==2){
    	    	orders<<"$"<<menu.get_pizzas(i).get_medium_cost()<<" ";
    		}
    		else {
				orders<<"$"<<menu.get_pizzas(i).get_large_cost()<<" ";

    		}
    	}

	}
    
    orders.close();
}
/********************************************************************
** function:change hours
** description:lets you change the hours
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::change_hours(){
	int one,two,three,four,five,six,seven,one1,two2,three3,four4,five5,six6,seven7;
	cout<<"what hours would you like to change?"<<endl;
	cout<<"OPEN HOUR"<<endl;
		
		cout<<"for Sunday"<<endl;
		cin>>one;
		cout<<"for Monday"<<endl;
		cin>>two;
		cout<<"for Tuesday"<<endl;
		cin>>three;
		cout<<"for Wednesday"<<endl;
		cin>>four;
		cout<<"for Thursday"<<endl;
		cin>>five;
		cout<<"for Friday"<<endl;
		cin>>six;
		cout<<"for Saturday"<<endl;
		cin>>seven;
/********************************************************************
** function:change hours
** description:lets you change the hours
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
		cout<<"CLOSE HOUR"<<endl;
		
		cout<<"for Sunday"<<endl;
		cin>>one1;
		cout<<"for Monday"<<endl;
		cin>>two2;
		cout<<"for Tuesday"<<endl;
		cin>>three3;
		cout<<"for Wednesday"<<endl;
		cin>>four4;
		cout<<"for Thursday"<<endl;
		cin>>five5;
		cout<<"for Friday"<<endl;
		cin>>six6;
		cout<<"for Saturday"<<endl;
		cin>>seven7;
/********************************************************************
** function:change hours
** description:lets you change the hours
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
	ofstream new_hours;
		new_hours.open("new_h.txt");
		new_hours<<"S"<<" "<<one<<" "<<one1<<endl;
		new_hours<<"M"<<" "<<two<<" "<<two2<<endl;
		new_hours<<"T"<<" "<<three<<" "<<three3<<endl;
		new_hours<<"W"<<" "<<four<<" "<<four4<<endl;
		new_hours<<"R"<<" "<<five<<" "<<five5<<endl;
		new_hours<<"F"<<" "<<six<<" "<<six6<<endl;
		new_hours<<"S"<<" "<<seven<<" "<<seven7<<endl;

		new_hours.close();
}
/********************************************************************
** function:view ord
** description:lets you view the orders
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::view_ord(){
  string line;
  cout<<"ORDERS"<<endl;
  ifstream myfile ("order.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }
}
/********************************************************************
** function:add ord
** description:this lets you add an order
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Restaurant::add_ord(){
	string nn;
	int sc;
	int mc;
	int lc;
	int nume;
	string ingo;
	ofstream menu_file;
	menu_file.open("menu.txt",ofstream ::app);
	menu_file<<endl;
	cout<<"enter the name of the pizza you would like to add"<<endl;
	cin>>nn;
	menu_file<<nn<<" ";
	cout<<"enter the small cost"<<endl;
	cin>>sc;
	menu_file<<sc<<" ";
	cout<<"enter the medium cost"<<endl;
	cin>>mc;
	menu_file<<mc<<" ";
	cout<<"enter the large cost"<<endl;
	cin>>lc;
	menu_file<<lc<<" ";
	cout<<"enter the number of ingredients"<<endl;
	cin>>nume;
	for (int i =0;i<nume;i++){
		cout<<"enter ingredient"<<endl;
		cin>>ingo;
		menu_file<<ingo<<" ";
	}
menu_file.close();
}

/********************************************************************
** function:deconstructor
** description:deletes the employees and week array
** parameters:none
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Restaurant::~Restaurant(){
	delete[] employees;
	delete[] week;
	
}
