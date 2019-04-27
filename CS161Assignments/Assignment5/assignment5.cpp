#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


/****************************************************************
** function:num_players
** description:this function will take in user input and return the amount of players playing
** Parameters:none
** Pre-Conditions:must be above 2 players
** Post-Conditions: the amount must be 2 numbers 
*********************************************************************/
int num_players(){
    int numpeople = 0;
    cout<<"Enter how many players you would like"<<endl;
    cin>>numpeople;
    cout<<endl;
    if (numpeople < 2){
            cout<<"You must enter more than one player"<<endl;
            cout<<"Enter how many players you would like"<<endl;
            cin>>numpeople;
            cout<<endl;  
    }     
    return numpeople;
}
/****************************************************************** 
** function:dice_roll
** description:this gets 6 random values for the dice
** Parameters:the roll array 
** Pre-Conditions:the dice 
** Post-Conditions:the random face values
*********************************************************************/
void dice_roll(int *roll){
    for (int i = 0; i < 6 ; i++){
        if(roll[i] != -1){
            roll[i] = 1 + rand() % 6;
            cout<<"Die "<< i + 1 <<": "<<roll[i]<<endl;
        }
    }
   
}
/*******************************************************************
** function:sort_roll
** description:this function sorts the roll array into the amount of times a face value occurs
** Parameters:roll and amountroll array 
** Pre-Conditions:must be those arrays
** Post-Conditions:returns the sorted array of values 
*********************************************************************/
void sort_roll(int *roll, int *amountRoll){
    for(int i = 0; i < 6; i++){
        for (int j = 0; j < 6 ; j++){
            if( roll[j] == i+1){
                amountRoll[i] = amountRoll[i] +1 ;
            }
        }
    }
}
/******************************************************************
** function: print_score
** description:this function will print out the score for each given player
** Parameters:score and the length of the array
** Pre-Conditions:must be scores
** Post-Conditions:returned scores 
*********************************************************************/
void print_score(int *score, int numpeople){
    cout << "Scores: \n";
    for(int i = 0; i < numpeople; i++){
        cout << "Player " << i+1 << ": " << score[i] << "\n";    
    }
}   
/**********************************************************************
** function:print_sorted 
** description:this will print out the sorted array the returns the face values 
** Parameters:the sorted array 
** Pre-Conditions:must be ints
** Post-Conditions: void return type but prints out
*********************************************************************/
void print_sorted(int *amountRoll){
    for(int i = 0;i < 6; i++){
        cout<<amountRoll[i];
    }
}
/*********************************************************************
** function:six_of_a_kind
** description:this will check for six of a kind
** Parameters:takes in the sorted roll
** Pre-Conditions:looks for 6s
** Post-Conditions: if there are return score of that
*********************************************************************/
int six_of_a_kind(int *amountRoll){
    for (int i = 0; i < 6 ; i++){
        if (amountRoll [i] == 6){
            return 3000;
        }
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
int straight(int *amountRoll){
    for(int i = 0; i < 6; i++){
        if (amountRoll [i] != 1){
            return 0;
        }
    }
return 1500;
}
/***********************************************************************
** function:three_paris
** description:this checks for if there are three pairs 
** Parameters:the sorted array 
** Pre-Conditions:must have 3 pairs 
** Post-Conditions: returns the 1500 points 
*********************************************************************/
int three_pairs(int *amountRoll){
int pairs =0;
    for (int i = 0; i < 6; i ++){
        if (amountRoll [i] == 2){
            pairs = pairs +1;
        }
    }
    if (pairs == 3){
        return 1500;
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
int four_and_pair(int *amountRoll){
int pairs = 0;
int fours = 0;
    for (int i = 0; i < 6; i ++){
        if (amountRoll [i] == 2){
            pairs = pairs +1;
        }
    }
    for (int i = 0; i < 6; i++){
        if (amountRoll [i] == 4){
            fours = fours +1;
        }
    }
    if (pairs == 1 and fours == 1){
        return 1500;
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
int two_tripples(int *amountRoll){
int tripples = 0;
    for (int i = 0; i < 6; i++){
        if (amountRoll [i] == 3){
            tripples = tripples + 1;
        }
    }
    if(tripples == 2){
        return 2500;
    }
}
/************************************************************************
** function:full_combos
** description:this will look for the full combos and assgin the score to that array
** Parameters:the sorted array
** Pre-Conditions:checks each function
** Post-Conditions: will return score with that value
*********************************************************************/
int full_combos(int *amountRoll){
int score = 0;
    score += six_of_a_kind(amountRoll);
    score += straight(amountRoll);
    score += three_pairs(amountRoll);
    score += four_and_pair(amountRoll);
    score += two_tripples(amountRoll);
return score;
}
/***********************************************************************
** function:farkle_roll
** description:this checks for a roll that has no value
** Parameters:the sorted roll
** Pre-Conditions:must have no 1 or 5 or scoring values 
** Post-Conditions: return farkle roll
*********************************************************************/
bool farkle_roll(int *amountRoll){
int one = 0;
int five = 0;   
int lessthree;
    for (int i =0; i < 6 ; i++){    
        if (amountRoll[i] == 1){
            one = one +1;
        }
        if (amountRoll[i] == 5){
            five = five +1;
        }
    }
    if ((one > 0) or (five > 0)){
        return false;
    }
    for (int i =0; i < 6; i++){
        if (amountRoll[i] > 2){
            lessthree = lessthree +1;
        }
    
        if (lessthree > 0){
            return false;
        }
    }
   cout<<"Farkle roll"<<endl;
return true;
}
/**************************************************************************
** function:is_valid
** description:this checks to see if the choice is valid
** parameters:the choice and the counter
** pre-conditions:must be valid number
** post-conditions:will error handle
*********************************************************************/
bool is_valid(int choice, int counter){
if (choice<'0' or choice>'9'){
    return false;
}
if(choice >= counter){
    return false;
}
if (choice < 1 ){
    return false;
}

return true;
}
/************************************************************************
** function: one_one
** description:will check for one , one
** Parameters:none
** Pre-Conditions:must have one one
** Post-Conditions: return score of 100
*********************************************************************/
int one_one(){
    return 100;
}
/*************************************************************************
** function:two_ones
** description:will check for two ones
** Parameters:none
** Pre-Conditions:must have 2 ones
** Post-Conditions: returned 200
*********************************************************************/
int two_one(){
    return 200;
}
/************************************************************************
** function:one_five 
** description:checks to see if there is 1 five 
** Parameters:none
** Pre-Conditions:one five must be there 
** Post-Conditions: returns the five
*********************************************************************/
int one_five(){
    return 50;
}
/*************************************************************************
** function:two_five
** description:will check for one five 
** Parameters:none
** Pre-Conditions:must have one five 
** Post-Conditions: return 100
*********************************************************************/
int two_five(){
    100;
}
/*************************************************************************
** function:three_of_a_kind
** description:goes throught the sorted array and looks for a three of any number
** Parameters:the number of the dice
** Pre-Conditions:the sorted array must have a 3
** Post-Conditions: the score will be number times 100
*********************************************************************/
int three_of_a_kind(int number){
    if (number == 1){
        return 300;
    }
    else {return (number * 100);
 }
}
/***************************************************************************
** function:four_of_a_kind
** description:will return the score if they choose a four of a kind
** Parameters:none
** Pre-Conditions:must be a four
** Post-Conditions: returned score
*********************************************************************/
int four_of_a_kind(){
    return 1000;
}
/***************************************************************************
** function:five_of_a_kind
** description:this will check to see if there is a five of a kind
** Parameters:none
** Pre-Conditions:must be a five of a kind
** Post-Conditions: will return score of that
*********************************************************************/
int five_of_a_kind(){
    return 2000;
}
/*************************************************************************
** function:six_of_a_kind
** description:returns the score of the six of a kind of any number
** Parameters:none
** Pre-Conditions:must be a six of a kind
** Post-Conditions: will return the score
*********************************************************************/
int six_of_a_kind(){
    return 3000;
}
/******************************************************************************
** function:check_one
** description:this will go through and check for the face value one
** Parameters:sorted array
** Pre-Conditions:must be face value of one
** Post-Conditions: will send it to a new function and get the score
*********************************************************************/
int check_one(int *amountRoll){
    int choice = 0;
    int number = 1;
    if (amountRoll[0] > 0){
    cout<<"You have "<<amountRoll[0]<<" dice with the face value of 1"<<endl;
    if (amountRoll[0] == 1){
        cout<<"would you like to keep this 1 ?"<<endl;
        cout<<"Press [1] for yes [2] for no"<<endl;
        cin>>choice;
        if (choice == 1){
            return one_one();
            amountRoll[0] = 0;
        }
        if(choice == 2){
            return 0;
            amountRoll[0] = 1;
        }
    }
    if (amountRoll[0] == 2){
        cout<<"would you like to keep both ones?"<<endl;
        cout<<"press[1] for yes [2] for no"<<endl;
        cin>>choice;
        if (choice == 1){
            return two_one();
            amountRoll[0] = 0;
        }
        if(choice == 2){
            return 0;
            amountRoll[0] = 2;
        }
    }
    if(amountRoll[0] == 3){
        cout<<"would you like a three of a kind?"<<endl;
        cout<<"press [1] for yes [2] for no"<<endl;
        cin>>choice;    
        if (choice == 1){
            return three_of_a_kind(number);
            amountRoll[0] = 0 ;
        }
        if (choice == 2){
            return 0;
            amountRoll[0] = 3;
        }
    }
    if (amountRoll[0] == 4){
        cout<<"would you like a four of a kind?"<<endl;
        cout<<"press [1] for yes [2] for no"<<endl;
        cin>>choice;
        if (choice == 1){
            return four_of_a_kind();
            amountRoll[0] = 0;
        }
        if (choice == 2){
            return 0;
            amountRoll[0] = 4;
        }
    }
    if (amountRoll[0] == 5){
        cout<<"would you like a five of a kind?"<<endl;
        cout<<"press [1] for yes [2] for no"<<endl;
        cin>>choice;
        if (choice == 1){
            return five_of_a_kind();
            amountRoll[0] = 0;
        }
        if (choice == 2){
            return 0;
            amountRoll[0] = 5;
        }
    }
    if (amountRoll[0] == 6){
        cout<<"would you like a six of a kind?"<<endl;
        cout<<"press [1] for yes [2] for no"<<endl;
        cin>>choice;
        if (choice == 1){
            return six_of_a_kind();
            amountRoll[0] = 0;
        }
        if (choice == 2){
            return 0;
            amountRoll[0] = 6;
        }
    }
 
 }
}
/***************************************************************************/
int check_five(int *amountRoll){
    int choice = 0;
    int number = 5;
    if (amountRoll[4] > 0){
    cout<<"You have "<<amountRoll[4]<<" dice with the face value of 5"<<endl;
    if (amountRoll[4] == 1){
        cout<<"would you like to keep this 5 ?"<<endl;
        cout<<"Press [1] for yes [2] for no"<<endl;
        cin>>choice;
        if (choice == 1){
        return one_five();
        }
        if(choice == 2){
        return 0;
        }
    }
    if (amountRoll[4] == 2){
        cout<<"would you like to keep both fives?"<<endl;
        cout<<"press[1] for yes [2] for no"<<endl;
        cin>>choice;
        if (choice == 1){
        return two_five();
        }
        if(choice == 2){
        return 0;
        }
    }
    if(amountRoll[4] == 3){
        cout<<"would you like a three of a kind?"<<endl;
        cout<<"press [1] for yes [2] for no"<<endl;
        cin>>choice;    
        if (choice == 1){
            return three_of_a_kind(number);
        }
        if (choice == 2){
            return 0;
        }
    }
    if (amountRoll[4] == 4){
        cout<<"would you like a four of a kind?"<<endl;
        cout<<"press [1] for yes [2] for no"<<endl;
        cin>>choice;
        if (choice == 1){
            return four_of_a_kind();
        }
        if (choice == 2){
            return 0;
        }
    }
    if (amountRoll[4] == 5){
        cout<<"would you like a five of a kind?"<<endl;
        cout<<"press [1] for yes [2] for no"<<endl;
        cin>>choice;
        if (choice == 1){
            return five_of_a_kind();
        }
        if (choice == 2){
            return 0;
        }
    }
    if (amountRoll[4] == 6){
        cout<<"would you like a six of a kind?"<<endl;
        cout<<"press [1] for yes [2] for no"<<endl;
        cin>>choice;
        if (choice == 1){
            return six_of_a_kind();
        }
        if (choice == 2){
            return 0;
        }
    }
 
 }
}
/******************************************************************************
** function:check_two
** description:this will check for the face value of 2
** Parameters:the sorted array 
** Pre-Conditions:must be a 2
** Post-Conditions: will send to other functions to get score
*********************************************************************/
int check_two (int *amountRoll){
    int choice = 0;
    int number = 2;
    if (amountRoll[1] > 2){
        cout<<"You have "<<amountRoll[1]<<" dice with the face value of 2"<<endl;
        if (amountRoll[1] == 3){
            cout<<"Would you like a three of a kind?"<<endl;
            cout<<"Press [1] for yes [2] for no"<<endl;
            cin>>choice;
            if (choice == 1){
                return three_of_a_kind(number);
            }
            if (choice == 2){
                return 0;
            }
        }
        if (amountRoll[1] == 4){
            cout<<"Would you like a four of a kind"<<endl;
            cout<<"Press [1] for four of a kind  [2] for no"<<endl;
            cin>>choice;
            if (choice == 1){
                return four_of_a_kind();
            }
            if (choice == 2){
                return 0;
            }
        }
        if (amountRoll[1] == 5){
            cout<<"Would you like a five of a kind"<<endl;
            cout<<"Press [1] for five of a kind [2] for no "<<endl;
            cin>>choice;
            if (choice == 1){
                return five_of_a_kind();
            }
            if (choice == 2){
                return 0;
            } 
       }
       if (amountRoll[1] == 6){
             cout<<"Would you like a six of a kind"<<endl;
             cout<<"Press [1] for six of a kind [2] for no"<<endl;
             cin>>choice;
            if (choice == 1){
                return six_of_a_kind();
            }
            if (choice == 2){
                return 0;
            }
        }
}} 
/***************************************************************************
** function:check_three
** description:this will check the sorted array for the face value of three
** Parameters:sorted roll
** Pre-Conditions:must be face value of three
** Post-Conditions: will send to other functions to get the score
*********************************************************************/
int check_three(int *amountRoll){
    int choice = 0;
    int number = 3;
    if (amountRoll[2] > 2){
        cout<<"You have "<<amountRoll[2]<<" dice with the face value of 3"<<endl;
         if (amountRoll[2] == 3){
            cout<<"Would you like a three of a kind?"<<endl;
            cout<<"Press [1] for yes [2] for no"<<endl;
            cin>>choice;
            if (choice == 1){
                return three_of_a_kind(number);
            }
            if (choice == 2){
                return 0;
            }
        }
        if (amountRoll[2] == 4){
            cout<<"Would you like a four of a kind"<<endl;
            cout<<"Press [1] for four of a kind  [2] for no"<<endl;
            cin>>choice;
            if (choice == 1){
                return four_of_a_kind();
            }
            if (choice == 2){
                return 0;
            }
        }
        if (amountRoll[2] == 5){
            cout<<"Would you like a five of a kind"<<endl;
            cout<<"Press [1] for five of a kind [2] for no "<<endl;
            cin>>choice;
            if (choice == 1){
                return five_of_a_kind();
            }
            if (choice == 2){
                return 0;
            } 
       }
       if (amountRoll[2] == 6){
             cout<<"Would you like a six of a kind"<<endl;
             cout<<"Press [1] for six of a kind [2] for no"<<endl;
             cin>>choice;
            if (choice == 1){
                return six_of_a_kind();
            }
            if (choice == 2){
                return 0;
            }
        }
}} 
/************************************************************************************
** function:check_four
** description:this will check the sorted array for the face value of four
** Parameters:the sorted array 
** Pre-Conditions:must be face value of four
** Post-Conditions: wil send to other functions and return the score 
*********************************************************************/
int check_four(int *amountRoll){
    int choice = 0;
    int number = 4;
    if (amountRoll[3] > 2){
        cout<<"You have "<<amountRoll[3]<<" dice with the face value of 4"<<endl;
        if (amountRoll[3] == 3){
            cout<<"Would you like a three of a kind?"<<endl;
            cout<<"Press [1] for yes [2] for no"<<endl;
            cin>>choice;
            if (choice == 1){
                return three_of_a_kind(number);
            }
            if (choice == 2){
                return 0;
            }
        }
        if (amountRoll[3] == 4){
            cout<<"Would you like a four of a kind"<<endl;
            cout<<"Press [1] for four of a kind  [2] for no"<<endl;
            cin>>choice;
            if (choice == 1){
                return four_of_a_kind();
            }
            if (choice == 2){
                return 0;
            }
        }
        if (amountRoll[3] == 5){
            cout<<"Would you like a five of a kind"<<endl;
            cout<<"Press [1] for five of a kind [2] for no "<<endl;
            cin>>choice;
            if (choice == 1){
                return five_of_a_kind();
            } 
            if (choice == 2){
                return 0;
            }
       }
       if (amountRoll[3] == 6){
             cout<<"Would you like a six of a kind"<<endl;
             cout<<"Press [1] for six of a kind [2] for no"<<endl;
             cin>>choice;
            if (choice == 1){
                return six_of_a_kind();
            }
            if (choice == 2){
                return 0;
            }
        }
}}
/****************************************************************************************
** function:check_six
** description:this will check the sorted array for the face value of 6
** Parameters:the sorted array 
** Pre-Conditions:must be of face value of six
** Post-Conditions: will send to another function and get the score
*********************************************************************/
int check_six(int *amountRoll){
    int choice = 0;
    int number = 6;
    if (amountRoll[5] > 2){
        cout<<"You have "<<amountRoll[5]<<" dice with the face value of 6"<<endl;
    if (amountRoll[5] == 3){
            cout<<"Would you like a three of a kind?"<<endl;
            cout<<"Press [1] for yes [2] for no"<<endl;
            cin>>choice;
            if (choice == 1){
                return three_of_a_kind(number);
            }
            if (choice == 2){
                return 0;
            }
        }
        if (amountRoll[5] == 4){
            cout<<"Would you like a four of a kind"<<endl;
            cout<<"Press [1] for four of a kind  [2] for no"<<endl;
            cin>>choice;
            if (choice == 1){
                return four_of_a_kind();
            }
            if (choice == 2){
                return 0;
            }
        }
        if (amountRoll[5] == 5){
            cout<<"Would you like a five of a kind"<<endl;
            cout<<"Press [1] for five of a kind [2] for no "<<endl;
            cin>>choice;
            if (choice == 1){
                return five_of_a_kind();
            } 
            if (choice == 2){
                return 0;
            }
       }
       if (amountRoll[5] == 6){
             cout<<"Would you like a six of a kind"<<endl;
             cout<<"Press [1] for six of a kind [2] for no"<<endl;
             cin>>choice;
            if (choice == 1){
                return six_of_a_kind();
            }
            if (choice == 2){
                return 0;
            }
        }
}}
/*******************************************************************************/
int get_scores(int *amountRoll){
    int score = 0;

    int singles = 0;
    int pairs = 0;
    int tripples = 0;
    int fours = 0;
    for (int i = 0; i < 6 ; i ++ ){
        if (amountRoll[i] == 1){
            singles ++ ;
        }
        if (amountRoll[i] == 2){
            pairs ++ ;
        }
        if (amountRoll[i] == 3){
            tripples ++;
       }
        if (amountRoll[i] == 4){
            fours ++;
       }

        if (singles == 6){
            score += 1500;
            //straight();
        }   
        if (pairs == 3){
            score += 1500;
            //three_pairs(); 
        }
        if (tripples == 2){
            score += 2500; 
            //two_tripples();
        }
        if ((pairs == 1) and (fours == 1)){
            
            score += 1500;
            //four_and_a_pair();
        }
    }







        if (amountRoll[0] > 0){
            score += check_one(amountRoll);
        }
        if (amountRoll[1] > 2){
            score += check_two(amountRoll);
        }
        if (amountRoll[2] > 2){
            score += check_three(amountRoll);
        }
        if (amountRoll[3] > 2){
            score += check_four(amountRoll);
        }
        if (amountRoll[4] > 0){
            score += check_five(amountRoll);
        }
        if (amountRoll[5] > 2){
            score += check_six(amountRoll);
        }
return score;
}
/********************************************************************
** function:reset_sorted
** description:this will reset the sorted array back to 0's
** Parameters:the sorted array
** Pre-Conditions:must be end of turn 
** Post-Conditions: returns the array reset
*********************************************************************/
void reset_sorted(int *amountRoll){
    for (int i =0; i < 6; i ++ ){
        amountRoll[i] = 0;
    }
}    
/*************************************************************
** function:roll_again
** description:this gets 6 random values for the dice
** Parameters:the roll array 
** Pre-Conditions:the dice 
** Post-Conditions:the random face values
*********************************************************************/
bool roll_again(){
    int choice = 0;
    cout<<"would you like to roll again?"<<endl;
    cout<<"press [1] for yes [2] for no"<<endl;
    if (choice == 1){
        return true; 
    }  
    if (choice == 2){
        return false;
    }
}
/*************************************************************************
** function:players turn 
** description:this function handles it all it goes for every persons turn 
** Parameters:the score the length and the current player
** Pre-Conditions:must be the players turn 
** Post-Conditions:will return the score for the players turn 
*********************************************************************/
   void players_turn(int *score , int current_player){
    int roll[6] ;
    int amountRoll[6] = {0,0,0,0,0,0};
    dice_roll(roll);
    sort_roll(roll, amountRoll); 
    cout<<"**************************************"<<endl;
    score[current_player] += get_scores(amountRoll);
    cout<<score[current_player]<<endl;
    cout<<endl;
    //if(roll_again() == true ){
      //  dice_roll(roll);
    //}
    cout<<endl;



}          
/*************************************************************************************
** function:game_going
** description:this function check the score to see if it has hit 1000 and if it has game is over
** Parameters:the score and the length
** Pre-Conditions:the score must be below or above
** Post-Conditions: bool return type for game going
*********************************************************************/
bool game_going(int *score, int currentPlayer ){
    for (int i = 0; i < currentPlayer; i++){
        if (score[currentPlayer] >= 10000){
            return false;
        }
    }
return true;
}
/******************************************************************************
** function:initscore
** description:return the score
** Parameters:score and length 
** Pre-Conditions:must be a score
** Post-Conditions: return score
*********************************************************************/
void initScore(int* score, int length){
    for(int i =0; i<length; i++){
        score[i] = 0;
    }
}
/********************************************************************************
** function:main
** description:the part of the code that starts it all
** Parameters:none
** Pre-Conditions:will take in the turns
** Post-Conditions: return scores
*********************************************************************/
int main(){
    srand(time(NULL));
    bool game_over = false;
    int numpeople = num_players();
    int *score = new int [numpeople];
       for (int i = 0; i < numpeople ; i++ ){
    while ( game_over == false){
             print_score(score , numpeople ); 
            cout<<"**************************************"<<endl;
            cout<<"********** Player "<< i+1 <<" Turn *************"<<endl;
            cout<<endl;
            players_turn( score , i);
           
        }
        if (game_going(score , i) == false){
            game_over = true;
        }  
    }   


    delete [] score;
return 0;
}

