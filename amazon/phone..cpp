// 

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        map <string,int> store;
        vector<vector<string>>  ans(s.size());
        int j;
        for(int i=0;i<n;i++)
        {
            for(j=0;j<s.size() and j<contact[i].size();j++)
            {
                if(contact[i][j]!=s[j])
                {
                    break;
                }
            }
            store[contact[i]]=j;
        }
        
        for(int i=0;i<s.size();i++)
        {
            int temp=1;
            for(auto x:store)
            {
                if(x.second>0)
                {
                    ans[i].push_back(x.first);
                    store[x.first]-=1;
                    temp=0;
                }
            }
            if(temp)
            {
                while(i<s.size())
                {
                    ans[i].push_back("0");
                    i++;
                }
                break;
            }
        }
        
        return ans;
    }
};