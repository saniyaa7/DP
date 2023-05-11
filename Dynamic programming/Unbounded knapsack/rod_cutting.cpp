#include<iostream>
using namespace std;
int main()
{
    int price[]={1,5,8,9,10,17,17,20};
    int y=8,n=sizeof(price)/sizeof(price[0]);
    int t[n+1][y+1];
    for(int i=0;i<n+1;i++)
        t[i][0]=0;
    for(int i=0;i<y+1;i++)
        t[0][i]=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<y+1;j++)
        {
            if(i<=j)
            {
                t[i][j]=max(price[i-1]+t[i][j-i],t[i-1][j]);
            }
            else
                t[i][j]=t[i-1][j];
        }
    }
    cout<<t[n][y];
}