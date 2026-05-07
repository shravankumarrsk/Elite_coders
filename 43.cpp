/*
767. Reorganize String

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

 

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reorganizeString(string s) {

        // Step 1: Store frequency of characters
        vector<int> freq(26, 0);

        for(char c : s) {
            freq[c - 'a']++;
        }

        // Step 2: Find character with maximum frequency
        int maxi = 0;
        int letter = 0;

        for(int i = 0; i < 26; i++) {

            if(freq[i] > maxi) {
                maxi = freq[i];
                letter = i;
            }
        }

        // Step 3: Check if answer is possible
        if(maxi > (s.size() + 1) / 2) {
            return "";
        }

        // Step 4: Create answer string
        string ans(s.size(), ' ');

        // Step 5: Fill most frequent character first
        int idx = 0;

        while(freq[letter]-- > 0) {

            ans[idx] = letter + 'a';

            idx += 2;
        }

        // Step 6: Fill remaining characters
        for(int i = 0; i < 26; i++) {

            while(freq[i]-- > 0) {

                // If even indices are filled,
                // start filling odd indices
                if(idx >= s.size()) {
                    idx = 1;
                }

                ans[idx] = i + 'a';

                idx += 2;
            }
        }

        return ans;
    }
};