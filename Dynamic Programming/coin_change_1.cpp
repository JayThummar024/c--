#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int coinChange(vector<int> &coins,int sum,int n){
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=sum;j++){
        dp[0][j] = INT_MAX-1;
    }
    for(int j=1;j<=sum;j++){
        if(j%coins[0]==0){
            dp[1][j] = j/coins[0];
        }else{
            dp[1][j] = INT_MAX-1;
        }
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coins[i-1]<=j){
                dp[i][j] = min(dp[i-1][j] , 1+dp[i][j-coins[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}


int main(){
    vector<int> coins = { 2,4,9,1};
    int sum = 10;
    int n=coins.size();
    for(int i=0;i<=coins.size();i++){
        vector<int> temp;
        for(int j=0;j<=sum;j++){
            temp.push_back(INT_MAX-1);
        }
        dp.push_back(temp);
    }
    cout << coinChange(coins,sum,n);

    return 0;
}