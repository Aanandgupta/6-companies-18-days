// M items are to be delivered in a circle of 
// size N. Find the position where the M-th item will be d
// elivered if we start from a given position K. Note that items are distributed at adjacent positions starting from K.


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int findPosition(int N , int M , int K) {
        // code here
        if(M+K-1<=N)
        {
            return M+K-1;
        }
        
        M=M-(N-K+1);
        return M%N==0?N:M%N;
    }
};
