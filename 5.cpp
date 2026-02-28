/*Day 5  : Reverse Array

📌 Problem: Reverse the Array (In‑Place)

Think about:
* Can you solve it without using an extra array?
* Use one pointer at the start and one at the end
* Swap elements and move inward

Example:
Input: [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]


*/

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
    void reverseArray(vector<int>&nums){
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        //since the return is void we wont return anything
    }
};