#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#include <iostream>
#include <vector>
#include "board.h"
#include "ant.h"
#include "bee.h"
using namespace std;
Ant a;
Harvester h;
Thrower t;
Fire f;
Long_Thrower lt;
Short_Thrower st;
Wall w;
Ninja n;
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
Board::Board(){
	
    bank = 50;
    turn =1;
    //Insect* bee = new Bee[11];
    
	for (int i =0; i <11;i++){
		ants[i] = new Ant;
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board::welcome(){
	cout<<"***************************************"<<endl;
	cout<<"********** ANTS VS SOME BEES **********"<<endl;
	cout<<"***************************************"<<endl;
	cout<<endl;
	cout<<endl;
	
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board :: print_ant_key(){
	cout<<"********** ANT KEY **********"<<endl;
	cout<<"|     NAME       |COST|ARMOR|"<<endl;
	cout<<"|___________________________|"<<endl;
	cout<<"|1  Harvester    | 2  |  1  |"<<endl;
	cout<<"|2  Thrower      | 4  |  1  |"<<endl;
	cout<<"|3  Fire         | 4  |  1  |"<<endl;
	cout<<"|4  Long Thrower | 3  |  1  |"<<endl;
	cout<<"|5  Short Thrower| 3  |  1  |"<<endl;
	cout<<"|6  Wall         | 4  |  4  |"<<endl;
	cout<<"|7  Ninja        | 6  |  1  |"<<endl;
	cout<<"|8  Bodyguard    | 4  |  2  |"<<endl;
	cout<<"*****************************"<<endl;
	cout<<endl;
	cout<<endl;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/

void Board:: generate_bee(){
	
	Bee bee;
	bugs[10].push_back(bee);
	
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board::bees_move(){
	int count;
	for(int i =1; i < 11;i++){
		for(int j = 0; j< bugs[i].size() ;j++){
			//cout << "bugs[10].size()\n";
			if(ants[i]->get_type() == "_" || ants[i]->get_type() == "N"){
				if(ants[i]->get_type() == "N"){
					for( int j = 0; j < bugs[i].size();j++){
					int mur = bugs[i][j].get_armor()-1;
					bugs[i][j].set_armor(mur);
					cout<<"Bee passed a Ninja, Bees new Armor: "<<bugs[i][j].get_armor()<<endl;
					}
					//del_bee();
				}
				if(ants[i]->get_type() == "_"){
					//del_bee();
					bugs[i-1].push_back(bugs[i][j]);
					bugs[i].erase(bugs[i].begin()+j);

				}
				//cout << "ants[10].type()\n";
				//bugs[i-1].push_back(bugs[i][j]);
				//count++;
				//cout << "push_back(bugs[10][1])\n";
				//bugs[i].erase(bugs[i].begin()+j);
				//cout << "erase bugs[10][1]\n";

			}
			else{
			cout<<endl;
			cout<<"BEE ATTACKS!"<<endl;

				if (ants[i]->get_type() == "F"){
					cout<<"Death of fire ant will inflict damage to bees armor to 0"<<endl;
					for( int j = 0; j < bugs[i].size();j++){
						int mur = 0;
						bugs[i][j].set_armor(mur);
						cout<<"Bees new armor: "<<bugs[i][j].get_armor()<<endl;	
					}
					//del_bee();
				}
			
				int arm = ants[i]->get_armor()-1;
				ants[i]->set_armor(arm);
				cout<<ants[i]->get_type()<<" new armor: "<<arm<<endl;

				if ( ants[i]->get_armor() == 0){
					ants[i] = new Ant;
				}
				
			}
			//bugs[i].pop_back();	
		
		}	
		//cout<<count<<endl;
		
		//del_bee();
	
	/*for(int k =0; k < bugs[i].size();k ++){
		if (bugs[i][k].get_armor() <= 0)
			bugs[i].pop_back();
	}*/

			//bugs[i].push_back(bugs[i][k]);
	//}

}
del_bee();
}
	
	//del_bee();

/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board:: ants_attack(){
	for (int i=0; i < 11;i ++){
		if( ants[i]->get_type() == "H"){
			cout<<"Harvester added 1 to food bank: ";
			if (ants[i]->get_armor() > 0){
				bank +=1;
			}
			cout<<bank<<endl;
		}
		//del_bee();
	}
	for (int i=0; i < 11;i ++){
		if(ants[i]->get_type() == "T"){
			if(bugs[i].size()> 0){
				cout<<"Thrower damages bee by 1 armor"<<endl;
				for( int j = 0; j < bugs[i].size();j++){
					//int mur = bugs[i][j].get_armor()-1;
					bugs[i][j].set_armor(bugs[i][j].get_armor()-1);
					cout<<"Bees new armor: "<<bugs[i][j].get_armor()<<endl;
			
				}
			}
		}
	}
	for (int i=0; i < 11;i ++){
		if (ants[i]->get_type() == "LT"){
			if( i <= 6){
				cout<<"Long Thrower damages bee by 1 armor 4 squares away"<<endl;
				for( int j = 0; j < bugs[i+4].size();j++){
					int mur = bugs[i+4][j].get_armor()-1;
					bugs[i+4][j].set_armor(mur);
					cout<<"Bees new armor: "<<bugs[i+4][j].get_armor()<<endl;
				}
			}
			
		}
	}
	for (int i=0; i < 11;i ++){
		if (ants[i]->get_type() == "ST"){
			if( i <= 8){
				cout<<"Short Thrower damages bee by 1 armor no more than 2 squares away"<<endl;
				for( int j = 0; j < bugs[i+2].size();j++){
					if (bugs[i+2][j].get_type() == "b"){
						int mur = bugs[i+2][j].get_armor()-1;
						bugs[i+2][j].set_armor(mur);
						cout<<"Bees new armor: "<<bugs[i+2][j].get_armor()<<endl;
					}
				}
			}
			
		}
	}
		

del_bee();
	}


/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board::del_bee(){
	for (int i=1; i < 11;i ++){
		for( int j = bugs[i].size() -1; j >= 0; j--){
			if (bugs[i][j].get_armor() == 0){
				//cout<<"bee dead"<<" "<<i<<" "<<j<<" "<<endl;
				bugs[i].erase(bugs[i].begin()+j);
			}
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
void Board :: print(){
	//Insect* bee = new Bee;
	
        cout<<'Q'<<" "<<"|";
    
	for (int k =1 ; k < 11 ; k++){
		cout<< ants[k]->get_type();
		for( int j = 0; j < bugs[k].size();j++){
			cout<<bugs[k][j].get_type();
			cout<<bugs[k][j].get_armor();
		}
		cout<<"|";
	}
		
		cout<<endl;
}
	





/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/

bool Board::is_int(string num){
	if(num.length() > 1){
		return false;
	}
    for (int i=0;i<num.length();i++){
        if (num[i]<'0' or num[i]>'8'){
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
int Board::get_int(string prompt){
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
bool Board::is_int_two(string num){
	

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
int Board::get_int_two(string prompt){
    string t;

    bool in = false;

    cout<<prompt<<endl;
    while (in == false){
        getline(cin, t);
        in = is_int_two(t);
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
void Board::badmessa(){
	cout<<"You dont have enough money to get this ant"<<endl;
	cout<<"Bank: "<<bank<<endl;
	cout<<endl;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void  Board::messa(int acost){

	cout<<"You have enough money for this ant "<<endl;
	bank -= acost;
	cout<<"Bank: "<<bank<<endl;
	cout<<endl;
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool Board:: check_h_cost(){
	    cout<<"Harvester ant "<<endl;
		int harvester_cost = a.two_dolla();
		if(bank < harvester_cost ){
			badmessa();
			return false;
		}
		else{
			messa(harvester_cost);
			return true;
		}	
}

/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool Board::tcost(){
	
		int thrower_cost = a.four_dolla();
		if(bank < thrower_cost ){
			badmessa();
			return false;
		}
		else{
			messa(thrower_cost);
			return true;
		}	
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool Board::threecost(){
	
		int antcost = a.three_dolla();
		if(bank < antcost ){
			badmessa();
			return false;
		}
		else{
			messa(antcost);
			return true;
		}	
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
bool Board::sixcost(){
	
		int antcost = a.six_dolla();
		if(bank < antcost ){
			badmessa();
			return false;
		}
		else{
			messa(antcost);
			return true;
		}	
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
int Board::get_ant_coord(){
	int spot;
	spot = get_int_two("What spot would you like to place this ant?");
	return spot;
}


/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board::set_new_h_ant(int cord){
	if(ants[cord]->get_type() == "_"){
		ants[cord] = new Harvester;
	}
	else{
		cout<<"You cant place another ant here"<<endl;
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board::set_new_t_ant(int cord){ 
	if(ants[cord]->get_type()== "_"){
		ants[cord] = new Thrower;
	} 
	else{
		cout<<"You cant place another ant here"<<endl;
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board::set_new_f_ant(int cord){ 
	if(ants[cord]->get_type()== "_"){
		ants[cord] = new Fire; 
	}
	else{
		cout<<"You cant place another ant here"<<endl;
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board::set_new_lt_ant(int cord){ 
	if(ants[cord]->get_type()== "_"){
		ants[cord] = new Long_Thrower;
	}
	else{
		cout<<"You cant place another ant here"<<endl;
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board::set_new_st_ant(int cord){ 
	if(ants[cord]->get_type()== "_"){
		ants[cord] = new Short_Thrower;
	}
	else{
		cout<<"You cant place another ant here"<<endl;
	}
}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board::set_new_w_ant(int cord){ 
	if(ants[cord]->get_type()== "_"){
		ants[cord] = new Wall; 
	}
	else{
		cout<<"You cant place another ant here"<<endl;
	}

}
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
void Board::set_new_n_ant(int cord){ 
	if(ants[cord]->get_type()== "_"){
		ants[cord] = new Ninja; 
	}
	else{
		cout<<"You cant place another ant here"<<endl;
	}
}

/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/

void Board :: getting_ant(){
	int coord;
	cout<<"Bank Account "<<bank<<endl;
	int antchoi = get_int("Input the number that corralates with the ant you would like to place ");
	if (antchoi == 1){
		//cout<<"h ant "<<endl;
		//cout<<h.get_type()<<endl;
		if (check_h_cost() == true){
			
			coord = get_ant_coord();
			set_new_h_ant(coord);
		}
		else{
			cout<<"will not place ant"<<endl;
		}
	}
	if (antchoi == 2){
		cout<<"Thrower ant"<<endl;
		if(tcost() == true){	
			coord = get_ant_coord();
			set_new_t_ant(coord);
		}
		else{
			cout<<"will not place ant"<<endl;
		}
	}
	if (antchoi == 3){
		cout<<"Fire ant"<<endl;
		if(tcost() == true){
			coord = get_ant_coord();
			set_new_f_ant(coord);
		}
		else{
			cout<<"will not place ant"<<endl;
		}
	}
	if (antchoi == 4){
		cout<<"Long Thrower ant "<<endl;
		if(threecost() == true){
			coord = get_ant_coord();
			set_new_lt_ant(coord);
		}
		else{
			cout<<"will not place ant"<<endl;
		}
	}
	/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/
	if (antchoi == 5){
		cout<<"Short Thrower ant "<<endl;
		if(threecost() == true){
			coord = get_ant_coord();
			set_new_st_ant(coord);
		}
		else{
			cout<<"will not place ant"<<endl;
		}
	}
	if (antchoi == 6){
		cout<<"Wall ant "<<endl;
		if(tcost() == true){
			coord = get_ant_coord();
			set_new_w_ant(coord);
		}
		else{
			cout<<"will not place ant"<<endl;
		}
	}
	if (antchoi == 7){
		cout<<"Ninja ant "<<endl;
		if(sixcost() == true){
			coord = get_ant_coord();
			set_new_n_ant(coord);
		}
		else{
			cout<<"will not place ant"<<endl;
		}
	}
	if (antchoi == 8){
		cout<<"Bodyguard ant "<<endl;
		if(tcost() == true){
			coord = get_ant_coord();
			int arm = ants[coord]->get_armor()+2;
			ants[coord]->set_armor(arm);
			cout<<ants[coord]->get_type()<<" Now Has a Bodyguard!"<<endl;
		}
		else{
			cout<<"will not place ant"<<endl;
		}
	}
}

int Board :: get_turn()const{return turn;}
void Board::set_turn(int t){turn =t;}



	
/********************************************************************
** function:funcs
** description:for the user this is the function calls
** parameters:sub op
** pre-conditions:none
** post-conditions:none
*********************************************************************/

bool Board::get_game_over(){	
	int counter=0;
	
	for(int j=1; j < 11; j++){
        for(int k =0; k < bugs[j].size();k++){
    		    if(bugs[j][k].get_type() == "b"){
                    //counter ++; 
                    return false;
                }
        }
    } 
 	

    cout<<"NO BEES YOU WIN"<<endl;
    return true;
}
    

Board :: ~ Board(){
	
	for(int i =0; i <11;i++){
	delete [] ants[i];
}

}
	

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              