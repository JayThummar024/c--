#include <bits/stdc++.h>
using namespace std;

int dp[505][505];

int LCS(string X,string Y,int i,int j){
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
    string s = "acbdbda";
    string s2(s);
    reverse(s.begin(),s.end());
    int i = s.length();
    int j = s2.length();

    cout << i - LCS(s,s2,i,j);

    return 0;
}