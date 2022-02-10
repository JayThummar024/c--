#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int LCS_tabulation(string X,string Y,int i,int j){
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

string print_SCS(string X,string Y,int i,int j){
    string ans = "";
    while(i!=0 and j!=0){
        cout<<i<<" "<<j<<endl;
        if(X[i-1]==Y[j-1]){
            ans += X[i-1];
            i--;
            j--;
        }else if(dp[i-1][j]>dp[i][j-1]){
            ans = ans + X[i-1];
            i--;
        }else{
            ans = ans + Y[j-1];
            j--;
        }
    }
    while(i!=0){
        ans+=X[i-1];
        i--;
    }
    while(j!=0){
        ans+=Y[j-1];
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string X = "abac";
    string Y = "cab";
    int i = X.length();
    int j = Y.length();
    memset(dp,-1,sizeof(dp));

    cout<<"Length of SCS : "<<i+j-LCS_tabulation(X,Y,i,j)<<endl;
    cout << print_SCS(X,Y,i,j);

    return 0;
}