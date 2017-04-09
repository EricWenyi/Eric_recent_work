#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector< vector<string> > solveNQueens(int n) {
        vector< vector<string> > res;

        vector<string>  ans;
        string s = "";

        //generate origin chessboard
        for(int i = 0; i < n; i++){
            s += ".";
        }
         for(int i = 0; i < n; i++){
                ans.push_back(s);
         }

         solver(res, ans, n, 0);

         return res;

    }


    void solver(vector<vector<string> > res, vector<string> s, int n, int row_num){
        if(row_num >= n){
            res.push_back(s);
            return;
        }

        for(int i = 0; i < n; i++){
            s[row_num][i] = 'Q';
//            if ( !row_check(s) && !line_check(s) && !slant_check(s)  ){
//                ;
//            }
        }
    }

    bool row_check(vector<string> s) {
        bool res = true;
        int n = s.size();
        int counter;

        for(int i = 0; i < n; i++){
            counter = 0;
            for(int j = 0; j < n; j++){
                if(s[i][j] == 'Q')
                    ++counter;
            }

            cout<<counter<<endl;
            if(counter > 1)
                res = false;
        }

        return res;
    }


};

int main(){
    string s = "....";
    string a = "...Q";
    string d = ".Q.Q";
    string f  = "....";

    vector<string> test;
    test.push_back(a);
    test.push_back(s);
    test.push_back(d);
    test.push_back(f);

    Solution so;
    bool res = so.row_check(test);
}
