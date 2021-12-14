#include<bits/stdc++.h>
using namespace std;

int nWays(int n){
    if(n<0) return 0;
    if(n==0) return 1;
    else return nWays(n-1)+nWays(n-2)+nWays(n-3); 
}

int main(){
    int n;
    cin>>n;
    int ans = nWays(n);
    cout<<ans<<endl;
    return 0;
}