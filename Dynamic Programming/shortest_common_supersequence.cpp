#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

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
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    //supersequence is : AGGXTXAYB which contains both strings
    int i = X.length();
    int j = Y.length();
    memset(dp,-1,sizeof(dp));

    cout<<"Length of SCS : "<<i+j-LCS_tabulation(X,Y,i,j);

    return 0;
}