/*
Code
Testcase
Testcase
Test Result
215. Kth Largest Element in an Array
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int k_largest=-1;
        for(int i=n-k;i>=0;i--){
            if(nums[i]!=k_largest){
                k_largest=nums[i];
                break;
            }
        }
        return k_largest;
    }
};




//new type of approach
class solution{
    public:
    int findkthlargest(vector<int>& nums,int k){
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};