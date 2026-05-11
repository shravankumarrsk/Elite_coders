/*
Roman to integer
Convert a Roman numeral to an integer.

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.
Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

*/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int romantoint(string s){
        unordered_map<char, int> str={
            {'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D',500},{'M', 1000}
        };
        int total=0;
        for(int i=0;i<s.size();i++){
            if(i+1<s.size() && str[s[i]]<str[s[i+1]]){
                total-=str[s[i]];
            }else{
                total+=str[s[i]];
            }
        }
        return total;
    }
};