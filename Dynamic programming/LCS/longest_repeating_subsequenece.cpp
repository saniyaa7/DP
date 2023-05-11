#include<iostream>
using namespace std;
int LCS(string a,string b,int n)
{
    int t[n+1][n+1];
    for(int i=0;i<n+1;i++)
    {
        t[i][0]=0;
        t[0][i]=0;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(a[i-1]==b[j-1]&&i!=j)
                t[i][j]=1+t[i-1][j-1];
            else
                t[i][j]=max(t[i][j-1],t[i-1][j]);
        }
    }
return t[n][n];
}
int main()
{
    string s="axxxxy";
    cout<<LCS(s,s,s.size());
}