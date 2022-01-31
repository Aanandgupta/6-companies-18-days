// Given an array of strings, return all groups of strings that are anagrams.


#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
  
    string getAscii(string s)
    {
        string ans="00000000000000000000000000";
    for(int i=0;i<s.size();i++)
    {

            int j=ans[s[i]-'a'];
            ans[s[i]-'a']=j+1;
    }
        return ans;
    }
    
    
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector <string>>  ans;
        // vector<vector <string>>  temp;
        int index=0;
        unordered_map <string,vector<string>> anagrams;
        unordered_map <int,string> order;
        unordered_set <string> store;
        for(int i=0;i<string_list.size();i++)
        {
            string s=getAscii(string_list[i]);
            anagrams[s].push_back(string_list[i]);
            order[i]=s;
        }
        for(int j=0;j<string_list.size();j++)
        {
            if(store.find(order[j])==store.end())
            {
                ans.push_back(anagrams[order[j]]);
                store.insert(order[j]);
            }
        }
        return ans;
    }
};