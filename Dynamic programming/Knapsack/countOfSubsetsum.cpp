#include<iostream>
#include<algorithm>
using namespace std;
int countOfSubsetsum(int arr[],int sum,int n)
{
    int t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
        t[i][0]=true;
    for(int i=1;i<sum+1;i++)
        t[0][i]=false;
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
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
            cout<<t[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    return t[n][sum];
}
int main()
{
    int arr[]={0,1,1,1};
    sort(arr,arr+sizeof(arr)/sizeof(arr[0]),greater<int>());
    int sum=3;
    cout<<countOfSubsetsum(arr,sum,sizeof(arr)/sizeof(arr[0]));
}