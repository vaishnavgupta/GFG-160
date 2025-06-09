#include<bits/stdc++.h>
using namespace std;


/*
    Here we need to find all possible combinations 
    We will put all possible numbers from (1to9) in the cell
    if it is possible we will continue the recursion and if not
    we will terminate and then move to next iteration
*/

class Solution {
  public:
    // Function to find a solved Sudoku.
    bool solve(vector<vector<int>> &mat){

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){

                if(mat[i][j] == 0){
                    //Putting till 1-9
                    for(int k=1;k<=9;k++){
                        if(isPossible(mat,i,j,k)){
                            mat[i][j] = k;

                            if(solve(mat) == true) return true;  //check for next
                            else{
                                mat[i][j] = 0;
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;  //for last case when no 0 are left
    }

    bool isPossible(vector<vector<int>>& mat,int row,int col,int ele){
        for(int i=0;i<9;i++){
            if(mat[row][i] == ele) return false;
            if(mat[i][col] == ele) return false;

            //for sub-box
            if(mat[3*(row/3) + i / 3][3*(col/3) + i % 3] == ele) return false;   //imp
        }
        return true;
    }

    void solveSudoku(vector<vector<int>> &mat) {
    
        solve(mat);
        
    }
};