// Decode the string 
// Easy Accuracy: 58.15% Submissions: 4659 Points: 2
// An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
// original string: abbbababbbababbbab 
// encoded string : 3[a3[b]1[ab]]

// Example 1:

// Input: s = 1[b]
// Output: b
// Explaination: 'b' is present only one time.

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    string decodedString(string s){
        // code here
        stack <char> store;
        string temp="";
        string temp1="";
        int temp2=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==']')
            {
                temp1="";
                while(store.top()!='[')
                {
                    temp1=store.top()+temp1;
                    store.pop();
                }
                store.pop();
                temp2=0;
                int i=1;
                while(!store.empty() and store.top()>='0' and store.top()<='9')
                {
                    temp2=(store.top()-'0')*i+temp2;
                    store.pop();
                    i*=10;
                }
                int j=temp2;
                temp="";
                while(j>0)
                {
                    temp+=temp1;
                    j--;
                }
                for(int x=0;x<temp.size();x++)
                {
                    store.push(temp[x]);
                }
                
            }
            else{
            store.push(s[i]);
            }
            
        }
            return temp;
    }
};