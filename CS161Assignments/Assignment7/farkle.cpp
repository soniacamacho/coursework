#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
using namespace std;

/********************************************************************
** function:is_int
** description:checks a string to see if it is an integer
** Parameters:string num
** Pre-Conditions:num must be a string
** Post-Conditions:boolean return
*********************************************************************/
bool is_int(string players){
    for (int i=0;i<players.length();i++){
        if (players[i]<'0' or players[i]>'9'){
            return false;
        }
    }   
    return true;
}
/******************************************************************
** function:get int 
** description:takes a prompt then gets user input to find int
** Parameters:string prompt
** Pre-Conditions:must be string
** Post-Conditions:integer return
*********************************************************************/ 
int get_int(string players){
    bool in = false;
    while (in == false){
        in = is_int(players);
            if(in == false){
                cout<<"bad input try again."<<endl;
            }   
    }
    int var=0;
    int exp=0;
    for(int i= 0; i <  players.length() ; i++){
        var+=(((int)players[i])-48)*pow(10,exp);
        exp++;
    }

return var;
}
/****************************************************************
** function:amount_of_players
** description:this function will take in user input and return the amount of players playing
** Parameters:none
** Pre-Conditions:must be above 2 players
** Post-Conditions: the amount must be 2 numbers 
*********************************************************************/
int amount_of_players(){
    string players = "";
    int number_players = 0;
    while (is_int(players) == false or (get_int(players) < 2)){
        cout<<"Enter how many players you would like"<<endl;
        getline (cin , players);
            if (number_players < 2){
                cout<<"You must enter more than one player"<<endl;
            }
    } 
    number_players = get_int(players);    
return number_players;
}
/*************************************************************************************
** function:game_going
** description:this function check the score to see if it has hit 1000 and if it has game is over
** Parameters:the score and the length
** Pre-Conditions:the score must be below or above
** Post-Conditions: bool return type for game going
*********************************************************************/
bool game_going(int *score, int number_players ){
    for (int i = 0; i < number_players; i++){
        if (score[number_players] >= 10000){
            return false;
        }
    }
return true;
}
/*******************************************************************
** function: print_score
** description:this function will print out the score for each given player
** Parameters:score and the length of the array
** Pre-Conditions:must be scores
** Post-Conditions:returned scores 
*********************************************************************/
void print_score(int *score, int number_players){
    cout << "Scores: \n";
    for(int i = 0; i < number_players; i++){
        cout << "Player " << i+1 << ": " << score[i] << "\n";    
    }
} 
/****************************************************************** 
** function:dice_roll
** description:this gets 6 random values for the dice
** Parameters:the roll array 
** Pre-Conditions:the dice 
** Post-Conditions:the random face values
*********************************************************************/
void dice_roll(int *roll, int number){
    for (int i = 0 ; i < number ; i++){
            roll[i] = 1 + rand() % 6;
            cout<<"Die "<< i + 1 <<": "<<roll[i]<<endl;
    }
}
/*******************************************************************
** function:sort_roll
** description:this function sorts the roll array into the amount of times a face value occurs
** Parameters:roll and amountroll array 
** Pre-Conditions:must be those arrays
** Post-Conditions:returns the sorted array of values 
*********************************************************************/
void sort_roll(int *roll, int *sortedRoll){
    for(int i = 0; i < 6; i++){
        for (int j = 0; j < 6 ; j++){
            if( roll[j] == i+1){
                sortedRoll[i] = sortedRoll[i] +1 ;
            }
        }
    }
}
/**************************************************************************
** function:is_valid
** description:this checks to see if the choice is valid
** parameters:the choice and the counter
** pre-conditions:must be valid number
** post-conditions:will error handle
*********************************************************************/
bool is_valid(string choice){
    for (int i = 0; i < choice.length(); i++){
        if ((choice[i] != 1) or (choice[i] != 2)){
            return false;
        }
    }
return true;
}
/******************************************************************************
** function:choice
** description:return the choice
** Parameters:string prompt
** Pre-Conditions:must be a string
** Post-Conditions: return choice
*********************************************************************/
bool choice(string prompt){
    string choice ="";
    while ((is_int(choice) == false) or ((get_int(choice)) == false)){
        cout<<"Would like a "<<prompt<<endl;
        cout<<" [1] yes [2] no"<<endl;
        cin.ignore();
        getline( cin, choice);
    }
    if (is_valid(choice) == 1){
        return true;
    }
    else {
        return false;
    }   
}
/******************************************************************
** function:six_of_a_kind
** description:this will check for six of a kind
** Parameters:takes in the sorted roll
** Pre-Conditions:looks for 6s
** Post-Conditions: if there are return score of that
*********************************************************************/
int six_of_a_kind(){
    string prompt = "six of a kind?";
    if (choice(prompt)){
        return 3000;
    }      
    return 0;
}
/***************************************************************************
** function:five_of_a_kind
** description:this will check to see if there is a five of a kind
** Parameters:none
** Pre-Conditions:must be a five of a kind
** Post-Conditions: will return score of that
*********************************************************************/
int five_of_a_kind(){
    string prompt = "five of a kind?";
    if (choice(prompt)){
        return 2000;
    }      
    return 0;
}
/***************************************************************************
** function:four_of_a_kind
** description:will return the score if they choose a four of a kind
** Parameters:none
** Pre-Conditions:must be a four
** Post-Conditions: returned score
*********************************************************************/
int four_of_a_kind(){
    string prompt = "four of a kind?";
    if (choice(prompt)){
        return 1000 ;
    }      
    return 0;
}
/**********************************************************************
** function:int_straight
** description:this will check the sorted array for a straight 
** Parameters:sorted roll
** Pre-Conditions:must have a one in each index
** Post-Conditions: return the score if there is 
*********************************************************************/
int straight(){
    string prompt = "straight?";
    if (choice(prompt)){
        return 1500 ;
    }      
    return 0;
}
/***********************************************************************
** function:three_paris
** description:this checks for if there are three pairs 
** Parameters:the sorted array 
** Pre-Conditions:must have 3 pairs 
** Post-Conditions: returns the 1500 points 
*********************************************************************/
int three_pairs(){
    string prompt = "three pairs?";
    if (choice(prompt)){
        return 1500 ;
    }      
    return 0;
}
/*************************************************************************
** function:two_tropples
** description:this will look for two sets of tripples 
** Parameters:the sorted array 
** Pre-Conditions:must be 2 of 3 in the sorted array
** Post-Conditions: returns the score
*********************************************************************/
int two_tripples(){
    string prompt = "two triples?";
    if (choice(prompt)){
        return 2500 ;
    }      
    return 0;
}
/***********************************************************************
** function:four_and_a_pair
** description:this function checks for four of one kind and a pair of another
** Parameters:the sorted array
** Pre-Conditions:must have 4 and a 2 somewhere in sorted array 
** Post-Conditions: will return score 
*********************************************************************/
int four_and_a_pair(){
    string prompt = "four and a pair?";
    if (choice(prompt)){
        return 1500 ;
    }      
    return 0;
}
/*************************************************************************
** function:three_of_a_kind
** description:goes throught the sorted array and looks for a three of any number
** Parameters:the number of the dice
** Pre-Conditions:the sorted array must have a 3
** Post-Conditions: the score will be number times 100
*********************************************************************/
int three_of_a_kind(int *sortedRoll){
    string prompt = "three of a kind?";
    if (choice(prompt)){
        if (sortedRoll[0] == 3){
            return 300;
        }
        for (int i = 1 ; i < 6 ; i++){
            if (sortedRoll[i] == 3){
                return i * 100;
            }
        }
    }
    else { 
        return 0;
    }
}
/************************************************************************
** function: one_one
** description:will check for one , one
** Parameters:none
** Pre-Conditions:must have one one
** Post-Conditions: return score of 100
*********************************************************************/
int one_one(){
    string prompt = "single one?";
    if (choice(prompt)){
           return 100;
    }  
    return 0;
    
}
/************************************************************************
** function:one_five 
** description:checks to see if there is 1 five 
** Parameters:none
** Pre-Conditions:one five must be there 
** Post-Conditions: returns the five
*********************************************************************/
int one_five(){
    string prompt = "single five?";
    if (choice(prompt)){
           return 50;
    }  
    return 0;
}
/***********************************************************************
** function:farkle_roll
** description:this checks for a roll that has no value
** Parameters:the sorted roll
** Pre-Conditions:must have no 1 or 5 or scoring values 
** Post-Conditions: return farkle roll
*********************************************************************/
bool farkle_roll(int *roll){
    int one = 0;
    int five = 0;   
    int morethanthree;
        for (int i =0; i < 6 ; i++){    
            if (roll[i] == 1){
                one = one +1;
            }
            if (roll[i] == 5){
                five = five +1;
            }
        }
        if ((one > 0) or (five > 0)){
            return false;
        }
        for (int i =0; i < 6; i++){
            if (roll[i] > 2){
                morethanthree = morethanthree +1;
            }
    
            if (morethanthree > 0){
                return false;
            }
        }
    cout<<"Farkle roll"<<endl;
return true;
}

/******************************************************************************
** function:get_score
** description:return the score
** Parameters:score  
** Pre-Conditions:must be a score
** Post-Conditions: return score
*********************************************************************/
int get_scores(int *sortedRoll){
int score =0;
        if (sortedRoll[0] > 0){
            score += one_one();
        }
        if (sortedRoll[1] == 3){
            score += three_of_a_kind(sortedRoll);
        }
        if (sortedRoll[1] == 4){
            score += four_of_a_kind();
        }
        if (sortedRoll[1] == 5){
            score += five_of_a_kind();
        }
        if (sortedRoll[1] == 6){
            score += six_of_a_kind();
        }        
        /*if (amountRoll[3] > 2){
            score[currentPlayer] += check_four(amountRoll);
        }
        if (amountRoll[4] > 0){
            score[currentPlayer] += check_five(amountRoll);
        }
        if (amountRoll[5] > 2){
            score[currentPlayer] += check_six(amountRoll);
        }
       
       */

    /*int score = 0 ;
    int singles = 0;
    int pairs = 0;
    int tripples = 0;
    int fours = 0;
    int fives = 0;
    int sixs = 0;
    for (int i = 0; i < 6 ; i ++ ){
        if (sortedRoll[i] == 1){
            singles ++ ;
        }
        if (sortedRoll[i] == 2){
            pairs ++ ;
        }
        if (sortedRoll[i] == 3){
            tripples ++;
       }
        if (sortedRoll[i] == 4){
            fours ++;
       }
        if (sortedRoll[i] == 5){
            fives ++;
       }
        if (sortedRoll[i] == 6){
            sixs ++;
       }
    }
    cout<<singles<<pairs<<tripples<<fours<<fives<<sixs<<endl;
    if (farkle_roll(roll) == true){
        score = score + 0;
    }
    
    for (int i = 0 ; i < sortedRoll[0] ; i++ ){
        score = score + one_one();
    }
    //for (int i = 0; i < sortedRoll[4] ; i++ ){
      if (sortedRoll[4] == 1){
          score = score + one_five();
    }
    if (singles == 6){
        score = score + straight();
    }
    if (pairs == 3){
        score = score + three_pairs(); 
    }
    if (tripples == 2){
        score = score + two_tripples();
    }
    if (fours == 1){
        score = score + four_of_a_kind();
    }
    if (fives == 1){
        score = score + five_of_a_kind(); 
    }
    if (sixs ==  1){
        score = score + six_of_a_kind(); 
    }
    if ((pairs == 1) and (fours == 1)){
        score = score + four_and_a_pair();
    }
    if (tripples == 1){
        score += three_of_a_kind(sortedRoll);  
    }
*/
return score;
}
/*************************************************************
** function:roll_again
** description:this gets 6 random values for the dice
** Parameters:the roll array 
** Pre-Conditions:the dice 
** Post-Conditions:the random face values
*********************************************************************/
bool roll_again(int number){
    string prompt = "to roll again?";
    if (choice(prompt)){
           return true; 
    }  
    return false;
}
/*******************************************************************
** function:players turn 
** description:this function handles it all it goes for every persons turn 
** Parameters:the score the length and the current player
** Pre-Conditions:must be the players turn 
** Post-Conditions:will return the score for the players turn 
*********************************************************************/
void players_turn(int *score , int current_player){
    int roll[6] ;
    int sortedRoll[6] = {0,0,0,0,0,0};
    int number = 6;
    dice_roll(roll, number);
    sort_roll(roll, sortedRoll); 
    cout<<"**************************************"<<endl;
    //get_scores(sortedRoll, roll);
    score[current_player] = get_scores(sortedRoll);
    cout<<score[current_player]<<endl;
    if(roll_again(number) == true ){
        dice_roll(roll , number);
    }
    cout<<endl;

}          
/*********************************************************************/
int main(){
    int game_over = false;
    int number_players = amount_of_players();
    cout<<"There are " <<number_players<<" Players"<<endl;
    int *score = new int [number_players];
    while ( game_over == false){
        for (int i = 0; i < number_players ; i++ ){
            print_score(score , number_players ); 
            cout<<"**************************************"<<endl;
            cout<<"********** Player "<< i+1 <<" Turn *************"<<endl;
            cout<<endl;
            players_turn(score,i);
        //cout<<"hello"<<endl;   
        }
    }
        if (game_going(score , number_players) == false){
            game_over = true;
        }  
       


    delete [] score;
return 0;
}
