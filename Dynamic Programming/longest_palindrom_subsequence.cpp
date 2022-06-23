#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int LPS(string s1,string s2,int n,int m){
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}


int main(){
    string s1 = "gabaaccba";
    string s2(s1);
    reverse(s2.begin(),s2.end());
    // cout<<s2<<endl;

    cout<<LPS(s1,s2,s1.length(),s2.length());
    return 0;
}