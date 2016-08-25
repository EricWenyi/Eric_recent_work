#include <iostream>
#include<bits/stdc++.h>

using namespace std;



class Solution {
public:
    bool isValid(vector<char> arr) {

        int Hash_table[9] = {0};

        for(size_t i = 0; i < arr.size(); i++){
            if(arr[i] != '.'){
                Hash_table[arr[i] - 49]++;
            }
        }

        for(int i = 0; i < 9; i++){
            if(Hash_table[i] > 1)
                return false;
        }

        return true;
    }

    bool isValidSudoku( vector< vector<char> > &board) {
        //first we check rolls

//        for(size_t i = 0; i < board.size(); i++){
//            if(! isValid(board[i])){
//                return false;
//            }
//        }

        //check cols

//        for(int i = 0; i < 9; i++){
//            vector<char> temp;
//            for(int j = 0; j < 9; j++){
//                temp.push_back(board[i][j]);
//            }
//            if(!isValid(temp)){
//                return false;
//            }
//            temp.clear();
//        }

        //then we check the blocks
        for(int p = 0; p < 9; p = p + 3){
            for(int q = 0; q < 9; q = q+ 3){
                vector<char> temp;
                for(int i = 0; i < 3; i++){
                    for(int j = 0; j < 3; j++){
                        temp.push_back(board[i + p][j + q]);
                    }
                }
                if(!isValid(temp)){
                    return false;
                }
            }
        }

        return true;
    }
};


int main()
{
    char num[9] = {'1','1','.','3','4','5','6','7','8'};
    vector<char> arr1 (num, num + sizeof(num) / sizeof(char) );
    vector<char> arr2 (num, num + sizeof(num) / sizeof(char) );
    vector<char> arr3 (num, num + sizeof(num) / sizeof(char) );
    vector<char> arr4 (num, num + sizeof(num) / sizeof(char) );
    vector<char> arr5 (num, num + sizeof(num) / sizeof(char) );
    vector<char> arr6 (num, num + sizeof(num) / sizeof(char) );
    vector<char> arr7 (num, num + sizeof(num) / sizeof(char) );
    vector<char> arr8 (num, num + sizeof(num) / sizeof(char) );
    vector<char> arr9 (num, num + sizeof(num) / sizeof(char) );

    vector<vector<char> > arr;
    arr.push_back(arr1);
    arr.push_back(arr2);
    arr.push_back(arr3);
    arr.push_back(arr4);
    arr.push_back(arr5);
    arr.push_back(arr6);
    arr.push_back(arr7);
    arr.push_back(arr8);
    arr.push_back(arr9);


    Solution s;
    cout<<s.isValidSudoku(arr)<<endl;
}
