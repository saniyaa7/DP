
#include<bits/stdc++.h>
using namespace std;
int static t[1001][1001];
// int solve(int arr[],int i,int j)
// {
//     if(i>=j)
//         return 0;
//         int mini=INT_MAX;
//     for(int k=i;k<=j-1;k++)
//     {
//         int tmp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
//         if(tmp<mini)
//             mini=tmp;
//     }
//     return mini;
// }

int solve(int arr[],int i,int j)
{
    if(i>=j) return 0;
    if(t[i][j]!=-1)
        return t[i][j];
         int mini=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int tmp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(tmp<mini)
            mini=tmp;
    }
    return t[i][j]=mini;
}
int main()
{
    memset(t,-1,sizeof(t));
    int arr[]={40,20,30,10,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<solve(arr,1,n-1);
}