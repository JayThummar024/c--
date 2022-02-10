#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int LRS(string s1,string s2,int n,int m){
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1] and i!=j){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}



int main(){
    string s = "AABEBCDD";
    memset(dp,-1,sizeof(dp));
    cout<<LRS(s,s,s.length(),s.length());

    return 0;
}