#include<bits/stdc++.h>
using namespace std;


int dp[1005][1005];
int knapsack(int val[],int wt[],int W,int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
            else if(j < wt[i-1]){
                dp[i][j] = dp[i-1][j];  
            }else{
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j-wt[i-1]] + val[i-1] );
            }
        }
    }
    return dp[n][W];
}



int main(){
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    memset(dp,-1,sizeof(dp));
    cout << knapsack(val,wt,W,n);
    return 0;
}