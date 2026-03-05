/* maximum sum circular subArray
   
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.


*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalsum=0;
        int maxsum=nums[0];
        int curmax=0;
        int minsum=nums[0];
        int curmin=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
            curmax=max(nums[i],curmax+nums[i]);
            maxsum=max(curmax,maxsum);
            curmin=min(nums[i],curmin+nums[i]);
            minsum=min(curmin,minsum);

        }
        if(maxsum<0)
            return maxsum;
        
        return max(totalsum-minsum,maxsum);
    }
};