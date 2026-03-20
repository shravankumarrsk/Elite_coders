/*Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]


spiral matrix


*/
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    vector<int>spiralorder(vector<vector<int>>&matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>ans;
        int top=0,bottom=m-1,left=0,right=n-1;
        while(top<=bottom && left<=right){
            for(int i=0;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
            }
        }
        return ans;
    }
};