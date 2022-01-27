#include<bits/stdc++.h>
using namespace std;


int unbounded_knapsack_recursive(int val[],int wt[],int W,int n,int idx,vector<vector<int>> &dp){
    if(W==0) return 0;
    if(idx==0) return 0;
    if(dp[idx][W]!=-1) return dp[idx][W];

    if(wt[idx-1]<=W){
        return dp[idx][W] = max( val[idx-1] + unbounded_knapsack_recursive(val,wt,W-wt[idx-1] ,n,idx,dp) ,  unbounded_knapsack_recursive(val,wt,W,n,idx-1,dp));
    }else{
        return dp[idx][W] = unbounded_knapsack_recursive(val,wt,W,n,idx-1,dp);
    }
    return dp[idx][W];
}

int tabulation(int val[],int wt[],int W,int n,vector<vector<int>> &dp){
    for(int i=0;i<W+1;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = max( dp[i-1][j] , val[i-1] + dp[i][j-wt[i-1]]);
            }
        }
    }
    return dp[n][W];
}

int main(){

    int val[] = {5,3,1,4};
    int wt[] = {4,3,2,3};
    int W = 10;
    int n = sizeof(val)/sizeof(val[0]);
    vector<vector<int>> dp(n+1 ,vector<int> (W+1,-1));
    // cout<<unbounded_knapsack_recursive(val,wt,W,n,n,dp)<<endl;
    cout<<tabulation(val,wt,W,n,dp)<<endl;

    // for(auto i:dp){
    //     for(auto j:i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}