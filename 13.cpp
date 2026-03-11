/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

find the missing number

*/

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int findmissingnum(vector<int>&nums){
        int n=nums.size();
        int totalsum=n*(n-1)/2;
        int currentsum=0;
        int missingnum=-1;
        for(int i=0;i<n;i++){
            currentsum+=nums[i];
            missingnum=totalsum-currentsum;
        }
        return missingnum;
    }
};