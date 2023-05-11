#include<bits/stdc++.h>
using namespace std;
//int t[100][100];


// bool subsetSum(int arr[],int sum,int n)
// {
//     if(sum==0)
//     return true;
//     if(n==0)
//     return false;
    
//      if(arr[n-1]>sum)
//         return subsetSum(arr,sum,n-1);
    
//         return subsetSum(arr,sum-arr[n-1],n-1)||subsetSum(arr,sum,n-1);
   
// }


// bool subsetSum(int arr[],int sum,int n)
// {
//     if(sum==0)
//     return true;
//     if(n==0)
//     return false;
//     if(t[n-1][sum]!=-1)
//         return t[n-1][sum];
//      if(arr[n-1]>sum)
//         return t[n-1][sum]=subsetSum(arr,sum,n-1);
    
//         return t[n-1][sum]=subsetSum(arr,sum-arr[n-1],n-1)||subsetSum(arr,sum,n-1);
   
// }

bool subsetSum(int arr[],int sum,int n)
{
    bool t[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            t[i][j]=false;

            if(j==0)
            t[i][j]=true;
           

        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
           cout<<t[i][j]<<" ";

        }
        cout<<endl<<endl;
    }
    
    return t[n][sum];
}
int main()
{

    int arr[]={2,3,7,8,10};
    int sum=12;
   // memset(t,-1,sizeof(t));
    cout<<subsetSum(arr,sum,sizeof(arr)/sizeof(arr[0]));
}