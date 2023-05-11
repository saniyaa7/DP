// #include<bits/stdc++.h>
// using namespace std;
// bool isPalindrome(string s,int  i,int j)
// {
//     if(i==j) return true;
//     if(i>j) return true;
//     while(i<j)
//     {
//         if(s[i]!=s[j])
//             return false;
//         i++;
//         j--;
//     }
//     return true;
// }
// int solve(string s,int i,int j)
// {
//     if(i>=j) return 0;
//     if(isPalindrome(s,i,j)) return 0;
//     int mn=INT_MAX;
//     for(int k=i;k<j;k++)
//     {
//         int tmp=1+solve(s,i,k)+solve(s,k+1,j);
//         if(tmp<mn)
//             mn=tmp;
//     }
//     return mn;
// }
// int main()
// {
//     string s="nitin";
//     cout<<solve(s,0,s.size()-1);
// }
