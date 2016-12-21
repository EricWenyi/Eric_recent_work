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


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    
    for(int i = 0; i<n; i++){
    	if(s[i]>='a' && s[i] <= 'z'){
    		if(s[i] + k > 'z'){
                s[i] = (s[i] + k)%122 + 96;
            }
            else
                s[i] += k;
    	}
        else if(s[i]>='A' && s[i] <= 'Z'){
            if(s[i] + k > 'Z'){
                s[i] = (s[i] + k)%90 + 64;
            }
            else
                s[i] += k;
        }
    }

    for (int i = 0; i<n; i++){
    	cout<<s[i];
    }

    
    return 0;
}
