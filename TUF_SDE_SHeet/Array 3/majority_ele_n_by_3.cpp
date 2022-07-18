
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

int main(){
    _fast
    
    vi nums{3,1,2,3,1,1,4,3,3,2,3,1,2,1};
    int sz=nums.size();

    int n1,n2,c1=0,c2=0;

    for(int i=0;i<sz;i++){
        if (n1 == nums[i]){
            c1 += 1;
        }else if (n2 == nums[i]){
            c2 += 1;
        }else if (c1 == 0){
            n1=nums[i];
            c1 += 1;
        }else if (c2 == 0){
            n2=nums[i];
            c2 += 1;
        }else{
            c1--;
            c2--;
        }
    }

    int count1=0, count2=0;
    vector<int> ans;

    for(int i=0;i<sz;i++){
        if(nums[i]==n1){
            count1 += 1;
        }else if(nums[i]==n2){
            count2 += 1;
        }
    }

    cout<<n1<<" "<<n2<<endl;

    if (count1 > sz / 3)
        ans.push_back(n1);
    if (count2 > sz / 3)
        ans.push_back(n2);

    logarr(ans,0,ans.size());

    return 0;
}