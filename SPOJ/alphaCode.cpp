//https://www.spoj.com/problems/ACODE/
#include<bits/stdc++.h>
using namespace std;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
//typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update> pbtrie;

#define ll                       long long int
#define ld                       long double
#define mod                      1000000007
#define inf                      1e18
#define endl                     "\n"
#define pb                       push_back
#define vi                       vector<ll>
#define vvi                      vector<vector<ll>>
#define vs                       vector<string>
#define pii                      pair<ll,ll>
#define ump                      unordered_map
#define us                       unordered_set
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
#define log(args...)             {string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)          for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
template <typename T> T          gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T          lcm(T a, T b){return (a*(b/gcd(a,b)));}
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
cout << *it << " = " << a << endl;
err(++it, args...);
}


// ll dp[100005];
// ll acodeTD(string &s ,int i){
//     if(i==1 or i==0) return 1;
//     if(dp[i] != -1) return dp[i];
//     ll ans = 0;
//     if( s[i-1]-'0' > 0 ){
//         ans += acodeTD(s,i-1);
//     }
//     if( i-2 >= 0 and (s[i-2]-'0') > 0 and (s[i-2]-'0')*10 + (s[i-1]-'0') <= 26 ) {
//         ans += acodeTD(s,i-2);
//     }
//     return dp[i] = ans;
// }

ll g(string &s){
    vi dp(s.size(),0);
    dp[0]= dp[1] = 1;
    if( (s[0]-'0')*10 + (s[1]-'0') <= 26 and (s[1]-'0') > 0 ) dp[1] += 1;

    for(int i =2 ; i < s.size() ; i++){
        if( ((s[i-1]-'0') > 0 )  and (s[i-1]-'0')*10 + (s[i]-'0') <= 26){
            dp[i] = dp[i-2];
        }
        dp[i] += dp[i-1];
    }
    return dp[s.size()-1];
}

int main(int argc, char const *argv[]){
    _fast
    string s;
    cin>>s;
    
    while(s[0]!='0'){
        // memset(dp,-1,sizeof dp);
        cout<<g(s)<<endl;
        cin>>s;
    }

    return 0;
}