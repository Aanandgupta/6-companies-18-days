// Maximum of all subarrays of size k 
// Medium Accuracy: 44.42% Submissions: 58182 Points: 4
// Given an array arr[] of size N and an integer K. Find the maximum for each and every contiguous subarray of size K.

// Example 1:

// Input:
// N = 9, K = 3
// arr[] = 1 2 3 1 4 5 2 3 6
// Output: 
// 3 3 4 5 5 5 6 
// Explanation: 
// 1st contiguous subarray = {1 2 3} Max = 3
// 2nd contiguous subarray = {2 3 1} Max = 3
// 3rd contiguous subarray = {3 1 4} Max = 4
// 4th contiguous subarray = {1 4 5} Max = 5
// 5th contiguous subarray = {4 5 2} Max = 5
// 6th contiguous subarray = {5 2 3} Max = 5
// 7th contiguous subarray = {2 3 6} Max = 6

#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque <int> store;
        vector <int> ans;
        for(int i=0;i<k;i++)
        {
            while(!store.empty() and arr[store.back()]<=arr[i])
            {
                store.pop_back();
            }
            store.push_back(i);
        }
        
        
        for(int i=k;i<n;i++)
        {
            ans.push_back(arr[store.front()]);
            
            
            while(!store.empty() and store.front()<=i-k)
            {
                store.pop_front();
            }
            while(!store.empty() and arr[store.back()]<=arr[i])
            {
                store.pop_back();
            }
            store.push_back(i);
            
        }
        
        ans.push_back(arr[store.front()]);
        return ans;
    }
};