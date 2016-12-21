#include <iostream>

using namespace std;

int main()
{
    int length, left_num;

    cin>>length;
    cin>>left_num;
    int a[length];
    int b[length];

    for (int i = 0; i < length; i++){
        cin>>a[i];
    }

    for (int i = 0; i < length; i++){
        b[i] = a[(i + left_num) % length];
    }

    for (int i = 0; i < length; i++){
        cout<<b[i]<<" ";
    }
}
