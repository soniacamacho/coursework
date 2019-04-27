#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(){
    
    srand(time(NULL));
    int randTemp;
    cout<<endl;
    cout<<endl;

    cout<<"this is password creator"<<endl;
    string password;
    cout<<endl;
    bool randgen=true;
    while(randgen == true){
    cout<<endl;
    int upper;
    cout<<"how many upper case letters would you like?"<<endl;
    cin>>upper;
    
    for (int i=0;i<upper;i++){
        randTemp = (rand()%26)+65;
        password += (char)randTemp;    
    }
    int lower;
    cout<<"how many lower case letters would you like?"<<endl;
    cin>>lower;
    for (int i=0;i<lower;i++){
        password+=char(rand()%26+97);
    }       
    
    int nums;
    cout<<"how many numbers would you like?"<<endl;
    cin>>nums;
    for (int i=0;i<nums;i++){
        password+=char(rand()%10+48);
    }
    cout<<"your password is: "<<password<<endl;
    int yesorno;
    cout<<"would you like to make another password [1] yes [2] no"<<endl;
    cin>>yesorno;
    if (yesorno == 1){
        randgen=true;
    }
    else{
        randgen=false;
    }
}
return 0;}
