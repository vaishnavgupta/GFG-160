#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<vector<char>>& board,int row,int col,string word,int idx){
        //Recursive Function
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col]=='#' || board[row][col]!=word[idx]){
            return false;
        }
        if(idx == word.length()-1) return true;

        //Marking visited
        char ch = word[idx];
        board[row][col] = '#';

        bool ans = isPossible(board,row+1,col,word,idx+1) ||
        isPossible(board,row,col+1,word,idx+1) ||
        isPossible(board,row-1,col,word,idx+1) ||
        isPossible(board,row,col-1,word,idx+1); 

        //Restoring word
        board[row][col] = ch;

        return ans;       
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0] && isPossible(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};