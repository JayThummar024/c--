
#include<bits/stdc++.h>
using namespace std;


void processArr(vector<int> arr){

    for( auto ele : arr ){
         if(ele%10==8 and ele%9==0){
        cout<<-7<<endl;
        }else if(ele%10==8){
            cout<<-3<<endl;
        }else if(ele%9==0){
            cout<<-6<<endl;
        }else{
            cout<<ele<<endl;
        }
    }   
}

int main(int argc, char const *argv[]){
    
    vector<int> arr;
    while(true){
        int num;
        cin>>num;
        if(num>0){
            arr.push_back(num);
        }else{
            break;
        }
    }
    processArr(arr);
    return 0;
}