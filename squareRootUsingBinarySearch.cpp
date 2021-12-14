#include<bits/stdc++.h>
using namespace std;

float square_root(int n , int p){
    int s = 0;
    int e = n;
    float ans = 0;

    while(s<=e){
        int mid = (s+e)/2;
        if(mid*mid == n){
            return mid;
        }else if(mid*mid < n){
            ans = mid;
            s = mid+1;
        }else{
            e = mid-1;
        }
    }


    float inc = 0.1;

    for(int i=1 ; i<=p ; i++){
        while(ans*ans<n){
            ans+=inc;
        }
        ans = ans-inc;
        inc = inc/10.0;
    }

    return ans;
}

int main(){
    int n,p;
    cin>>n>>p;

    cout<<square_root(n,p);
    return 0;
}