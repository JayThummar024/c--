#include<bits/stdc++.h>
using namespace std;

int dp[9][9];

int cut_rod_recur(int profit[] , int lengths[] ,int len ,int n){
    if(n==0 or len==0){
        return 0;
    }
    if(dp[n][len]!=-1){
        return dp[n][len];
    }
    if(lengths[n-1] <= len ){
        return dp[n][len] = max( profit[n-1] + cut_rod_recur(profit,lengths, len-lengths[n-1],n) , cut_rod_recur( profit,lengths,len,n-1));

    }else{
        return dp[n][len] = cut_rod_recur(profit,lengths,len,n-1);
    }
}


int main(){
    int profit[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int l = sizeof(profit)/sizeof(profit[0]);
    int lengths[l];

    for(int i=0;i<l;i++){
        lengths[i] = i+1;
    }

    memset(dp,-1,sizeof(dp));   
    cout<< cut_rod_recur(profit,lengths,l,l);

    return 0;
}