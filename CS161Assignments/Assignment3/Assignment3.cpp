 /************************************************************
 * ** program:error handling 
 * ** Author:Sonia Camacho
 * ** Date:1-30-18
 * ** Description:In this program we are making functions for the 16 parts that are in the pdf 
 * ** Input:
 * ** Output: 
 * *********************************************************/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
/********************************************************************
** function:check_range
** description:I will be checking if a test value is in between the min and max
** Parameters:lower bound,upper bound,test value
** Pre-Conditions: variables have to be integers
** Post-Conditions: returning a boolian 
*********************************************************************/
 bool check_range(int lower_bound, int upper_bound, int test_value){
    if (test_value < lower_bound){
        return false;
    }
    else if (test_value > upper_bound){
        return false;
    }
    else {
        return true;
    }
}

/********************************************************************
** function:is_int
** description:checks a string to see if it is an integer
** Parameters:string num
** Pre-Conditions:num must be a string
** Post-Conditions:boolean return
*********************************************************************/
bool is_int(string num){
    for (int i=0;i<num.length();i++){
        if (num[i]<'0' or num[i]>'9'){
            return false;
        }
    }   
    return true;
}
/********************************************************************
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
** function:is_capital
** description:checks a character to see if its capital
** Parameters:char letter
** Pre-Conditions:letter must be a char
** Post-Conditions:boolean return
****************************************************************/
bool is_capital (char letter){
    if (letter >=65 and letter<=90){
        return true;
    }
    else{
        return false;
    }
} 
/********************************************************************
** function:is_even
** description:checks to see if an int is even
** Parameters:int num
** Pre-Conditions:num must be an int
** Post-Conditions:boolean return
*********************************************************************/
 
bool is_even(int num){
    if (num % 2==0){
        return true;
    }
    else{
        return false;
    }
}
/********************************************************************
** function:is_odd
** description:checks to see if an int is odd
** Parameters:int num
** Pre-Conditions:int must be a num
** Post-Conditions:boolean return
*********************************************************************/
 
bool is_odd(int num){
    if (num % 2==1){
        return true;
    }
    else{
        return false;
    }
}
/********************************************************************
** function:equality_test
** description:checks 2 numbers and will print out int values for whatever their relationship is
** Parameters:int num 1 int num2
** Pre-Conditions:they must be integers
** Post-Conditions:integer output of 0,1,-1
*********************************************************************/
int equality_test(int num1, int num2){
    if (num1 < num2){
        return -1;
    }
    else if(num1==num2){
        return 0;
    }
    else{
        return 1;
    }
}
/********************************************************************
** function:float is equal
** description:checks 2 floats and sees if they are in the precision of eahcohther
** Parameters:num1 num2 precision
** Pre-Conditions:must be floats
** Post-Conditions:boolean return
*********************************************************************/
bool float_is_equal(float num1, float num2, float precision){
    float result=(num1-num2);
    if (abs(result) == precision){
        return true;
    }
    else{
        return false;
    }
} 

/********************************************************************
** function:numbers_present
** description:checks to see if there are numbers in a string
** Parameters:string sentence
** Pre-Conditions:must be a string
** Post-Conditions:boolean return
*********************************************************************/
bool numbers_present(string sentence){
    for(int i=0;i<sentence.length();i++){
        if (sentence[i]>='0' and sentence[i]<='9'){
            return true;
        }
           
    }
    return false;
     
 
}

/********************************************************************
** function:letters present
** description:checks a string to see if there are any letters in it
** Parameters:string sentence
** Pre-Conditions:must be a stirng
** Post-Conditions:boolean return
*********************************************************************/
bool letters_present(string sentence){
    for (int i=0;i<sentence.length();i++){
        if(sentence[i]<=90 and sentence[i]>=65){
            return true;
        } 
        if(sentence[i]<=97 and sentence[i]>=122){
            return true;
        }
    }
    return false;
        
}

/********************************************************************
** function:contains sub string
** description:checks one string to see if another one is in it
** Parameters:sentence , sub string
** Pre-Conditions:must be strings
** Post-Conditions:boolean return 
*********************************************************************/
bool contains_sub_string(string sentence, string sub_string){
    bool h=false;
    int len=sentence.length()-sub_string.length();
    for (int i=0; i<len; i++){
        if (sentence[i]==sub_string[0]){
            h=true;
            for(int j=0;j<sub_string.length();j++){
                if (sentence[i+j]!= sub_string[j]){
                    h=false;
                }
            }
            if (h==true){
                return h;
            }   
        }     
    }   
return h;
}

/********************************************************************
** function:word count
** description:checks how many words are in a sentence
** Parameters:sentence
** Pre-Conditions:must input a string
** Post-Conditions:integer return
*********************************************************************/
int word_count(string sentence){
    int count=1;
    for (int i=0;i<sentence.length();i++){
        if(sentence[i]==32){
        count=count+1;
        }
    }
return count;
}

/********************************************************************
** function:to upper
** description:makes a sentence all upper case
** Parameters:sentence 
** Pre-Conditions:must be a string
** Post-Conditions:string return
****************************************************************/
string to_upper(string sentence){
    for (int i=0; i<sentence.length();i++){
        if (sentence[i]>=97 and sentence[i]<=122){
            char newChar =(char)(((int)sentence[i])-32);
            sentence[i]= newChar;
        }
    }
    return sentence;
} 
 
/********************************************************************
** function:to lower
** description:makes a string all lowercase
** Parameters:sentece
** Pre-Conditions:must be string
** Post-Conditions:string return
*********************************************************************/
string to_lower(string sentence){
     for (int i=0; i<sentence.length();i++){
        if (sentence[i]>=65 and sentence[i]<=90){
            char newChar =(char)(((int)sentence[i])+32);
            sentence[i]= newChar;
        }
    }
    return sentence;
}

/********************************************************************
** function:get int 
** description:takes a prompt then gets user input to find int
** Parameters:string prompt
** Pre-Conditions:must be string
** Post-Conditions:integer return
*********************************************************************/
 
int get_int(string prompt){
    string t;
    bool in = false;

    cout<<prompt<<endl;
    while (in == false){
        getline(cin, t);
        in = is_int(t);
        if(in == false){
            cout<<"bad input try again."<<endl;
        }
    }
    int var=0;
    int exp=0;
    for(int i= t.length()-1; i>=0 ; i--){
        var+=(((int)t[i])-48)*pow(10,exp);
        exp++;
    }

return var;
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


   
/****************************************************************/





 int main(){
    
/****************************************************************/
    cout<<endl;
    cout<<"Testing check_range() "<<endl;
    cout<<"input: \"1 , 10 ,5 \" , expected output: true, Actual output: "<<endl;
    cout<<check_range(1,10,5)<<endl;
    if (check_range(1,10,5)){
        cout<<"True, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing check_range() "<<endl;
    cout<<"input: \"1 , 5 ,10 \" , expected output: false, Actual output: "<<endl;
    cout<<check_range(1,5,10)<<endl;
    if (check_range(1,5,10)){
        cout<<"True, FAIL"<<endl;
    }
    else{
        cout<<"False, PASS"<<endl;
    }   
/****************************************************************/
    cout<<endl;
    cout<<"Testing is_int() "<<endl;
    cout<<"input: \"987\", expected output: true, Actual output: "<<endl;
    cout<<is_int("987")<<endl;
    if (is_int("987")){
        cout<<"True, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing is_int() "<<endl;
    cout<<"input: \"hello\", expected output: false, Actual output: "<<endl;
    cout<<is_int("hello")<<endl;
    if (is_int("hello")){
        cout<<"True, FAIL"<<endl;
    }
    else{
        cout<<"False, PASS"<<endl;
    }
/************************************************************/
    cout<<"testing is_float() "<<endl;
    cout<<"input: \".89\" , expected output: true, Actual output: "<<endl;
    cout<<is_float(".89")<<endl;
    if(is_float(".89")){
        cout<<"true, PASS"<<endl;
    }
    else{
        cout<<"false, FAIL"<<endl;
    }
    cout<<endl;

    cout<<"testing is_float() "<<endl;
    cout<<"input: \"hello\" , expected output: false, Actual output: "<<endl;
    cout<<is_float("hello")<<endl;
    if(is_float("hello")){
        cout<<"true, FAIL"<<endl;
    }
    else{
        cout<<"false, PASS"<<endl;
    }
   
/***************************************************************/
    cout<<endl;
    cout<<"Testing is_capital() "<<endl;
    cout<<"input: \"H \", expected output: True , Actual output: "<<endl;
    cout<<is_capital('H')<<endl;
    if (is_capital('H')){
        cout<<"True, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing is_capital() "<<endl;
    cout<<"input: \"h \", expected output: false, Actual output: "<<endl;
    cout<<is_capital('h')<<endl;   
    if (is_capital('h')){
        cout<<"True, FAIL"<<endl;
    }
    else{
        cout<<"False, PASS"<<endl;
    } 
/****************************************************************/
    cout<<endl;
    cout<<"Testing is_even() "<<endl;
    cout<<"input:\"2\" , expected output: true, Actual output: "<<endl;
    cout<<is_even(2)<<endl;
    if (is_even(2)){
        cout<<"True, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing is_even() "<<endl;
    cout<<"input: \"3\" , expected output: false, Actual output: "<<endl;
    cout<<is_even(3)<<endl;   
    if (is_even(3)){
        cout<<"True, FAIL"<<endl;
    }
    else{
        cout<<"False, PASS"<<endl;
    } 
/*****************************************************************************/
    cout<<endl;
    cout<<"Testing is_odd() "<<endl;
    cout<<"input:\"3\" , expected output: true, Actual output: "<<endl;
    cout<<is_odd(3)<<endl;
    if (is_odd(3)){
        cout<<"True, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing is_odd() "<<endl;
    cout<<"input: \"2\" , expected output: false, Actual output: "<<endl;
    cout<<is_odd(2)<<endl;   
    if (is_odd(2)){
        cout<<"True, FAIL"<<endl;
    }
    else{
        cout<<"False, PASS"<<endl;
    } 
/*****************************************************************************/
    cout<<endl;
    cout<<"Testing equality_test() "<<endl;
    cout<<"input:\"5,5\" , expected output: 0, Actual output: "<<endl;
    cout<<equality_test(5,5)<<endl;
    if (equality_test(5,5)){
        cout<<"False, FAIL"<<endl;
    }
    else{
        cout<<"0, PASS"<<endl;
    }
    cout<<endl;
    cout<<"Testing equality_test() "<<endl;
    cout<<"input:\"6,4\" , expected output: 1, Actual output: "<<endl;
    cout<<equality_test(6,4)<<endl;
    if (equality_test(6,4)){
        cout<<"1, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing equality_test() "<<endl;
    cout<<"input: \"4,9\" , expected output: -1, Actual output: "<<endl;
    cout<<equality_test(4,9)<<endl;   
    if (equality_test(4,9)){
        cout<<"-1, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    } 
/*****************************************************************************/
    cout<<endl;
    cout<<"Testing float_is_equal() "<<endl;
    cout<<"input: \"5.50 , 5.25 ,0.25 \" , expected output: true, Actual output: "<<endl;
    cout<<float_is_equal(5.50,5.25,0.25)<<endl;
    if (float_is_equal(5.50,5.25,0.25)){
        cout<<"True, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing float_is_equal() "<<endl;
    cout<<"input: \"1.0 , 5.5 ,0.2 \" , expected output: false, Actual output: "<<endl;
    cout<<float_is_equal(1.0,5.5,0.2)<<endl;
    if (float_is_equal(1.0,5.5,0.2)){
        cout<<"True, FAIL"<<endl;
    }
    else{
        cout<<"False, PASS"<<endl;
    }   
/****************************************************************/
    cout<<endl;
    cout<<"Testing numbers_present() "<<endl;
    cout<<"input: \"Hello 56 \" , expected output: true, Actual output: "<<endl;
    cout<<numbers_present("Hello 56")<<endl;
    if (numbers_present("Hello 56")){
        cout<<"True, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing numbers_present() "<<endl;
    cout<<"input: \"Hello \" , expected output: false, Actual output: "<<endl;
    cout<<numbers_present("Hello")<<endl;
    if (numbers_present("Hello")){
        cout<<"True, FAIL"<<endl;
    }
    else{
        cout<<"False, PASS"<<endl;
    }   
/****************************************************************/
    cout<<endl;
    cout<<"Testing letters_present() "<<endl;
    cout<<"input: \"Hello 56 \" , expected output: true, Actual output: "<<endl;
    cout<<letters_present("Hello 56")<<endl;
    if (letters_present("Hello 56")){
        cout<<"True, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing letters_present() "<<endl;
    cout<<"input: \"98765 \" , expected output: false, Actual output: "<<endl;
    cout<<letters_present("98765")<<endl;
    if (letters_present("98765")){
        cout<<"True, FAIL"<<endl;
    }
    else{
        cout<<"False, PASS"<<endl;
    }   
/****************************************************************/
    cout<<endl;
    cout<<"Testing contains_sub_string() "<<endl;
    cout<<"input: \"hello world, hello \" , expected output: true, Actual output: "<<endl;
    cout<<contains_sub_string("hello world","hello")<<endl;
    if (contains_sub_string("hello world","hello")){
        cout<<"True, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing contains_sub_string() "<<endl;
    cout<<"input: \"hello world, today \" , expected output: false, Actual output: "<<endl;
    cout<<contains_sub_string("hello world","today")<<endl;
    if (contains_sub_string("hello world","today")){
        cout<<"True, FAIL"<<endl;
    }
    else{
        cout<<"False, PASS"<<endl;
    }
/****************************************************************/
    cout<<endl;
    cout<<"Testing word_count() "<<endl;
    cout<<"input:\"hello world\" , expected output: 2, Actual output: "<<endl;
    cout<<word_count("hello world")<<endl;
    if (word_count("hello world")){
        cout<<"2, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Testing word_count() "<<endl;
    cout<<"input:\"hello\" , expected output: 1, Actual output: "<<endl;
    cout<<word_count("hello")<<endl;
    if (word_count("hello")){
        cout<<"1, PASS"<<endl;
    }
    else{
        cout<<"False, FAIL"<<endl;
    } 
/*****************************************************************************/
    cout<<endl;
    cout<<"Testing to_upper() "<<endl;
    cout<<"input: \"Hello \", expected output: HELLO , Actual output: "<<endl;
    cout<<to_upper("Hello")<<endl;
        cout<<"HELLO, PASS"<<endl;
   
/****************************************************************/
    cout<<endl;
    cout<<"Testing to_lower() "<<endl;
    cout<<"input: \"HELLO \", expected output: hello , Actual output: "<<endl;
    cout<<to_lower("HELLO")<<endl;
        cout<<"hello, PASS"<<endl;
  
 
/****************************************************************/
    cout<<endl;   
    cout<<"Testing get_int"<<endl;
    cout<<get_int("Please Provide Input")<<endl;
 
/****************************************************************/
    cout<<endl;   
    cout<<"Testing get_float"<<endl;
    cout<<get_float("Please Provide Input")<<endl;








  return 0;
}
