#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int LCS_memoization(string X,string Y,int i,int j){ //TLE in leetcode
    if(i==0 or j==0){
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    if(X[i-1]==Y[j-1]){
        dp[i][j] = 1+LCS_memoization( X,Y ,i-1,j-1 );
    }else{
        dp[i][j] = max(LCS_memoization(X,Y,i,j-1) , LCS_memoization(X,Y,i-1,j));
    }
    return dp[i][j];
}

int LCS_tabulation(string X,string Y,int i,int j){// Accepted in leetcode
    for(int x=0;x<=i;x++){
        dp[x][0] = 0;
    }
    for(int x=0;x<=j;x++){
        dp[0][x] = 0;
    }

    for(int x=1;x<=i;x++){
        for(int y=1;y<=j;y++){
            if(X[x-1]==Y[y-1]){
                dp[x][y] = 1+dp[x-1][y-1];
            }else{
                dp[x][y] = max(dp[x-1][y] , dp[x][y-1]);
            }
        }
    }
    return dp[i][j];
}


int main(){
    string X = "abecdef";
    string Y = "abcefdxf";
    int i = X.length();
    int j = Y.length();
    memset(dp,-1,sizeof(dp));

    cout << LCS_memoization(X,Y,i,j) << endl;
    cout << LCS_tabulation(X,Y,i,j) << endl;

    return 0;
}