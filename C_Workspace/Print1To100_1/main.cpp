#include <iostream>

using namespace std;

void print_num(int n){
    if(n>10)
        return;
    else{
        cout<<n++<<" ";
        print_num(n);
    }


}

int main()
{
    print_num(0);
}
