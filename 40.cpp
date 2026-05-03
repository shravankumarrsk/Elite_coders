/* 
edit distance


*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i<0) return j+1;  //if s1 is empty then we need to insert all characters of s2 to make them equal
        if(j<0) return i+1;  //if s2 is empty then we need to delete all characters of s1 to make them equal
        if(dp[i][j]!=-1) return dp[i][j];  //if we have already computed the answer for this subproblem, return it
        if(s1[i]==s2[j]) return dp[i][j]=f(i-1,j-1,s1,s2,dp);  //if the characters are the same, we can move to the next character in both strings
        return dp[i][j]=1+min(   //if the characters are different, we can either insert a character, delete a character, or replace a character
            f(i-1,j,s1,s2,dp),
            min(
                f(i,j-1,s1,s2,dp),
                f(i-1,j-1,s1,s2,dp))
            );
    }
    int minDistance(string word1, string word2) {  //the main function that initializes the dp table and calls the recursive function
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};