#include<bits/stdc++.h>
using namespace std;
//int size;
// void menset(int wt[size],int val[size],int w)
// {
//     int t[size+1][w+1];
//     for(int i=0;i<size+1;i++)
//     {
//         for(int j=0;j<w+1;j++)
//         t[i][j]=-1;
//     }
//     cout<<knapsack(wt,val,w,size,t);
// }

// int knapsack(int wt[],int val[],int w,int n)
// {
//     if(n==0||w==0)
//         return 0;
//     if(wt[n-1]<=w)
//     return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
//     else if(wt[n-1]>w)
//     return knapsack(wt,val,w,n-1);
// }




// int knapsack(int wt[size],int val[size],int w,int n,int t[size][])
// {
//     if(n==0||w==0)
//         return 0;
//         if(t[n][w]!=-1)
//             return t[n][w];
//     if(wt[n-1]<=w)
//     return t[n-1][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1,t),knapsack(wt,val,w,n-1,t));
//     else if(wt[n-1]>w)
//     return t[n-1][w]=knapsack(wt,val,w,n-1,t);
// }
int knapsack(int wt[],int val[],int w,int n)
{
    int t[n+1][w+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
            if(i==0||j==0)
                t[i][j]=0;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
            if(wt[i-1]<=j)
            t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            else
            t[i][j]=t[i-1][j];
        }
    }
     for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
           
               cout<< t[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl<<endl;
    return t[n][w];
}
int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int w=7;
    int size=sizeof(wt)/sizeof(wt[0]);
    // menset(wt,val,w);
    

   
   cout<<knapsack(wt,val,w,size);
}