#include<iostream>
using namespace std;
int main()
{
    int coin[]={1,2,3};
    int sum=3,n=sizeof(coin)/sizeof(coin[0]);
    int t[n+1][sum+1];

    
    for(int i=0;i<sum+1;i++)
        t[0][i]=0;
        for(int i=0;i<n+1;i++)
        t[i][0]=1;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(coin[i-1]<=j)
                t[i][j]=t[i][j-coin[i-1]]+t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }
    cout<<t[n][sum];
}