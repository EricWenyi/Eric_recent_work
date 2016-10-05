#include <iostream>
#include<bits/stdc++.h>

using namespace std;

class MinStack {
private:
    stack<int> sta;
    stack<int> minstack;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        sta.push(number);
        if(minstack.empty()){
            minstack.push(number);
        }
        else{
            int temp = minstack.top();
            if(temp > number)
                minstack.push(number);
            else
                minstack.push(temp);
        }

    }

    int pop() {
        // write your code here
        int results = sta.top();
        sta.pop();
        minstack.pop();
        return results;
    }

    int min() {
        // write your code here
        int result = minstack.top();
        return result;
    }
};


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
