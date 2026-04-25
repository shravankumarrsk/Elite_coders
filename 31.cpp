/*45. Jump Game II
Medium
Topics
premium lock icon
Companies
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.
 
Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2*/





// jump game 
/*You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxindex=0;
        for(int i=0;i<n;i++){
            if(i>maxindex) return false;
            maxindex=max(maxindex,i+nums[i]);
        }
        return true;
    }
};





//jump game 2

/*45. Jump Game II
Medium
Topics
premium lock icon
Companies
You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.
 
Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2*/



class Solution {
public:
    int jump(vector<int>& nums) {
       int n=nums.size();
       int destination=n-1;
       int totaljumps=0, maxjump=0,lastjump=0;
       if(n==1)return 0;
       for(int i=0;i<n;i++){
        maxjump=max(maxjump,i+nums[i]);
        if(i==lastjump) {
            lastjump=maxjump;
            totaljumps++;

            if(maxjump>=destination){
                return totaljumps;
            }
        }
       }
       return totaljumps;
    }
};