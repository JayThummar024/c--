#include<bits/stdc++.h>
using namespace std;




int main(){
    int n;
    cin>>n;
    while(n--){
        int ans=0;
        int x=3;
        while(x--){
            int a1,a2;
            cin>>a1>>a2;
            ans = max(ans,a1+a2);
        }
        cout<<ans<<endl;
    }
}