/*
Common elements in all given rows of matrix
Input:
mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

Output: 
1 8 or 8 1
8 and 1 are present in all rows.
*/

#include<bits/stdc++.h>
using namespace std;
void printcommonelements(int mat[5][6],int m,int n){
    unordered_map<int,int>mp;
    for(int j=0;j<m;j++){
        mp[mat[0][j]]==1;
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            if(mp[mat[i][j]]==i){
                mp[mat[i][j]]=i+1;

                if(i==m-1 && mp[mat[i][j]]==m){
                    cout<<mat[i][j] <<"";
                }
            }
        }
    }
}


/*
Can we do better than O(mnlogn)? 
The idea is to use maps. We initially insert all elements of the first row in an map. For every other element in remaining rows, we check if it is present in the map. If it is present in the map and is not duplicated in current row, we increment count of the element in map by 1, else we ignore the element. If the currently traversed row is the last row, we print the element if it has appeared m-1 times before. 
*/