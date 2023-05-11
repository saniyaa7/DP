#include<iostream>
using namespace std;
int count(int arr[],int n,int sum)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
        t[i][0]=1;
    for(int i=1;i<sum+1;i++)
        t[0][i]=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int arr[]={1,1,2,3};
    int diff=1;
    int sum=0,n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        sum+=arr[i];
    int s1=(diff+sum)/2;
    cout<<count(arr,sizeof(arr)/sizeof(arr[0]),s1);
}