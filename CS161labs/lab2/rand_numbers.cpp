#include <iostream>
#include <ctime> /*included to allow time() to be used */
#include <cstdlib> /*include to allow rand() and srand() to be used*/

using namespace std;

int main(){
    int x; /*variable to hold our random integer */
    int num;
    srand(time(NULL));/* seeds random number in generator. Do this just once*/
    num = rand() % 6;
    cout<<num<<endl;
    if (num == 0){
        cout<<"bummer, I'm 0"<<endl;
    }
    else if (num == 1 or num== 3 or num==5){
        cout<<"hey I'm odd"<<endl;
    }
    else{
        cout<<"I'm even"<<endl;
    }
    x = rand();
    cout<< "x = "<<x<<endl;
    
    x = rand ();
    cout<<"x = "<<x<<endl;
return 0;
}
