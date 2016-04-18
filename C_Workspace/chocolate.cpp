#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int Chocolate_can_be_exchanged(int Chocolate_bought, int Wrappers_needed);
int main(){
    int t;
    cin >> t;
    int n[t];
    int c[t];
    int m[t];
    for(int a0 = 0; a0 < t; a0++){
        
        cin >> n[a0] >> c[a0] >> m[a0];
    }
    int i = 0;

    for (i = 0; i<t; i++){
        int c_bought;
        int c_exchanged;

        c_bought = n[i]/c[i];
        c_exchanged = Chocolate_can_be_exchanged(c_bought,m[i]);
        cout<<c_bought + c_exchanged<<endl;
    }

    return 0;
}

int Chocolate_can_be_exchanged(int Chocolate_bought, int Wrappers_needed){
    int Chocolate_exchanged;
    int Wrappers_left;
    Chocolate_exchanged = Chocolate_bought / Wrappers_needed;
    Wrappers_left = Chocolate_bought % Wrappers_needed;

    if (Chocolate_exchanged + Wrappers_left >= Wrappers_needed){
        Chocolate_exchanged += Chocolate_can_be_exchanged(Chocolate_exchanged + Wrappers_left, Wrappers_needed);
    }

    return Chocolate_exchanged;
}