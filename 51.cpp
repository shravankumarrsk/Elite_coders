/*
. Longest Palindromic Substring

Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string expand(string s,int left,int right){
        while(left>=0 && right< s.size() && s[left]==s[right] ){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.size();i++){
            string odd=expand(s,i,i);
            string even=expand(s,i,i+1);
            if(odd.size()>ans.size()){
                ans=odd;
            }
            if(even.size()>ans.size()){
                ans=even;
            }
        }
        return ans;
        
    }
};