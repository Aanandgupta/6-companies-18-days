// Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

// Example 1 :

// Input : arr = [9, 5, 7, 3], k = 6
// Output: True
// Explanation: {(9, 3), (5, 7)} is a 
// possible solution. 9 + 3 = 12 is divisible
// by 6 and 7 + 5 = 12 is also divisible by 6.


// https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map <int,int> store;
        if(nums.size()%2!=0)
        {
            return false;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%k==0)
            {
                if(store.find(0)!=store.end() and store[0]!=0)
                {
                 store[0]-=1;   
                }
                else{
                    store[0]+=1;
                }
            }
            else if(store.find(k-(nums[i]%k))!=store.end() and store[k-(nums[i]%k)]!=0)
            {
                store[k-nums[i]%k]-=1;
            }
            else{
                store[nums[i]%k]+=1;
            }
        }
        
        for(auto it=store.begin();it!=store.end();it++)
        {
            if(it->second>0)
            {
                return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends