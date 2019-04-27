#include <iostream>
#include <cmath>
using namespace std;

int main (){
    long bytes;
    long bits;
    cout<<"how many bytes?"<<endl;
    cin>>bytes;
    bits = bytes *8;
    
    cout<<"the number of bits in signed max int: "<<(pow(2,bits-1))-1<<endl;
    cout<<"the number of bits in an unsigned max int: "<<(pow(2,bits))-1<<endl;
    cout<<"the number of bits in signed min int: "<<(pow(-2,bits-1))<<endl;
    cout<<"the number of bits in an unsigned min int: "<<0<<endl;   







    return 0;
}
