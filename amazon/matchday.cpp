// IPL 2021 - Match Day 2 
// Medium Accuracy: 58.44% Submissions: 8712 Points: 4
// Due to the rise of covid-19 cases in India, this year BCCI decided to organize knock-out matches in IPL rather than a league.

// Today is matchday 2 and it is between the most loved team Chennai Super Kings
//  and the most underrated team - Punjab Kings. Stephen Fleming, the head coach of CSK, analyzing the batting stats of Punjab. 
//  He has stats of runs scored by all N players in the previous season and he wants to find the maximum score for each and every contiguous
//   sub-list of size K to strategize for the gam

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


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> ans;
        deque <int> Q(k);
        for(int i=0;i<k;i++)
        {
            while(!Q.empty() and arr[i]>arr[Q.back()])
            {
                Q.pop_back();
            }
            Q.push_back(i);
        }
        for(int i=k;i<n;i++)
        {
            ans.push_back(arr[Q.front()]);
            
            while(!Q.empty() and Q.front()<=i-k)
            {
                Q.pop_front();
            }
            while(!Q.empty() and arr[i]>arr[Q.back()])
            {
                Q.pop_back();
            }
            Q.push_back(i);
        }
        ans.push_back(arr[Q.front()]);
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends