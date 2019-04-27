#include <iostream>
#include <cmath>
using namespace std;
void towers(int disks, int b[][3] , int from_col, int to_col,int rows , int spare){
    if(disks >= 0){
        towers(disks-1, b, from_column, to_col,rows, spare);
        cout<<"Moving disk "<<disks<<" from "<<from_column<<" to "<<to_column<<endl;
        moveDisk(disks-1, b, from_column, to_colu,rows); 
        printArray(b, rows);
        towers(disks-1, b, from_column, to_column, rows, spare);
    }
}
/***************************************************************************************/
void moveDisk(int disk, int b[][3], int from_column, int to_column, int rows){
    int lowest;
    int i;
    for(i = rows-1; i>=0 && b[i][from_column]!=0; i--){
    disk = i;
    }
    for(i = rows-1; i>=0; i--){
    if (b[i][to_column]!=0){
        ;
    }
    else{
        lowest = i;
        break;
    }    
    }
    b[lowest][to_column] = b[disk][from_column];
    b[disk][from_column] = 0;
}


void printArray(int x = 0; x<rows; x++)ry(int array[][3], int rows){
    for (int x = 0; x<rows; x++){
    for (int y = 0; y<3; y++){
        cout<<array[x][y];
    }
    cout<<endl;
    }
    cout<<"-----------------------"<<endl;
}     fo

