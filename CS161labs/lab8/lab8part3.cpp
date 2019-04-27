#include <iostream>
#include <cstring>
using namespace std;

void get_replace_str_dyn(char* array, char* replace){
    for (int i = 0; i < strlen(array);i++){
        replace[i] = array[i];
    }
    for (int i = 0; i < strlen(array) ; i++){
        if ((int)array[i] != 32){
            replace[i] = '-';
        }
    }
}
int get_search_replace_dyn(char guess , char* array, char* replace){
    cout<<endl;
    cout<<"Enter a character to search for: ";
    cout<<endl;
    cin>>guess;
    int count = 0;
    for (int i =0; i <strlen(array);i++){
        if ((int)array[i] ==(int)guess){
            replace[i] = guess;
            count ++;
        }
    }
    cout<<endl;
    for (int i = 0; i<strlen(array);i++){
        cout<<replace[i];
    }
    cout<<endl;
    return count;
}

int main() {
    cout<<"How many characters would you like?"<<endl;
    int number = 0;
    cin>>number;
    int len = number+1;
    char *array = new char[len];
    cout<<"please enter a string"<<endl;
    while(cin.get() != '\n');
    cin.getline(array,len);
    char replace[len];
    char guess =' ' ;
    get_replace_str_dyn(array,replace);
    bool flag;
    do{
        cout << get_search_replace_dyn(guess,array,replace) ;
        flag = true;
        for (int i =0; i <=256 ;i++){
            if ((int)replace[i] == 45){
                flag = false;
            }
        }    
    }
    while (flag == false);
    delete [] array;
    
    return 0;
}
