#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solveNQueens(int n) {
        //initialize the res
        int res = 0;
        vector<string>  ans(n, string(n, '.'));

        //start of the backtracking
        solver(res, ans, n, 0);

        return res;

    }


    void solver(int  &res, vector<string> &s, int n, int row_num){
        if(row_num == n){
            res++;
            return;
        }

        for(int i = 0; i < n; i++){
            //cout<<row_num<<" "<<i<<endl;
            s[row_num][i] = 'Q';

            if ( row_check(s, row_num, i) && line_check(s, row_num, i) && slant_check(s, row_num, i)  ){
                solver(res, s, n, row_num + 1);
            }

            s[row_num][i] = '.';
        }

        return;
    }

    bool row_check(vector<string> s, int row, int col) {
        bool res = true;
        int n = s.size();
        int counter;

        for(int j = col - 1; j >= 0; j--){
            if(s[row][j] == 'Q'){
                res = false;
                return res;
            }
        }
        return res;
    }

    bool line_check(vector<string> s, int row, int col){
        bool res = true;
        int n = s.size();
        int counter;

        for(int i = row - 1; i >= 0; i--){
            if(s[i][col] == 'Q'){
                res = false;
                return res;
            }
        }

        return res;
    }

    bool slant_check(vector<string> s, int row, int col){
        int n = s.size();
        int counter;

        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if(s[i][j] == 'Q')
                return false;
        }

        for(int i = row - 1, j = col + 1; i >=0 && j < n; i--, j++){
            if(s[i][j] == 'Q')
                return false;
        }

        return true;
    }


};

int main(){
    string a = "Q...";
    string s = "Q..Q";
    string d = "....";
    string f  = "....";

    vector<string> test;
    test.push_back(a);
    test.push_back(s);
    test.push_back(d);
    test.push_back(f);

    Solution so;
    //cout<<so.line_check(test, 2, 3)<<endl;

    int res = so.solveNQueens(4);

    cout<<res<<endl;

}
