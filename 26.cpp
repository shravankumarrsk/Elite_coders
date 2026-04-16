//partition painters problem
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    bool isPossible(vector<int>& arr, int m, int n, int maxTime) {
        int painters = 1;
        long long time = 0;

        for (int i = 0; i < n; i++) {
            if (time + arr[i] <= maxTime) {
                time += arr[i];
            } else {
                painters++;
                time = arr[i];
            }
        }

        return painters <= m;
    }

    int minTime(vector<int>& arr, int m) {
        int n = arr.size();

        if (m > n) return -1;

        long long sum = 0;
        int maxval = INT_MIN;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            maxval = max(maxval, arr[i]);
        }

        int start = maxval;
        int end = sum;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isPossible(arr, m, n, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};