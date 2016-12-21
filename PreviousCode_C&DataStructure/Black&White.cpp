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

int bigger_number(int x,int y,int b, int w);



int absolute(int x,int y);

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int b;
        int w;
        cin >> b >> w;
        int x;
        int y;
        int z;


        long int cost;
        int smaller;
        cin >> x >> y >> z;

        
        if(z <= absolute(x,y)){
            cost = (x>y?y:x) * (b + w) + bigger_number(x,y,b,w) * z;
        }
        else
            cost = x*b + y*w;

        cout<<cost<<endl;
    }


    return 0;
}

int bigger_number(int x,int y,int b,int w){
    if(x > y)
        return b;
    else
        return w;
}

int absolute(int x,int y){
    if (x - y < 0)
        return (y - x);
    else 
        return (x - y);
}