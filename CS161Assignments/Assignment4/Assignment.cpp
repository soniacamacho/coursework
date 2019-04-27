#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/*****************************************************************
 * ** Function: bin_check()
 * ** Description:checks to see if the number entered is binary
 * ** Parameters:binary number consist of 1 and 0
 * ** Pre-Conditions:must be binary 
 * ** Post-Conditions:return decimal value
 *******************************************************************/

bool bin_check(string binarynum){
    for(int i=0;i<binarynum.length();i++){
        if ((binarynum[i] != '0') and (binarynum[i] != '1')){
            return false;
        }
    }
return true;
}

/*****************************************************************
 * ** Function: get_binarynum()
 * ** Description:gets the actual binary number from the user
 * ** Parameters:binary number consist of 1 and 0
 * ** Pre-Conditions:must be binary 
 * ** Post-Conditions:return decimal value
*****************************************************************/ 
string get_binarynum() {
    string binarynum = "" ;
    do {
        cout<<"please enter a binary number: "<<endl;
        getline(cin,binarynum);
    } while (bin_check(binarynum)==false);

    return binarynum;
}

/*****************************************************************
 * ** Function: bin_to_dec() this code is from the website
 * ** Description:this will take in a binary number and convert it to decimal
 * ** Parameters:binary number consist of 1 and 0
 * ** Pre-Conditions:must be binary 
 * ** Post-Conditions:return decimal value
 ****************************************************************/
 
int bin_to_dec(string binarynum) {
    int binlen = binarynum.length();
    int ans =0;
    for (int i=0;i < binlen; i ++){
        if (binarynum[i] == 49){
            ans += pow(2, (binlen-i-1));
        }
    }
    return ans;
}
/*****************************************************************
** function:is_float
** description:checks a string to see if it is a float
** Parameters:string num
** Pre-Conditions:must be a string
** Post-Conditions:boolean return
*********************************************************************/
 

bool is_float(string num){
   
    for (int i=0;i<num.length();i++){
        if (num[i]=='.'){
            return true;
  }      
}   
return false;

}


/********************************************************************
** function:get float
** description:gets the prompt and then user input to make it a float
** Parameters:string prompt
** Pre-Conditions:string has to be
** Post-Conditions:float return
*********************************************************************/

float get_float(string prompt){
    string t;
    bool in = false;

    cout<<prompt<<endl;
    while (in == false){
        getline(cin, t);
        in = is_float(t);
        if(in == false){
            cout<<"bad input try again."<<endl;
        }

    }
   
    int var=0;
    int exp=0;
    int loc=0;
    for(int i= t.length()-1; i>=0 ; i--){
        if (t[i]==46){
            loc=i;
        }
        else{
            var+=(((int)t[i])-48)*pow(10,exp);
            exp++;
        }
   
    }
    float ans= ((float)var)/pow(10,t.length()-1-loc);
return ans;
}

/********************************************************************
** function:get grade
** description: gets a grade from the user and will send it through other function checks and then will print out the grade averages and if they are weighted or not
** Parameters:none
** Pre-Conditions:floats have to be entered
** Post-Conditions:float return
*********************************************************************/
float get_grade(){
    float numofgrade=0 , sum=0 ,weightornot=0 , result=0 , weight , grade;
    cout<<"how many grades would you like to average? "<<endl;
    cin>>numofgrade;
    for (int i=0; i<numofgrade ; i++){
        cout<<"input grade" <<endl;
        cin>>grade;
     
    sum += grade;
    }
    cout<<"Would you like the grades to be weighted?[1] yes [2]no "<<endl;
    cin>>weightornot;
    cout<<endl;
    if (weightornot == 1){
        cout<<"input weight in decimal form "<<endl;
        cin>>weight;
        result = (sum * weight);
        
    cout<<"Weighted Average: "<<result<<endl;
    cout<<endl;
    }
    else if (weightornot ==2){
        result= sum / numofgrade;
    
    cout<<"Average: "<<result<<endl;
    }   
}
/*****************************************************************
 * ** Function: dec_to_bin()
 * ** Description:checks to see if the number entered is decimal then it will convert
 * ** Parameters:binary number consist of numbers
 * ** Pre-Conditions:must be number
 * ** Post-Conditions:return binary value
 *******************************************************************/
int dec_to_bin(){
    int dec = 0;
    int bin = 0;
    int j = 0;
    cout<<"Enter a decimal string: "<<endl;
    cin>> dec;
    while (dec != 0){
        bin = bin + (dec % 2) * pow(10,j);
        dec = dec / 2;
        j = j + 1;
    }
    return bin;
} 

/**********************************************************/


int main(){
    int choice=0;
       
    cout<<"[1] binary to decimal [2] grade [3] decimal to binary [4] standard [5] exit"<<endl;
    cin>>choice;
   
        if (choice == 1){
            string binarynum = get_binarynum();
            int ans = bin_to_dec(binarynum);
            cout<<"Binary number: "<<ans<<endl;
            cout<<endl;
        }
        if(choice == 2){
            get_grade();
        }
        if (choice == 3){
            int he =  dec_to_bin();
            cout<<"Decimal number: "<<he<<endl;
        }
       
     
return 0; 
} 
