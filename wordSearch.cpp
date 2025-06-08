#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void solve(int row,int col,vector<vector<char>>& mat,vector<vector<bool>>& isVisited,string& word,int n,int m,bool &flag){
        if(word == ""){
            flag = true;
            return;
        }
        if(row<0 || col<0 || row>=n || row>=m){
            return;
        }
        if(mat[row][col] == word[0]){
            char ch = word[0];
            word = word.substr(1);
            isVisited[row][col] = true;
            if(row-1>=0) solve(row-1,col,mat,isVisited,word,n,m,flag);
            if(col-1>=0) solve(row,col-1,mat,isVisited,word,n,m,flag);
            if(row+1<n) solve(row+1,col,mat,isVisited,word,n,m,flag);
            if(col+1<m) solve(row,col+1,mat,isVisited,word,n,m,flag);
            //Restoring
            word = ch + word;
            isVisited[row][col] = false;
        }
        else{
            if(row-1>=0) solve(row-1,col,mat,isVisited,word,n,m,flag);
            if(col-1>=0) solve(row,col-1,mat,isVisited,word,n,m,flag);
            if(row+1<n) solve(row+1,col,mat,isVisited,word,n,m,flag);
            if(col+1<m) solve(row,col+1,mat,isVisited,word,n,m,flag);
        }
    }
    
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        bool flag = false;
         solve(0,0,mat,visit,word,n,m,flag);
        return flag;
    }
};