/*
Common in 3 Sorted Arrays
Difficulty: EasyAccuracy: 22.16%Submissions: 456K+Points: 2
Given three sorted arrays in non-decreasing order, return all common elements in non-decreasing order across these arrays. If there are no such elements return an empty array.
Note: Ignore duplicates, include each common element only once in the output.

Examples :

Input: a[] = [1, 5, 10, 20, 40, 80], b[] = [6, 7, 20, 80, 100], c[] = [3, 4, 15, 20, 30, 70, 80, 120]
Output: [20, 80]
Explanation: The elements 20 and 80 appear in all three arrays a, b, and c, making them the only common elements, so the output is [20, 80].
Input: a[] = [1, 2, 3, 4, 5], b[] = [6, 7], c[] = [8, 9, 10]
Output: []
Explanation: Since none of the elements in arrays a, b, and c appear in all three arrays, there are no common elements, so the output is [].
Input:  a[] = [1, 1, 1, 2, 2, 2], b[] = [1, 1, 2, 2, 2], c[] = [1, 1, 1, 1, 2, 2, 2, 2]
Output: [1, 2]
Explanation: Ignoring duplicates, 1 and 2 are present in all three arrays, so the output is [1, 2]

*/


#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int i=0,j=0,k=0;
        vector<int>ans;
        int n1=a.size(),n2=b.size(),n3=c.size();
        while(i<n1 && j<n2 && k<n3){
            if(a[i]==b[j] && b[j]==c[k]){
                
                if(ans.empty() || ans.back()!=a[i]){       //avoid duplicates
                ans.push_back(a[i]);    
                }
                
                i++;
                j++;
                k++;
            }else if(a[i]<b[j]){
                i++;
            }else if(b[j]<c[k]){
                j++;
            }else{
                k++;
            }
        }
        return ans;
    }
};