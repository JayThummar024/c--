#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int dp[10005][10005];

int LC_substring(string s1,string s2,int n,int m,int l){ //memoization
    if(s1.length()==n or s2.length()==m) return 0;

    if(dp[n][m]!=-1) return dp[n][m];
    
    if(s1[n]==s2[m]){
        ans = max(ans,l+1);
        dp[n][m] = ans;
        LC_substring(s1,s2,n+1,m+1,l+1);
    }else{
        dp[n][m] = ans = max({ans,LC_substring(s1,s2,n+1,m,0),LC_substring(s1,s2,n,m+1,0)});
    }
    
    return dp[s1.length()-1][s2.length()-1];
}

int main(){

    string s1 = "abcbe";
    string s2 = "abccbe";
    memset(dp,-1,sizeof(dp));
    cout << LC_substring(s1,s2,0,0,0);
    return 0;
}