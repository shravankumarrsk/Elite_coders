/*
Smallest subarray with sum greater than x


Difficulty: EasyAccuracy: 37.07%Submissions: 159K+Points: 2Average Time: 20m
Given a number x and an array of integers arr, find the smallest subarray with sum greater than the given value. If such a subarray do not exist return 0 in that case.

Examples:

Input: x = 51, arr[] = [1, 4, 45, 6, 0, 19]
Output: 3
Explanation: Minimum length subarray is [45, 6]
Input: x = 100, arr[] = [1, 10, 5, 2, 7]
Output: 0
Explanation: No subarray exist
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        int n=arr.size();
        int cursum=0;
        int minlen=n+1;
        int start=0,end=0;
        while(end<n){
            while(cursum<=x && end<n){
                cursum+=arr[end++];
            }
            while(cursum>x && start<n){
                
                // for cheking the min subarray
                if(end-start<minlen){  //checks the length of array
                    minlen=end-start;  //calculates the length of array
                }
                cursum-=arr[start++];
            }
        }
        return minlen;
    }
};