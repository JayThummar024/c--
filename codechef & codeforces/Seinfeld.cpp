#include<bits/stdc++.h>
using namespace std;
#define ll                       long long int
#define ld                       long double
#define mod                      1000000007
#define inf                      1e18
#define pb                       push_back
#define vi                       vector<ll>
#define vs                       vector<string>
#define pii                      pair<ll,ll>
#define ump                      unordered_map
#define mp                       make_pair
#define pq_max                   priority_queue<ll>
#define pq_min                   priority_queue<ll,vi,greater<ll> >
#define all(n)                   n.begin(),n.end()
#define ff                       first
#define ss                       second
#define mid(l,r)                 (l+(r-l)/2)
#define bitc(n)                  __builtin_popcount(n)
#define SET(a)                   memset( a, -1, sizeof a )
#define CLR(a)                   memset( a,  0, sizeof a )
#define Pi                       3.141592653589793
#define loop(i,a,b)              for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)           for(int i=(a);i>=(b);i--)
#define _fast                    ios_base::sync_with_stdio(0);  cin.tie(0);
#define iter(container,it)       for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define log(args...)             {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);
// #istream_iterator<string> _it(_ss); err(_it, args); 
#define logarr(arr,a,b)          for(int z=(a);z<=(b);z++)<<endl<<cout<<(arr[z])<<cout<<endl;
template <typename T> T          gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T          lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
// cout << *it << ' = ' << a << endl;
err(++it, args...);
}
void solve() {
/*code*/
    
}
int main(int argc, char const *argv[]){
    _fast


    string str;
    int count = 0;
    
    while (true){
        cin>>str;
        if(str[0] == '-') break;
        stack<char> st;
        ll closing = 0;
        ll ans = 0;
        for(int i = 0;i<str.size();i++){
            if(str[i]=='{') st.push('{');
            else{
                if(not st.empty()){
                    st.pop();
                }else{
                    closing++;
                }
            }
        }
        if(st.size() > 0){
            if(st.size()%2 != 0){
                closing--;
                ans+=2;
            }else{
                ans += st.size()/2;
            };
        }
        if (closing > 0){
            ans += closing/2;
        }
        cout<<++count<<". "<<ans<<endl;
    }
    return 0;
}