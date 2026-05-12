/*
46. Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
*/


//leetcode for the integer array, we can use set to avoid duplicates and then convert it to vector of vector and return the answer.

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void solve(vector<int>& nums,int l, int r,set<vector<int>>& ans){
        int i;
        if(l==r){
            ans.insert(nums);
            return;
        }
        
        for(i=l;i<=r;i++){
            swap(nums[l],nums[i]);
            solve(nums,l+1,r,ans);
            swap(nums[i],nums[l]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>>st;
        solve(nums,0,nums.size()-1,st);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};




// geeksforgeeks solution for the same problem is as follows: but it for the strings and it uses backtracking to generate all the permutations of the string.

class Solution {
  public:
    void permute(string s,int l, int r,set<string>& ans){
        int i;
        if(l==r){
            ans.insert(s);
            return;
        }
        
        for(i=l;i<=r;i++){
            swap(s[l],s[i]);
            permute(s,l+1,r,ans);
            swap(s[i],s[l]);
        }
    }

    vector<string> findPermutation(string &s) {
        set<string>st;
        permute(s,0,s.length()-1,st);
        vector<string>ans(st.begin(),st.end());
        return ans;
    }
};
