#include<bits/stdc++.h>
using namespace std;

int dp[4][6];

int coinChange_recur(int coins[],int n,int sum){
    if(sum==0){
        return 1;
    }
    if(n==0) return 0;
    if(dp[n][sum]!=-1) return dp[n][sum];
    if(coins[n-1]<=sum){
        dp[n][sum]=coinChange_recur(coins,n-1,sum) + coinChange_recur(coins,n,sum-coins[n-1]);
    }else{
        dp[n][sum]=coinChange_recur(coins,n-1,sum);
    }
    return dp[n][sum];
}

int coin_change(int coins[],int n,int sum){
    for(int i=0;i<=sum;i++){
        dp[0][sum]=0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1]<=j){
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main(){
    int coins[] = {1,2,3};
    int sum = 5;
    memset(dp,0,sizeof(dp));
    int n = sizeof(coins)/sizeof(coins[0]);
    // cout << coinChange_recur(coins,n,sum) <<endl;
    cout << coin_change(coins,n,sum) <<endl;
   
    return 0;
}