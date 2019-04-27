/*
 *  **description: turns a character into a decimal value
** Parameters: char character
** Pre-Conditions: the input is a character
** Post-Conditions: returned the decimal value of the character *********************************************************************/
#include <iostream>
#include <string>
using namespace std;

int a_to_i(char test){
    return (int)test;
}


char i_to_a(int decimal){
    return (char)decimal;
}


int main(){
    char t;
    cout<<"input a char"<<endl;
    cin>>t;
    cout<<a_to_i(t)<<endl;
    int d;
    cout<<"input a integer"<<endl;
    cin>>d;
    cout<<i_to_a(d)<<endl;

return 0;
}
