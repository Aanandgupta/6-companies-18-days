

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
    
    
    vector<vector<string> > Anagrams(string & string_list) {
        //code here
        vector<vector <string>>  ans;
        // vector<vector <string>>  temp;
        int index=0;
        unordered_map <string,vector<string>> anagrams;
        unordered_map <int,string> order;
        unordered_set <string> store;
        for(int i=0;i<string_list.size();i++)
        {
            for(int j=1;j<=string_list.size()-i;j++)
            {
            string s=getAscii(string_list.substr(i,j));
            anagrams[s].push_back(string_list.substr(i,j));
            // order[index++]=s;
            }
        }
        // for(int j=0;j<string_list.size();j++)
        // {
        //     if(store.find(order[j])==store.end())
        //     {
        //         ans.push_back(anagrams[order[j]]);
        //         store.insert(order[j]);
        //     }
        // }

        for(auto i=anagrams.begin();i!=anagrams.end();i++)
        {
            if(i->second.size()>1)
            {
                for(int j=0;j <i->second.size();j++)
                {
                    cout << i->second[j]<< " ";
                }
                cout << endl;
            }
        }
        return ans;
    }
};


int main()
{
    Solution ob;
    vector<vector <string>>  ans;
    string s="abba";
    ans=ob.Anagrams(s);
  
    return 0;
}