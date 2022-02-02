#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> ary{12,3,4,3,5,35454546,6,6,56,5,656,56,56,5,75,7,76,45,656,5,653,6,56,456,6,56,4,547,6,7,4637,67,6437,467};
    priority_queue <int,vector<int>,greater <int>> store;
    for(int i=0;i<10;i++)
    {
        store.push(ary[i]);
    }
    for(int i=10;i<ary.size();i++)
    {
        if(store.top()<ary[i])
        {
            store.pop();
            store.push(ary[i]);
        }
    }

    for(int i=0;i<10;i++)
    {
        cout<<store.top()<< " ";
        store.pop();
    }
    
    return 0;
}