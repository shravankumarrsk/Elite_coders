/*
Search Pattern

Given two strings, a text string txt and a pattern string pat, both consisting of lowercase English alphabets. Return the starting indices (0-based) of all the occurrences of the pattern string pat in the text string txt.

Note: Return an empty list in case of no occurrences of pattern.

Examples:

Input: txt = "geeksforgeeks", pat = "geek"
Output: [0, 8]
Explanation: The string "geek" occurs twice in txt, one starts at index 0 and the other at index 8.
Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int>search(string &pat, string &text){
        //vector<int>ans;
        int n=text.size();
        int m=pat.size();
        vector<int>lps(m,0);
        int len=0;
        int i=1;
        while(i<m){
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len!=0){
                    len=lps[len-1];
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        vector<int>res;
        i=0;
        int j=0;
        while(i<n){
            if(pat[j]==text[i]){
                i++;
                j++;
            }
            if(j==m){
                res.push_back(i-j);
                j=lps[j-1];
            }else if(i<n && pat[j]!=text[i]){
                if(j!=0){
                    j=lps[j-1];
                }else{
                    i++;
                }
            }
        }
        return res;
    }

};