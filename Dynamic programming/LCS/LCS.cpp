#include<bits/stdc++.h>
using namespace std;
const int MAX=1000;
// int LCS(string a,string b,int m,int n)
// {
//     if(m==0||n==0)
//         return 0;
//     if(a[m-1]==b[n-1])
//         return 1+LCS(a,b,m-1,n-1);
//     else
//         return max(LCS(a,b,m,n-1),LCS(a,b,m-1,n));
// }



// int LCS(string a,string b,int m,int n,int t[][MAX])
// {
//     if(m==0||n==0)
//         return 0;
    
//       if(t[m-1][n-1]!=-1)
//         return t[m-1][n-1];
//      if(a[m-1]==a[n-1]){
//         t[m-1][n-1]=1+LCS(a,b,m-1,n-1,t);
//         return t[m-1][n-1];

//      }
        
     
//     else
//     {t[m-1][n-1]=max(LCS(a,b,m,n-1,t),LCS(a,b,m-1,n,t));
//          return t[m-1][n-1];
//     }
       

// }


int LCS(string a,string b,int m,int n)
{
    int t[m+1][n+1];
    for(int i=0;i<m+1;i++)
        t[i][0]=0;
    for(int j=0;j<n+1;j++)
        t[0][j]=0;
    
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
    return t[m][n];
}

int main()
{
    string a="abcddefghij";
    string b="ecdig";
    //int t[a.size()][MAX];
    //memset(t,-1,sizeof(t));
    cout<<LCS(a,b,a.size(),b.size());

}