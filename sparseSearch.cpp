
#include<bits/stdc++.h>
using namespace std;

int sparse_search(string a[] ,int n, string key){

    int start = 0;
    int end = n-1;

    while(start<=end){
        int mid = (start+end)/2;

        int mid_l = mid-1;
        int mid_r = mid+1;

        if(a[mid]==""){

            while(1){
                if(mid_l<start and mid_r>end){
                    return -1;
                }else if ( mid_l>=start and  a[mid_l]!=""){
                    mid = mid_l;
                    break;
                }else if( mid_r<=end and a[mid_r]!=""){
                    mid = mid_r;
                    break;
                }
                mid_l--;
                mid_r++;
            }
        }else if (a[mid]==key){
            return mid;
        }else if (a[mid]>key){
            end = mid-1;
        }else{
            start = mid+1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]){
    string a[] = {"ai","","","bat","","cat","dog","","","ele","","fan"};
    int n = 12;
    string f;
    cin>>f;
    cout<<sparse_search(a,n,f)<<endl;
    return 0;
}