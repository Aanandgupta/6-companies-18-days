// Given an array of positive integers nums and a positive integer target, 
// return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr]
//  of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int minimum=INT_MAX;
        for(int start=0,end=0;end<nums.size();end++)
        {
            sum+=nums[end];
            while(sum-nums[start]>=target)
            {
                sum-=nums[start++];
            }
            if(sum>=target)
            {
                minimum=min(minimum,end-start+1);
            }
        }
        
        return (minimum==INT_MAX?0:minimum);
        
    }
};