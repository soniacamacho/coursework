#include "playerheaders.h"
#include "househeaders.h"
#include "apheaders.h"
#include "businessheaders.h"
#include "propertyheaders.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
	
	srand (time(NULL));
	cout<<"****************************************************************************"<<endl;
	cout<<"************************ WELCOME TO PROPERTY TYCOON ************************ "<<endl;
	cout<<"****************************************************************************"<<endl;
	
    Player player; 
    cout<<"Players Balance: "<<player.get_money()<<endl;
    cout<<"Players Properites: 0"<<endl;
    while (player.get_game_over() == false){
    	
    	player.turn_funcs();
    	
    	player.set_turn(player.get_turn()+ 1);
    	cout<<"money: "<<player.get_money()<<endl;
    	cout<<"**********************************************************"<<endl;

	}
	
    //Property prop;
    
return 0;
}
                               
