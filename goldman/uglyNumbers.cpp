// Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number.

// Example 1:

// Input:
// N = 10
// Output: 12
// Explanation: 10th ugly number is 12.

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    
	    //generate all prime numbers till n
	    vector <ull> store(n,0);
	    int l=0,j=0,k=0;
	    store[0]=1;
	    for(int i=1;i<n;i++)
	    {
	        store[i]=min(store[j]*2,min(store[k]*3,store[l]*5));
	        if(store[i]==store[j]*2)
	        j++;
	        if(store[i]==store[k]*3)
	        k++;
	        if(store[i]==store[l]*5)
	        l++;
	
	    }
	    
	    return store[n-1];
	}
};