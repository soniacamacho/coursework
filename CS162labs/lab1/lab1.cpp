#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

bool check_board_size(int board_size){
    if (board_size > 0  and board_size < 9){
        return true;
    }
        return false;
}
struct mult_div_values{
    int mult;
    float div;
};

mult_div_values** create_table(int m, int n){
    struct mult_div_values **table = new  mult_div_values *[m];
        for (int i =0; i <m; i++){
            table[i] = new struct mult_div_values[n];
        }
return table;
}
void set_mult_values(mult_div_values **table, int m, int n){
    for (int i = 0 ; i <m ; i++){
        for (int j = 0; j < n; j++){
            table[i][j].mult = (i+1)*(j+1);
        }
    }
}
void set_div_values(mult_div_values **table, int m, int n){
    for (int i = 0 ; i <m ; i++){
        for (int j = 0; j < n; j++){
            table[i][j].div = (i+1.0)/(j+1.0);
        }
    }
}
void delete_table(mult_div_values **table,int m){
    for (int i =0 ; i < m; i++){
        delete [] table[i];
    }
    //delete[];
}
void print_values_mult(mult_div_values **table,int m ,int n){
    for (int i =0 ; i<m;i++){
        for (int j =0 ; j <n ; j ++){
            cout<<table[i][j].mult<<" ";
        }
    
        cout<<endl;
    }
}
void print_values_div(mult_div_values **table,int m ,int n){
    for (int i =0 ; i<m;i++){
        for (int j =0 ; j <n ; j ++){
            cout<<table[i][j].div<<" ";
        }
    cout<<endl;
    }
}
int main(int argc,char **argv){
    char str [256] ;
    int board_size =0;
    int choice = 0;
     
        if(argc == 2 and argv[1] != 0){
        for (int i =1; i < 2 ; i++){
           board_size = atoi(argv[i]);
        }
    }
    do{
    while  (check_board_size(board_size) == false){
        cout<<endl;
        cout<<"Enter a number"<<endl;
        cout<<endl;
        cin.getline(str,sizeof(str));
        board_size =  atoi(str);    
    }
    cout<<endl;
    cout<<"The table size is: "<<board_size<<" X "<<board_size<<endl;
    cout<<endl;
    
    int m = board_size;
    int n = board_size;
    mult_div_values** table = create_table(m,n);
    set_mult_values(table,m,n);
    set_div_values(table,m,n);
    cout<<"Mult values"<<endl;
    print_values_mult(table,m,n);
    cout<<"Div values"<<endl;
    print_values_div(table,m,n);
    delete_table(table,m);
    
    cout<<"would you like to see a differetn matrix? 0- no 1 -yes"<<endl;
    cin>>choice;
    if(choice == 1){
        board_size = 0;
    cout<<"input a new matrix size"<<endl;
    cin>>board_size;
    }
    }while(choice == 1); 
return 0;
}
