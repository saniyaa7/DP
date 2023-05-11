#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>mp;
int solve(string s,int i,int j,bool isTrue)
{
    if(i>j)
    return 0;
    if(i==j)
    {
        if(isTrue)
        return s[i]=='T';
        else
        return s[i]=='F';
    }
    string tmp=to_string(i);
    tmp.push_back(' ');
    tmp.append(to_string(j));
     tmp.push_back(' ');
      tmp.append(to_string(isTrue));

      if(mp.find(tmp)!=mp.end())
        return mp[tmp];

    int ans=0;
    for(int k=i+1;k<=j-1;k=k+2)
    {
        int lt=solve(s,i,k-1,true);
        int lf=solve(s,i,k-1,false);
        int rt=solve(s,k+1,j,true);
        int rf=solve(s,k+1,j,false);

        if(s[k]=='&')
    {
        if(isTrue)
        ans=ans+lt*rt;
        else
        ans=ans+(lt*rf)+(lf*rt)+(lf*rf);
    }
    else if(s[k]=='|')
    {
        if(isTrue)
        ans=ans+(lt*rt)+(lt*rf)+(lf*rt);
        else
        ans=ans+(lf*rf);
    }
    else if(s[k]=='^')
    {
        if(isTrue)
        ans=ans+(lt*rf)+(lf*rt);
        else
        ans=ans+(lt*rt)+(lf*rf);
    }
    }
    return mp[tmp]=ans;
}
int main()
{
    string s="T&F|T^F";
    cout<<solve(s,0,s.size()-1,true);

}