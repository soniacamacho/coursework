#include "./create.h"
using namespace std;

int main(){
    Pizza p;
    cout<<p.get_name()<<endl;
    cout<<p.get_num_ingredients()<<endl;

    p.set_name("mushrooms");
    p.set_num_ingredients(8);

    cout<<p.get_name()<<endl;
    cout<<p.get_num_ingredients()<<endl;
    
    return 0;
}
