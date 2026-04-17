/*Allocate Minimum Pages
Difficulty: MediumAccuracy: 35.51%Submissions: 387K+Points: 4
Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
All books must be allocated.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: If it is not possible to allocate books to all students, return -1.

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
=> [12] and [34, 67, 90] Maximum Pages = 191
=> [12, 34] and [67, 90] Maximum Pages = 157
=> [12, 34, 67] and [90] Maximum Pages = 113.
The third combination has the minimum pages assigned to a student which is 113.
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.*/


/*  this is same as the partition painters problem */

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPossible(vector<int>&arr,int m,int n,int maxtime){
        int books=1;
        long long time=0;
        for(int i=0;i<n;i++){
            if(time+arr[i]<=maxtime){
                time+=arr[i];
            }else{
                books++;
                time=arr[i];
            }
        }
        return books<=m;
    }
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>n) return -1;
        long long sum=0;
        int maxval=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            maxval=max(maxval,arr[i]);
        }
        int start=maxval;
        int end=sum;
        int ans=-1;
        
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(arr,k,n,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};