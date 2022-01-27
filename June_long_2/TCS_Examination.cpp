#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int s[3],d[3];
        for(int i=0;i<3;i++){
            cin>>d[i];
        }
        for(int i=0;i<3;i++){
            cin>>s[i];
        }
        int sm = 0 , dm =0;
        for(int i=0;i<3;i++){
            sm+=s[i];
            dm+=d[i];
        }
        if(sm>dm){
            cout<<"SLOTH"<<endl;
        }else if(sm<dm){
            cout<<"DRAGON"<<endl;
        }else{
            if(s[0]>d[0]) cout<<"SLOTH"<<endl;
            else if(s[0]<d[0]) cout<<"DRAGON"<<endl;
            else if(s[1]>d[1]) cout<<"SLOTH"<<endl;
            else if(s[1]<d[1]) cout<<"DRAGON"<<endl;
            else if(s[2]>d[2]) cout<<"SLOTH"<<endl;
            else if(s[2]<d[2]) cout<<"DRAGON"<<endl;
            else cout<<"TIE"<<endl;
        }
    }
    return 0;
}
