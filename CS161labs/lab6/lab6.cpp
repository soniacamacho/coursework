#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using namespace std;
/*
using std::cout;
using std::endl;
*/
int fib_iter(int n){
    int spot1=0;
    int spot2=1;
    int spot3=0;
    if (n==0){
        return 0;
    }
    if (n==1){
        return 1;
    }
    while (n >= 2){
        spot3=spot1+spot2;
        spot1=spot2;
        spot2=spot3;
    n--;
    }
    return spot3;
}

/*********************************************************************/
 int fib_recurs(int n){
    if (n == 0 ){
        return 0;
    }
    else if (n == 1){
        return 1;
    }
    else {
        return fib_recurs(n-1) + fib_recurs(n-2);
    }
}



int main(){
int h=0;
cout<<"enter a number"<<endl;
cin>>h;
cout<<"The Iterative Fibonacci number is : "<< fib_iter(h)<<endl;
cout<<"The Recursive Fibonacci number is : "<< fib_recurs(h)<<endl;
return 0;
} 


