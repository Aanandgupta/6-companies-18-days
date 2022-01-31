
// Count the subarrays having product less than k


#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long count=0;
        long long currentCount=0;
        long long mul=1; 
        for(int start=0,end=0;end<a.size();end++)
       {
           
           mul*=a[end];
           while(start<=end and mul>=k){
               mul/=a[start++];
           }
           
           count+=end-start+1;
       }
        return count;
    }
};

// https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#