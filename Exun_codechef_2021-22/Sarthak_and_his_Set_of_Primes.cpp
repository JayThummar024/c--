
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

vector<int> calc(vector<int> primeSet,int M){
    vector<int> valueSet= {1};
    for(int x : primeSet){
        for(int i=0;i< (int)valueSet.size();i++){
            if( x*valueSet[i] <= M ){
                valueSet.push_back(x*valueSet[i]);
            }
        }
    }
    return valueSet;
}


void solve(){

    int N,M;
    cin>>N>>M;
    vector<int> primes(N);
    for(int i=0;i<N;i++){
        cin>>primes[i];
    }

    sort(primes.begin(),primes.end());
    vector<int> primeSet1,primeSet2;
    for(int i=0;i<n;i++){
        if(i&1) primeSet1.push_back(primes[i]);
        else primeSet2.push_back(primes[i]);
    }

    vector<int> valueSet1 = calc(primeSet1,m);
    vector<int> valueSet2 = calc(primeSet2,m);

    sort(valueSet1.begin(),valueSet1.end());
    sort(valueSet2.begin(),valueSet2.end());

    int ans = 0, len1 = valueSet1.size() , len2 = valueSet2.size();
    int start = 0;
    int end = len2-1;

    while(start<len1 and end>=0){
        if(valueSet1[start]*valueSet2[end] <= m){
            ans += (end+1);
            start++;
        }
        else{
            end--;
        }
    }
    cout<< ans <<endl;
}


int main(){
    _fast
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}