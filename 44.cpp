/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
     string longestCommonPrefix(vector<string>& strs){
        if(strs.empty()) return "";
        string result="";
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        for(int i=0;i<strs.size();i++){
            if(first[i]!=last[i]){
            break;
            result.push_back(first[i]);
        }
    }
        return result;
     }
};