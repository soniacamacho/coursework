/****************************************************************            * ** Program Filename:Assignment1
 * ** Author:Sonia Camacho
 * ** Date:1-9-18
 * ** Description:In this program we are just getting familiar with coding in c++ and using the different libraries 
 * ** Input:
 * ** Output: 
 * *********************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    /*right here I am declaring a variable that is called X. 
    this variable will be used and changed throughout the program*/
    int x =0;
    /*This line prints the value of the cosine equation with the values give    n*/
    cout<<"cos(2/3) = "<< cos(0.66)<< endl; 
    cout<<endl;
    cout<<endl;
    cout<<endl;
    /*this line prints the value of the equation given */
    cout<<"2sin(2/3) = "<< 2*(sin(0.66))<< endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    /*this line prints the value of what was put into the equation*/
    cout<<"tan(-3/4) = "<< tan(-0.75)<< endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    /*this line will print out the log equation that is given*/
    cout<<"log10(55) = "<< log10(55)<< endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    /*this line will print out the ln equation using the log equation*/
    cout<<"ln(60) = "<< log(60)<< endl;     
    cout<<endl;
    cout<<endl;
    cout<<endl;
    /*here we were given the eqution so here I set the values equal to what     were given*/
    cout<< "Find the log 2 of 15." << endl;
    cout<< " ln(x) = 2.70805" << endl;
    cout<< " ln(b) = 0.693147" << endl;
    cout<< " ln(x)/ln(b) = 3.90689" << endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    /*here is where x is given the value of 40 and just like the lst equation I used the values given and then divided them to give the result*/
    x = 40;
    int b =4 ;
    cout<< "Find the log 4 of 40." << endl;
    cout<< " ln(x) = " << log (40)<< endl;
    cout<< " ln(b) = " << log (4)<< endl;
    cout<< " ln(x)/ln(b) = " <<log(40)/log(4) << endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    /*here is where we really re use the value of x and plug in the equation that was given and for this step I created a float to create a step so that I could re implement it in the other values. */
    x=1;
    cout<<"find 3^sin(X)"<<endl;
    cout<<"for x=1"<<endl;
    float part1 = pow(3,sin(x));
    cout<<"3^sin(x) = "<<part1<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;


    x=10;
    cout<<"find 3^sin(X)"<<endl;
    cout<<"for x=10"<<endl;
    part1 = pow(3,sin(x));
    cout<<"3^sin(x) = "<<part1<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;


    x=100;
    cout<<"find 3^sin(X)"<<endl;
    cout<<"for x=100"<<endl;
    part1 = pow(3,sin(x));
    cout<<"3^sin(x) = "<<part1<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

/*here like before I re set the values of x and then used the equation to write out the steps for each one I gave the value of x a new value and and then printed out the equation that I needed to solve it for.Then I printed that x had a new value assigned then on the last line I just printed the result */
    x=1;
    cout<<"find log2(x^2+1) "<<endl;
    cout<<"for x = "<<x<<endl;
    cout<<"log2(x^2+1) = "<< log2 (pow(x,2)+1)<< endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    x=10;
    cout<<"find log2(x^2+1) "<<endl;
    cout<<"for x = "<<x<<endl;
    cout<<"log2(x^2+1) = "<< log2 (pow(x,2)+1)<< endl;
    cout<<endl; 
    cout<<endl;
    cout<<endl;
    cout<<endl; 


    x=100;
    cout<<"find log2(x^2+1) "<<endl;
    cout<<"for x = "<<x<<endl;
    cout<<"log2(x^2+1) = "<< log2 (pow(x,2)+1)<< endl;
    cout<<endl;
  
    return 0;
}




