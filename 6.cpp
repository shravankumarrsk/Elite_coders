/* Given an integer array nums, find a subarray that has the largest product, and return the product.

The test cases are generated so that the answer will fit in a 32-bit integer.

Note that the product of an array with a single element is the value of that element.

 

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.


..........Maximum product subarray......

*/


//otpimal solution
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    int maxproduct(vector<int>&nums){
        int n=nums.size();
        int maxi=INT_MIN;
        int prefix=1;
        int suffix=1;
        for(int i=0;i<n;i++){
            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            }
            prefix*=nums[i];
            suffix*=nums[n-1-i];
            maxi=max(maxi,max(prefix,suffix));
        }
        return maxi;
    }
};