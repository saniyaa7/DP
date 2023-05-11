#include<iostream>
#include<algorithm>
using namespace std;
void printLCS(string a,string b,int m,int n)
{
    int t[m+1][n+1];
    for(int i=0;i<m+1;i++)
        t[i][0]=0;
    for(int i=0;i<n+1;i++)
        t[0][i]=0;
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(a[i-1]==b[j-1])
                t[i][j]=1+t[i-1][j-1];
            else 
                t[i][j]=max(t[i][j-1],t[i-1][j]);
        }

    }
    string result="";
    int i=m,j=n;
    while(i>0&&j>0)
    {
        if(a[i-1]==b[j-1])
        {
            result.push_back(a[i-1]);
            i--;
            j--;
        }
        else
        {
            if(t[i][j-1]>t[i-1][j])
                j--;
            else
                i--;
        }

    }
    reverse(result.begin(),result.end());
    cout<<result;
}
int main ()
{
    string a="acbcf";
    string b="abcdaf";
    printLCS(a,b,a.size(),b.size());
}