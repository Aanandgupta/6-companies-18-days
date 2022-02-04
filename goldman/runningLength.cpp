// Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
// eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
// You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.

#include <bits/stdc++.h>
using namespace std;

string encode(string src)
{     
  //Your code here
  int i=0;
  string ans="";
  while(i<src.size())
  {
      int n=1;
      int j=i;
      while(j<src.size()-1 and src[j]==src[j+1])
      {
          n++;
          j++;
      }
      ans.push_back(src[i]);
      ans.push_back(n+'0');
      i=j+1;
  }
  return ans;
}    