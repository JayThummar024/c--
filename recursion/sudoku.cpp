
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

bool isSafe(vector<vector<string>> mat,int i,int j,int no,int n){
    for(int k=0;k<9;k++){
        if(mat[i][k]==to_string(no) || mat[k][j]==to_string(no)){
            return false;
        }
    }
    int sx = (i/3)*3;
    int sy = (j/3)*3;
    for(int x=sx;x<(sx+3);x++){
        for(int y=sy;y<(sy+3);y++){
            if(mat[x][y]==to_string(no)){
                return false;
            }
        }
    }
    return true;
}



bool solveSudoku(vector<vector<string>> &mat,int i,int j,int n){
    if(i==n) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<mat[i][j]<<" - ";
            }
            cout<<"\n\n";
        }
        return true;
    };
    if(j==n){
       return solveSudoku(mat,i+1,0,n);
    }
    if(mat[i][j]!="."){
        return solveSudoku(mat,i,j+1,n);
    }
    for(int no=1;no<=n;no++){
        if(isSafe(mat,i,j,no,n)){
            mat[i][j]=to_string(no);
            bool solveSubProb = solveSudoku(mat,i,j+1,n);
            if(solveSubProb==true) return true;
        }
    }
    mat[i][j]=".";
    return false;
}


int main(){
    _fast
    int n=9;
    vector<vector<string>> mat=
    {
        {".",".",".",".","7",".","5","6","8"},
        {".","8","1",".",".",".",".",".","3"},
        {"7","2",".",".",".",".",".",".","."},
        {"1",".",".",".","4","6",".",".","."},
        {".","7","4","5",".","3","2","9","."},
        {".",".",".","2","9",".",".",".","4"},
        {".",".",".",".",".",".",".","7","5"},
        {"2",".",".",".",".",".","1","3","."},
        {"3","5","7",".","6",".",".",".","."}
    };
    solveSudoku(mat,0,0,n);
    return 0;
}