#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    vector<int>v;
    cout<<"Push back"<<endl;
    for (int i =0; i < 10 ; i++){
        v.push_back(i);
        cout<<"size: "<<v.size()<<endl;
        cout<<"capacity: "<<v.capacity()<<endl;
    }
    cout<<endl;
    cout<<"pop back"<<endl;
    for(int i =0; i <10;i++){
        v.pop_back();
        cout<<"size: "<<v.size()<<endl;
        cout<<"capacity: "<<v.capacity()<<endl;
}
return 0;
}

