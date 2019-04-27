#include <iostream>
#include <cmath>
using namespace std;

void initialize_array(int b[][3]){
    for (int i =0; i < 3; i++){
        for(int j =0; j < 3 ; j++){
            b[i][j] = 0;
        }
    }
    for (int i = 0; i < 3; i++){
        b[i][0] = (i+1);
    }
}

void print_array(int b[][3]){
    for (int i = 0; i < 3 ; i++){
        for ( int j = 0; j< 3 ; j++){
             cout<< b[i][j];
        }
    cout<<endl;
    }
cout<<"*****"<<endl;
}



void moveDisk(int b[][3],int disks,int from_col,int to_col){
    int found = 0;
    int move_to = 0;
    for (int i = 0 ; i < 3 ; i++){
        if( b[i][from_col] != 0){
            found = b[i][from_col];
            b[i][from_col] = 0;
        break;
        }
    }

    for (int i = 2; i >= 0 ; i--){
        if ( b[i][to_col] == 0){
           move_to = i;
          if(move_to == 2){ 
             b[i][to_col] = found;
          }
          else if(b[i+1][to_col] > found){
            b[i][to_col] = found;
          }

        }        
        
    }
}
 
void towers(int disks, int b[][3], int from_col, int to_col, int spare){
    if(disks >= 1){
    towers(disks-1, b, from_col, spare, to_col);
    moveDisk(b ,disks, from_col , to_col);
    print_array(b);
    towers(disks-1, b, spare, to_col, from_col);
}
}
int main(){
int b[3][3];
initialize_array(b);
print_array(b);
towers(3,b,0,2,1);

return 0;
}
    
