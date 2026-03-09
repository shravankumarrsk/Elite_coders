/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2


find the duplicate number

*/

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int findduplicate(vector<int>&nums){
        int q=nums.size();
        sort(nums.begin(),nums.end());
        int duplicate=nums[0];
        for(int i=0;i<q-1;i++){
            if(nums[i]==nums[i+1]){
                duplicate=nums[i];
            }
        }
        return duplicate;
    }
};