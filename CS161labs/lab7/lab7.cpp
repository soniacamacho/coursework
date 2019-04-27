#include <iostream>
#include <string>
using namespace std;


/********************************************************/
void get_string (string * str){
   cout<<"enter a string"<<endl;   
   getline(cin,*str);
}
/********************************************************/

void set_replace_string(string  str, string * str2){
    * str2 = str;
    //cout<<*str2<<endl;
    for (int i =0; i< str.length();i++){
        if (str[i] == 32){
            (*str2) [i] = ' ';
        }
        else{
            (*str2)[i] = '_';
        }
        
    }
}
 
/********************************************************/
int get_search_replace(char h, string str,string & str2){
    int count =0;
    cout<<"input a character"<<endl;
    cin>>h;
    for (int j = 0;j<str.length();j++){
        if (str[j] == h){
            str2[j] = h;
            count ++;
        }
    }
cout<<str2<<endl;
return count;
}

/********************************************************/
int main (){
    string str = "";
    string str2 = "";
    char h = ' ';
    get_string(&str);
    set_replace_string(str,&str2);
    cout<<get_search_replace(h,str,str2)<<endl;
return 0;
}    
