#include <iostream>
#include <cstring>
using namespace std;

void get_string (char *str){
    cout<<"enter a string"<<endl;   
    cin.getline(str,256);
}
/********************************************************/

void set_replace_string(char *str, char *str2){
    strcpy(str2,str);
    cout<<*str2<<endl;
    int len = sizeof(str)/sizeof(char);
    for (int i =0; i< strlen(str);i++){
        if (str[i] == 32){
            str2[i] = ' ';
        }
        else{
            str2[i] = '_';
        }
    }
}
 
/********************************************************/
int get_search_replace(char h, char *str,char *str2){
    int count =0;
    cout<<"input a character"<<endl;
    cin>>h;
    for (int j = 0;j<strlen(str);j++){
        if (str[j] == h){
            str2[j] = h;
            count ++;
        }
    }
    for (int i =0 ; i < strlen(str2);i++){
        cout<<str2[i];
    }
    

return count;
}

int main (){
    char *str = new char[256];
    char *str2 = new char[256];
   
    char h = ' ';
    get_string(str);
    set_replace_string(str,str2);
   cout<< get_search_replace(h,str,str2)<<endl;
cout<<endl;
return 0;
}
