// You may recall that an array arr is a mountain array if and only if:

// arr.length >= 3
// There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given an integer array arr, return the length of the longest subarray, which is a mountain. Return 0 if there is no mountain subarray.
// Input: arr = [2,1,4,7,3,2,5]
// Output: 5
// Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int i=1,ans=0;
        while(i<arr.size()-1)
        {
            if(arr[i-1]<arr[i] and arr[i]>arr[i+1])
            {
                int x=i,j=i;
                while(x>0 and arr[x]>arr[x-1])
                {
                    x--;
                }
                while(j<arr.size()-1 and arr[j+1]<arr[j])
                {
                    j++;
                }
                ans=max(ans,j-x+1);
                i=j+1;
                    
            }
            else{
                i++;
            }
        }
        return ans;
    }
};