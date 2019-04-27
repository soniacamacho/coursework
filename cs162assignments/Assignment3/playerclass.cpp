#include "playerheaders.h"
#include <stdlib.h>
using namespace std;

/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Player::Player(){
	num_house =0;
	money = 500000;
	turn =1;
	tax=0;
    rents=0;
   
    numapart =0;
    num_b = 0;
        

	houses = NULL;
	apartments = NULL;
	business = NULL;

	house_op = new House[3];
	business_op = new Busi[3];
	apartments_op = new Apart[3];

}
/*       
Player::Player(int num, int numa, int nb,int m , int t,House* home, Apart* a,Busi* b){
	num_house = num;
	numapart = numa;
	num_b = nb;
	money = m;
	turn =t;
	home = new House[num_house];
	for (int i =0;i< num_house;i++){
		houses[i]=home[i];
	}
	a = new Apart[numapart];
	for (int i =0;i <numapart;i++){
		apartments[i] = a[i];
	}
	b=new Busi[num_b];
	for(int i =0; i < num_b;i++){
		business[i] = b[i];
	}
}       
*/
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Player::Player(const Player& copy){
	num_house = copy.num_house;
	//houses= copy.houses;
	if (houses ==0){
		houses = NULL;
	}
	else { 
		houses = new House[num_house];
		for (int i =0;i<num_house;i++){
				houses[i] = copy.houses[i];
		}
	}

	numapart = copy.numapart;
	if (apartments == 0){
		apartments = NULL;
	}
	else{
		apartments = new Apart[numapart];
		for (int i =0; i< numapart;i++){
			apartments[i] = copy.apartments[i];
		}
	}

	num_b = copy.num_b;
	if(business == 0){
		business = NULL;
	}
	else{
		business = new Busi[num_b];
		for (int i =0; i < num_b;i++)
			business[i]=copy.business[i];
		}
	}


		/*house_op = new House[3];
		apartments_op = new Apart[3];
		business_op = new Busi[3];
		*/
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
const Player& Player:: operator=(const Player&  copy){
	num_house = copy.num_house;
	//houses = copy.houses;
	if (houses != NULL)
		delete []houses;
	if (num_house ==0)
		houses = NULL;
	else { 
		houses = new House[num_house];
		for (int i =0;i<num_house;i++){
				houses[i] = copy.houses[i];
		}
	}

	numapart = copy.numapart;
	if (apartments != NULL)
		delete[] apartments;
	if (numapart == 0)
		apartments =NULL;
	else{
		apartments = new Apart[numapart];
		for (int i=0;i < numapart;i++){
			apartments[i] = copy.apartments[i];
		}
	}


	num_b = copy.num_b;
	if(business != NULL)
		delete[] business;
	if (num_b == 0)
		business == NULL;
	else{
		business = new Busi[num_b];
		for (int i =0; i < num_b;i++){
			business[i] = copy.business[i];
		}
	}
	return *this;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Player::~Player(){
	delete [] houses;
	delete [] apartments;
	delete [] business;
	delete [] house_op;
	delete [] apartments_op;
	delete [] business_op;
}


//accessors 
int Player :: get_num_houses()const{return num_house;}
int Player :: get_numapart()const{return numapart;}
int Player :: get_money()const{return money;}
int Player :: get_turn()const{return turn;}
House Player::get_house(int i)const{return houses[i];}
//mutators
void Player::set_num_houses(int num){num_house=num;}
void Player::set_numapart(int numa){numapart=numa;}
void Player::set_money(int m){money = m;}
void Player::set_turn(int t){turn =t;}
void Player::set_houses(int num, House* home){
	for (int i=0;i<num;i++){
		houses[i]=home[i];
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool Player::is_int(string num){
    for (int i=0;i<num.length();i++){
        if (num[i]<'0' or num[i]>'9'){
            return false;
        }
    }   
    return true;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
int Player::get_int(string prompt){
    string t;
    bool in = false;

    cout<<prompt<<endl;
    while (in == false){
        getline(cin, t);
        in = is_int(t);
        if(in == false){
            cout<<"bad input try again."<<endl;
        }
    }
    int var=0;
    int exp=0;
    for(int i= t.length()-1; i>=0 ; i--){
        var+=(((int)t[i])-48)*pow(10,exp);
        exp++;
    }

return var;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::set_apart(int numapart, Apart* a){
	for (int i =0;i < numapart;i++){
		apartments[i] = a[i];
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool Player::get_game_over(){
	if (money < 0 || money >= 1000000){
		if (money < 0){
			cout<<"YOU LOSE!"<<endl;
			return true;
		}
		else{
			cout<<"YOU WIN!"<<endl;
			return true;
		}
	}
return false;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::print_ops(House& ho, Busi &bo, Apart& ao){
	cout<<"1"<<endl;
	cout<<"HOUSE:"<<endl;
	cout<<"Value: "<<ho.get_value()<<endl;
	cout<<"Mortgage: "<<ho.get_mor()<<endl;
	cout<<"Location: "<<ho.get_location()<<endl;

	cout<<endl;
	cout<<"2"<<endl;
	cout<<"BUSINESS:"<<endl;
	cout<<"Value: "<<bo.get_value()<<endl;
	cout<<"Mortgage: "<<bo.get_mor()<<endl;
	cout<<"Location: "<<bo.get_location()<<endl;
	cout<<"Number of Spaces: "<<bo.get_num_spaces()<<endl;

	cout<<endl;
	cout<<"3"<<endl;
	cout<<"APARTMENT:"<<endl;
	cout<<"Value: "<<ao.get_value()<<endl;
	cout<<"Mortgage: "<<ao.get_mor()<<endl;
	cout<<"Location: "<<ao.get_location()<<endl;
	cout<<"Number of Spaces: "<<ao.get_num_tenants()<<endl;

    cout<<endl;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::rand_ops(){
	int housenumber = rand () % 3;
	int businessnumber = rand () % 3;
	int apartmentnumber = rand ()%3;

	//print_ops(house_op[housenumber],business_op[businessnumber], apartments_op[apartmentnumber]);
	buy_prop(housenumber,businessnumber,apartmentnumber);
}

/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
House* Player::resize_house(House house_op, House* house, int numh){
	House* temp = new House[numh+1];
	for(int i= 0; i < numh;i++){
		temp[i] = house[i];
	}
	temp[numh] = house_op;
	delete[] house;
	house = temp;
	return house;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Busi* Player::resize_busi(Busi business_op, Busi* business, int num_b){
	Busi* temp = new Busi[num_b+1];
	for(int i= 0; i < num_b;i++){
		temp[i] = business[i];
	}
	temp[num_b] = business_op;
	delete[] business;
	business = temp;
	return business;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Apart* Player::resize_ap(Apart apartments_op, Apart* apartments, int numapart){
	Apart* temp = new Apart[numapart+1];
	for(int i= 0; i < numapart;i++){
		temp[i] = apartments[i];
	}
	temp[numapart] = apartments_op;
	delete[] apartments;
	apartments = temp;
	return apartments;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::print_ava(House& h, Busi& b, Apart& a){
	cout<<"1"<<endl;
	cout<<"HOUSE:"<<endl;
	cout<<"Value: "<<h.get_value()<<endl;
	cout<<"Mortgage: "<<h.get_mor()<<endl;
	cout<<"Location: "<<h.get_location()<<endl;
	cout<<endl;
	cout<<"2"<<endl;
	cout<<"BUSINESS:"<<endl;
	cout<<"Value: "<<b.get_value()<<endl;
	cout<<"Mortgage: "<<b.get_mor()<<endl;
	cout<<"Location: "<<b.get_location()<<endl;
	cout<<"Number of Spaces: "<<b.get_num_spaces()<<endl;

	cout<<endl;
	cout<<"3"<<endl;
	cout<<"APARTMENT:"<<endl;
	cout<<"Value: "<<a.get_value()<<endl;
	cout<<"Mortgage: "<<a.get_mor()<<endl;
	cout<<"Location: "<<a.get_location()<<endl;
	cout<<"Number of Spaces: "<<a.get_num_tenants()<<endl;

    cout<<endl;
}

/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/


void Player::buy_prop(int housenumber, int businessnumber, int apartmentnumber){
	string choice;
	print_ava(house_op[housenumber],business_op[businessnumber],apartments_op[apartmentnumber]);
	cout<<"what property would you like to purchase [1] house [2] business [3] apartment [4] for none "<<endl;
	cin.ignore();
	cin.clear();
	getline(cin,choice);
	
	if (choice == "1"){
		cout<<"You Purchased House"<<endl;
		house_op[housenumber].set_rent();
		houses = resize_house(house_op[housenumber],houses,num_house);
		num_house ++;
		House h;
		house_op[housenumber] = h;

	}
	if(choice == "2"){
		cout<<"You Purchased Businnes"<<endl;
		business_op[businessnumber].set_rent();
		business = resize_busi(business_op[businessnumber],business,num_b);
		num_b ++;
		Busi bu;
		business_op[businessnumber] = bu;

	}
	if (choice == "3"){
		cout<<"You Purchased Apartment"<<endl;
		apartments_op[apartmentnumber].set_rent();
		apartments = resize_ap(apartments_op[apartmentnumber],apartments,numapart);
		numapart ++;
		Apart ap; 
		apartments_op[apartmentnumber] = ap;
	}
	if (choice == "4"){cout<<"none Purchased"<<endl;}

}

/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::hurricane(){
	for (int i =0; i < num_house;i++){
			if (houses[i].get_location() == "SE" ){
				houses[i].set_value( houses[i].get_value() * 0.5);
			}
		}
		for (int i =0; i < numapart;i++){
			if (apartments[i].get_location() == "SE"){
				apartments[i].set_value( apartments[i].get_value() * 0.5);
			}
		}
		for (int i =0; i < num_b ; i++){
			if (business[i].get_location() == "SE"){
				business[i].set_value( business[i].get_value() * 0.5);
			}
		}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::tornado(){
	for (int i =0; i < num_house;i++){
			if (houses[i].get_location() == "Midwest" ){
				houses[i].set_value( houses[i].get_value() * 0.7);
			}
		}
		for (int i =0; i < numapart;i++){
			if (apartments[i].get_location() == "Midwest"){
				apartments[i].set_value(apartments[i].get_value() * 0.7);
			}
		}
		for (int i =0; i < num_b ; i++){
			if (business[i].get_location() == "Midwest"){
				business[i].set_value(business[i].get_value() *0.7);
			}
		}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::earthquake(){
	for (int i =0; i < num_house;i++){
			if (houses[i].get_location() == "NW" ){
				houses[i].set_value(houses[i].get_value() * 0.9);
			}
		}
		for (int i =0; i < numapart;i++){
			if (apartments[i].get_location() == "NW"){
				apartments[i].set_value(apartments[i].get_value() * 0.9);
			}
		}
		for (int i =0; i < num_b ; i++){
			if (business[i].get_location() == "NW"){
				business[i].set_value(business[i].get_value() *0.9);
			}
		}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::wildfire(){
	for (int i =0; i < num_house;i++){
			if (houses[i].get_location() == "SW" ){
				houses[i].set_value(houses[i].get_value() * 0.75);
			}
		}
		for (int i =0; i < numapart;i++){
			if (apartments[i].get_location() == "SW"){
				apartments[i].set_value(apartments[i].get_value() * 0.75);
			}
		}
		for (int i =0; i < num_b ; i++){
			if (business[i].get_location() == "SW"){
				business[i].set_value(business[i].get_value() * 0.75);
			}
		}

}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::stock_crash(){
	for (int i =0; i < num_house;i++){
			houses[i].set_value(houses[i].get_value() * 0.7);
		}
		for (int i =0;i < numapart ; i++){
			apartments[i].set_value(apartments[i].get_value() * 0.7);
			
		}
		for (int i =0;i < num_b ; i++){
			business[i].set_value(business[i].get_value() * 0.7);
		}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::gentrefication(string str){
	for (int i =0; i < num_house;i++){
		if (houses[i].get_location() == str){
			houses[i].set_value(houses[i].get_value() * 1.2);
		}
	}
	for (int i =0;i < numapart ; i++){
		if (apartments[i].get_location() == str){
			apartments[i].set_value(apartments[i].get_value() * 1.2);
		}
	}
	for (int i =0;i < num_b ; i++){
		if (business[i].get_location() == str){
			business[i].set_value(business[i].get_value() * 0.7);
		}
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player :: rand_events(){


	int event = rand () % 6 +1;

	//hurricane
	if (event == 1){
		cout<<"Hurricane"<<endl;
		hurricane();
	}
	//tornado
	if(event == 2){
		cout<<"Tornado"<<endl;
		tornado();
	}
	//earthquake
	if(event == 3){
		cout<<"Earthquake"<<endl;
		earthquake();
	}
	//wildfire
	if(event == 4){
		cout<<"Wildfire"<<endl;
		wildfire();
	}
	//stock crash
	if (event == 5){
		cout<<"Stock Crash"<<endl;
		stock_crash();
	}
	//gentrefication
	if (event == 6){
		int gen_loc = rand ()%6+1;

		if (gen_loc == 1){
			cout<<"gentrefication in the SE"<<endl;
			gentrefication("SE");
		}
		if (gen_loc == 2){
			cout<<"gentrefication in the NE"<<endl;
			gentrefication("NE");
		}
		if (gen_loc == 3){
			cout<<"gentrefication in the Midwest"<<endl;
			gentrefication("Midwest");
		}
		if (gen_loc == 4){
			cout<<"gentrefication in the SW"<<endl;
			gentrefication("SW");
		}
		if (gen_loc == 5){
			cout<<"gentrefication in the NW"<<endl;
			gentrefication("NW");
		}
		
	}
}


/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/

void Player::collecting_rents(){

	for (int i =0; i < num_house;i++){
		rents += houses[i].collect_rent();
	}

	for (int i =0;i < numapart; i++){
		rents += apartments[i].collect_rent();
	}
	
	for (int i =0; i < num_b;i++){
		rents += business[i].collect_rent();
	}

money += rents;
}

/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::pay_mortgage(){
	int total;
	
		for (int i=0; i< num_house;i++){
			houses[i].pay_mortgage();
			total = houses[i].pay_mortgage();
		}
		for(int i =0; i < num_b;i++){
			business[i].pay_mortgage();
			total = business[i].pay_mortgage();
		}
		for(int i =0 ;i < numapart;i++){
			apartments[i].pay_mortgage();
			total = apartments[i].pay_mortgage();
		}
	
	money -= total;
	cout<<"Mortgage payed: "<<money<<endl;
}

/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player :: pay_tax(){

	for (int i =0; i < num_house;i++){
		tax += houses[i].get_value() * 0.015;
	}
	for (int i =0; i < num_b;i++){
		tax += business[i].get_value() * 0.015;
	}
	for (int i =0; i < numapart; i++){
		tax += apartments[i].get_value() * 0.015;
	}

	money -= tax;
	cout<<"Tax payed: "<<money<<endl;
	change_rents();
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player:: change_rents(){
    int choi;
    int newrent;
	cout<<"Would you like to change the rents?"<<endl;
	cout<<"[1] yes [2] no"<<endl;

	cin>>choi;
	if (choi ==1){
		cout<<"Enter a rent"<<endl;
		cin>>newrent;
		cin.ignore();
		cin.clear();
		cout<<"rent changed to: "<<newrent<<endl;
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/

void Player:: sell_props(){
	cout<<"what house would you like to sell?"<<endl;



}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Player::turn_funcs(){
    rand_ops();
    rand_events();

    collecting_rents();
    pay_mortgage();
    pay_tax();
    //change_rents();
    
    
	
    //buy_prop();
	//money = money+1;
	
}
















                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
