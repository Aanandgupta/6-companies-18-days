// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

// Example 1:

// Input:
// N = 2
// Arr[] = {2, 2}
// Output: 2 1
// Explanation: Repeating number is 2 and 
// smallest positive missing number is 1


#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int sum=0;
        int prod=1;
        int *ans=new int[2];
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[abs(arr[i])-1]<0)
            {
                ans[0]=abs(arr[i]);
                // break;
            }
            else{
                
            arr[abs(arr[i])-1]=-1*arr[abs(arr[i])-1];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                ans[1]=i+1;
            }
        }
        return ans;
    }
};

