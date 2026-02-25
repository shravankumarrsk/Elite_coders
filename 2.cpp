/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

/* brute force approach */

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    void movezeros(vector<int>&nums){
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                for(int j=i+1;j<n;j++){
                    if(nums[j]!=0){
                        swap(nums[i],nums[j]);
                        break;
                    }
                }
            }
        }
    }
};



/*optimal solution*/

class solution{
    public:
    void movezeros(vector<int>&nums){
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};
