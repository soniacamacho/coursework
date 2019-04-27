#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <string>
using namespace std;

/********************************************************************
** function:check_board_size
** description:this will be checking the board to ensure it is a valid game board
** Parameters:the board size 
** Pre-Conditions:must be an int
** Post-Conditions:will return true if it is valid board
*********************************************************************/
bool check_board_size(int board_size){
    if (board_size == 8 or board_size == 10 or board_size == 12 ){
        return true;
    }
        return false;
}

/********************************************************************
** function:print_dyn
** description:this will print out the board
** Parameters:game board and rows and cols
** Pre-Conditions:must be valid input
** Post-Conditions:prints out the game board
*********************************************************************/
void print_dyn(char** game_board, int rows,int cols){
    char game_piece ;
    int color;
    cout<<"   ";
    for (char i = 'a'; i <'a'+rows ; i++){
        cout<<"|\033[0m"<<i<<"  ";
    }
    cout<<endl;

    for(int i=0; i< rows ; i++) {
        cout<<"|\033[0m"<<i+1<<"";
        if ( i < 9 ){
            cout<<" "; 
        }
        for(int j=0; j < cols; j++){
            game_piece = game_board[i][j];
                if (game_piece == 'x'){
                    color = 31;
                }
                else {
                    color = 37;
                }
            if (!(i % 2 == j %2))
                cout << "|\033["<<color<<";40m " << game_board[i][j] << " ";
            else
                cout << "|\033[37;47m " << game_board[i][j] << " ";
            cout << "\033[0m";
        }
        cout<<endl;
    }
}
/********************************************************************
** function:pop_dyn
** description:this will set up the game board with x and o 
** Parameters:the game board playing on and rows and cols
** Pre-Conditions:must be valid input
** Post-Conditions:prints out the board with x and o
*********************************************************************/
void pop_dyn(char **game_board, int rows, int cols){
   for (int i =0; i < rows; i++){
        for(int j =0; j < cols; j++){
            game_board[i][j] = ' ';
        }
    } 
    for (int i = 0; i < (rows/2)-1; i++){
        if ( i % 2 == 0){
            for (int j = 0; j < cols; j++){
                if (j % 2 == 1){
                    game_board[i][j] ='o';

                }
            }
        }
        if (i % 2 == 1){
             for (int j = 0; j < cols; j++){
                if (j % 2 == 0){
                    game_board[i][j] = 'o';
                }
            } 
        }
    }
    for(int i = (rows/2)+1 ; i < rows ; i++){
        if ( i % 2 == 0){
            for (int j = 0; j < cols; j++){
                if (j % 2 == 1){
                    game_board[i][j] ='x';
                }
            }
        }
        if (i % 2 == 1){
             for (int j = 0; j < cols; j++){
                if (j % 2 == 0){
                    game_board[i][j] = 'x';
                }
            }
        }
    }
}
bool valid_letter(char coord){
    if (coord < 97 or coord > 122 ){        return false;
    }
return true;
}
/********************************************************************
** function:valid number
** description:checks to see if the input is a vlid number
** Parameters:must be char
** Pre-Conditions:checks to see if it is valid
** Post-Conditions:returns true or false
*********************************************************************/
bool valid_number(char coord){
    if (coord < 48 or coord > 57){      
        return false;
    }
return true;
}
/********************************************************************
** function:is_int 
** description:checks to see if the input is the c style string
** Parameters:char coord
** Pre-Conditions:must be char
** Post-Conditions:returns true or false
*********************************************************************/
bool is_int(string players){
    for (int i= 0 ; i < 2 ; i++ ){
        if (players[i] < '0' or players[i] > '9'){
            return false;
        }
       
    return true;
    }
}
/******************************************************************
** function:get int 
** description:takes a prompt then gets user input to find int
** Parameters:string prompt
** Pre-Conditions:must be string
** Post-Conditions:integer return
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
bool is_valid(char* coord){
    if (valid_letter(coord[0]) == false or valid_number(coord[1]) == false){  
        return false;
    }
return true;
} 
/**********************************************************************
** function:get_choice
** description:return the choice
** Parameters:string prompt
** Pre-Conditions:must be a string
** Post-Conditions: return choice
*********************************************************************/
bool get_choice(string prompt){
    string choice = "";
    int number_choice = 0;
    cout<<prompt<<endl;
    cout<<" [1] yes [2] no"<<endl;
    getline (cin,choice);
        
    while  ((is_int(choice) == false) or (get_int(choice) > 2) or (get_int(choice) < 1)){
       cout<<endl;
       cout <<"Invalid input try again you must enter an integer that is a 1 or 2"<<endl;
       cout<<"[1] yes [2] no"<<endl;
       cout<<endl;
       getline (cin , choice);
    }
    number_choice = get_int(choice);    
    
    if (number_choice == 1){
        return true;
    }
      else{  return false;
    }
}


/********************************************************************
** function:new_spot
** description:this will get the desired move for the player
** Parameters:coord game board the size and the player
** Pre-Conditions:must be valid input
** Post-Conditions:will return the board move
*********************************************************************/
void new_spot(char ** game_board,int rows,int cols,char* coord,char piece){
    string coordinate;
    int i;
    int next=0;
    int number =0;
    int letter2 =0;
    char r;
    char b;
    for(i=0; i < strlen(coord);i++){
        if (coord[i] == 32){
            next += i+1;
            for(int j = i+2; j < strlen(coord);j++){
                    coordinate += coord[j];
                    j++; 
            }
        }
    }
    number = get_int(coordinate);    
    letter2 =(int)coord[next]-97;
    char p = piece;
   r = game_board[number-1][letter2] = p;
}
/********************************************************************
** function:new_spot_jump
** description:this will get the desired move for the player
** Parameters:coord game board the size and the player
** Pre-Conditions:must be valid input
** Post-Conditions:will return the board move
*********************************************************************/
void new_spot_jump(char ** game_board,int rows,int cols,char* coord,char piece){
    string coordinate;
    int i;
    int next=0;
    int number =0;
    int letter2 =0;
    char r;
    char b;
    for(i=0; i < strlen(coord);i++){
        if (coord[i] == 32){
            next += i+1;
            for(int j = i+2; j < strlen(coord);j++){
                    coordinate += coord[j];
                    j++; 
            }
        }
    }
    number = get_int(coordinate);    
    letter2 =(int)coord[next]-97;
    char p = piece;
   b = game_board[number-2][letter2+1] = ' ';
   r = game_board[number-1][letter2] = p;
       
}
/********************************************************************
** function:old_spot
** description:this will get the desired move for the player
** Parameters:coord game board the size and the player
** Pre-Conditions:must be valid input
** Post-Conditions:will return the board move
*********************************************************************/
void old_spot(char ** game_board, int rows,int cols,char* coord){
    string coordinate;
    int i=1;
    int j=1;
    int num=0;
    int letter =0;
    char n;
    while (coord[i] != ' ' ){
        coordinate+= coord[i];
        i++;
    }
    num = get_int(coordinate);    
    letter =(int)coord[j-1]-97;
    n=game_board[num-1][letter] = ' ';

 }
/********************************************************************
** function:get coord
** description:this will get the desired move for the player
** Parameters:coord game board the size and the player
** Pre-Conditions:must be valid input
** Post-Conditions:will return the board move
*********************************************************************/
void get_coord(char** game_board,int current_player,int rows,int cols){
    char coord [256];
    cout<<"Input your current coordinate followed by a space and the coordinate you would like to move to"<<endl;
    cin.getline(coord,sizeof(coord));
    while(is_valid(coord)== false){
        cout<<"invalid input .Input your current coordinate followed by a space and the coordinate you would like to move to"<<endl;
        cin.getline(coord,sizeof(coord));
    }
  
    string z = "is this a jump?";
    if (get_choice(z) == true){
    
    
    char piece = current_player == 0 ? 'o':'x';
    old_spot(game_board,rows,cols,coord);
    new_spot_jump(game_board,rows,cols,coord,piece);
    print_dyn(game_board,rows,cols);
    cout<<endl;
    }
    else{
    char piece = current_player == 0 ? 'o':'x';
    old_spot(game_board,rows,cols,coord);
    new_spot(game_board,rows,cols,coord,piece);
    print_dyn(game_board,rows,cols);
    cout<<endl;
    }
}
 /********************************************************************
** function:new_spot2
** description:this will get the desired move for the player
** Parameters:coord game board the size and the player
** Pre-Conditions:must be valid input
** Post-Conditions:will return the board move
*********************************************************************/
void new_spot2(char ** game_board,int rows,int cols,char* coord,char piece){
    string coordinate;
    int i;
    int next=0;
    int number =0;
    int letter2 =0;
    char r;
    char b;
    for(i=0; i < strlen(coord);i++){
        if (coord[i] == 32){
            next += i+1;
            for(int j = i+2; j < strlen(coord);j++){
                    coordinate += coord[j];
                    j++; 
            }
        }
    }
    number = get_int(coordinate);    
    letter2 =(int)coord[next]-97;
    char p = piece;
    r = game_board[number-1][letter2] = p;
}
/********************************************************************
** function:new_spot2_jump
** description:this will get the desired move for the player
** Parameters:coord game board the size and the player
** Pre-Conditions:must be valid input
** Post-Conditions:will return the board move
*********************************************************************/
void new_spot2_jump(char ** game_board,int rows,int cols,char* coord,char piece){
    string coordinate;
    int i;
    int next=0;
    int number =0;
    int letter2 =0;
    char r;
    char b;
    for(i=0; i < strlen(coord);i++){
        if (coord[i] == 32){
            next += i+1;
            for(int j = i+2; j < strlen(coord);j++){
                    coordinate += coord[j];
                    j++; 
            }
        }
    }
    number = get_int(coordinate);    
    letter2 =(int)coord[next]-97;
    char p = piece;
      b = game_board[number][letter2-1] = ' ';
       r = game_board[number-1][letter2] = p;
}
/********************************************************************
** function:old_spot2
** description:this will get the desired move for the player
** Parameters:coord game board the size and the player
** Pre-Conditions:must be valid input
** Post-Conditions:will return the board move
*********************************************************************/
void old_spot2(char ** game_board, int rows,int cols,char* coord){
    string coordinate;
    int i=1;
    int j=1;
    int num=0;
    int letter =0;
    char n;
    while (coord[i] != ' ' ){
        coordinate+= coord[i];
        i++;
    }
    num = get_int(coordinate);    
    letter =(int)coord[j-1]-97;
    n=game_board[num-1][letter] = ' ';

 }

/********************************************************************
** function:get_coord2
** description:this will get the desired move for the player
** Parameters:coord game board the size and the player
** Pre-Conditions:must be valid input
** Post-Conditions:will return the board move
*********************************************************************/
void get_coord2(char** game_board,int current_player,int rows,int cols){
    char coordi [256];
    cout<<"Input your current coordinate followed by a space and the coordinate you would like to move to"<<endl;
    cin.getline(coordi,sizeof(coordi));
    while(is_valid(coordi)== false){
        cout<<"invalid input .Input your current coordinate followed by a space and the coordinate you would like to move to"<<endl;
        cin.getline(coordi,sizeof(coordi));
    }
    string g = "Is this a jump?[1]yes[2]no";
    bool choice = get_choice(g);
    
    if(choice == true){
    
    char piece = current_player == 0 ? 'o':'x';
    old_spot2(game_board,rows,cols,coordi);
    new_spot2_jump(game_board,rows,cols,coordi,piece);
    print_dyn(game_board,rows,cols);
    cout<<endl;
    }
    else{
    char piece = current_player == 0 ? 'o':'x';
    old_spot(game_board,rows,cols,coordi);
    new_spot2(game_board,rows,cols,coordi,piece);
    print_dyn(game_board,rows,cols);
    cout<<endl;
    }

}   
/********************************************************************
** function:players_turn
** description:this will run through each function for each player
** Parameters:game board the size and the player
** Pre-Conditions:must be all valid
** Post-Conditions:will do stuff in that players turn 
*********************************************************************/
void players_turn( char** game_board, int rows,int cols,int current_player){
    cout<<"Player "<<current_player+1<<" turn"<<endl;
    char piece = current_player == 0 ? 'o':'x';
    cout<<"Players pice: "<<piece<<endl;
    get_coord(game_board, current_player,rows,cols);
}
/********************************************************************
** function:players_turn
** description:this will run through each function for each player
** Parameters:game board the size and the player
** Pre-Conditions:must be all valid
** Post-Conditions:will do stuff in that players turn 
*********************************************************************/
void players_turn2( char** game_board, int rows,int cols,int current_player){
    cout<<"Player "<<current_player+1<<" turn"<<endl;
    char piece = current_player == 0 ? 'o':'x';
    cout<<"Players pice: "<<piece<<endl;
    get_coord2(game_board, current_player,rows,cols);
}
/********************************************************************
** function:delete_dyn_array
** description:this will go in and delete all the memory in the 2d array
** Parameters:game board and rows and cols
** Pre-Conditions:must there to delte it
** Post-Conditions:deleted
*********************************************************************/
void delete_dyn_array(char** game_board, int rows, int cols){
    for(int i = 0; i < rows ; i++){
        delete [] game_board[i];
    }
    delete [] game_board;
    game_board = NULL;
}
/********************************************************************
** function:red winner
** description:this will run through each function for each player
** Parameters:game board the size and the player
** Pre-Conditions:must be all valid
** Post-Conditions:will do stuff in that players turn 
*********************************************************************/
bool red_winner(char**game_board, int rows, int cols){
int counter =0;
    for (int i =0; i < rows; i++){
        for(int j =0; j < cols; j++){
            if (game_board[i][j] == 'o'){
                counter++;
            }
        }
    
    if (counter > 0) {
        return false;
    }
   }
        cout<<"Player 2 you win!"<<endl;
        return true;
    
}
/********************************************************************
** function:white winner
** description:this will run through each function for each player
** Parameters:game board the size and the player
** Pre-Conditions:must be all valid
** Post-Conditions:will do stuff in that players turn 
*********************************************************************/
bool white_winner(char**game_board, int rows, int cols){
int counter =0;
   for (int i =0; i < rows; i++){
        for(int j =0; j < cols; j++){
            if (game_board[i][j] == 'x'){
                counter++;
            }
        }
    
    if (counter > 0) {
        return false;
    }
    }
        cout<<"Player 1 you win!"<<endl;
        return true;
    
}


/*********************************************************************/
int main(int argc, char** argv) {     
    char str [256] ;
    int board_size =0;
    if(argc == 2){
        for (int i =1; i < 2 ; i++){
           board_size = atoi(argv[i]);
        }
    }
    else { 
        cout<<"Please input a game board size [8,10,12]"<<endl;
        cin.getline(str, sizeof(str));
        board_size = atoi(str);
    }
    while  (check_board_size(board_size) == false){
        cout<<endl;
        cout <<"Invalid input try again"<<endl;
        cout<<"Enter game board size [8 ,10 ,12]"<<endl;
        cout<<endl;
        cin.getline(str,sizeof(str));
        board_size =  atoi(str);    
    }
    cout<<endl;
    cout<<"******** CHECKERS ********"<<endl;
    cout<<"The board size is: "<<board_size<<" X "<<board_size<<endl;
    cout<<endl;

/*********************************************************************/
//now the game board array will be made with the dimensions of board_size
    int rows = board_size;
    int cols = board_size;
    char **game_board = new char*[rows];
    for (int i =0; i <rows; i++){
        game_board[i] = new char[cols];
    }
    pop_dyn(game_board,rows,cols);
    print_dyn(game_board,rows,cols);

/*********************************************************************/
    bool redw =  red_winner(game_board,rows,cols);
    bool whitew = white_winner(game_board,rows,cols);
    bool current_player =  false;
    while(redw == false and  whitew == false){
    //    for (int current_player = 0 ; current_player < 2 ; current_player++ ){
          if (current_player == 0){
                players_turn(game_board,rows,cols,current_player);
            }
            if (current_player == 1 ){
                players_turn2(game_board,rows,cols,current_player);
           }
    //    cin.ignore();
        cin.clear();
        current_player =!current_player;
        redw = red_winner(game_board,rows,cols);
        whitew = white_winner(game_board,rows,cols);
    }
    
    
    cout<<endl;
    delete_dyn_array(game_board,rows,cols);
return 0;
} 
