#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //There are total 8 directions in which queen can clash
    //But only three directions we need to check
    //TopLeftDiagonal & Left & BottomLeftDiagonal
    //As we are moving from 0 to last

    //isPossible --> Not efficient
    bool isPossible(vector<string>& board,int row,int col){
        int r = row;
        int c = col;
        //TopLeftDiagonal
        while(r>=0 && c>=0){
            if(board[r][c] == 'Q') return false;
            r--;c--;
        }
        r = row;
        c = col;
        //Left
        while(r>=0 && c>=0){
            if(board[r][c] == 'Q') return false;
            c--;
        }
        r = row;
        c = col;
        //BottomLeftDiagonal
        while(r<board.size() && c>=0){
            if(board[r][c] == 'Q') return false;
            c--;r++;
        }
        return true;
    }

    void solve(int col,vector<string>& board,vector<vector<string>>& ans,int n){
        if(col == n){
            //everything done
            //push in ans
            ans.push_back(board);
            return;
        }

        //check each column
        for(int i=0;i<n;i++){
            if(isPossible(board,i,col) == true){
                board[i][col] = 'Q';
                solve(col+1,board,ans,n);
                board[i][col] = '.'; //Removing so that it will not affect others
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s(n,'.');
        vector<vector<string>> ans;
        vector<string> board(n);
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,board,ans,n);
        return ans;
    }
};