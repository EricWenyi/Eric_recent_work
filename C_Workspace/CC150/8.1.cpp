#include<iostream>

using namespace std;

int WaysToSteps(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	else if(n == 2) return 2;
	else if(n == 3) return 4;

	int * a = new int[n+1];
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;

	for(int i = 4; i < n+1; i++){
		a[i] = a[i-1] + a[i-2] + a[i-3]; 
	}
	return a[n];

}

int main(){
    int res = WaysToSteps(5);
    cout<<res<<endl;

    return 0;
}
