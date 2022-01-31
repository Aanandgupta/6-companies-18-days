// Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

// Example 1 :

// Input : arr = [9, 5, 7, 3], k = 6
// Output: True
// Explanation: {(9, 3), (5, 7)} is a 
// possible solution. 9 + 3 = 12 is divisible
// by 6 and 7 + 5 = 12 is also divisible by 6.

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


// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#