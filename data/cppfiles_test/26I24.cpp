#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);


#define nl "\n"
#define sep " "
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define FOR(a, b, c) for(int(a) = (b); (a) < (c); ++(a))
#define scan(arr,n) FOR(scan_idx,0,n)cin>>arr[scan_idx];
#define inp(v,n) int n;cin>>n;vi v(n);scan(v,n)
#define inpl(v,n) ll n;cin>>n;vl v(n);scan(v,n)
#define setbits(x) __builtin_popcountll(x)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define present(ab,cd) ((ab).find((cd)) != (ab).end())
#define acc accumulate

//debug template starts
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//debug template ends


#define YES(); {cout<<"YES"<<nl;return;}
#define Yes(); {cout<<"Yes"<<nl;return;}
#define NO(); {cout<<"NO"<<nl;return;}
#define No(); {cout<<"No"<<nl;return;}

//using ulli = unsigned long long int;
using ll = long long;
using lld = long double;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef pair<string, string> pss;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> i_set;//indexed_set
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

lld pi = 3.1415926535897932;
ll MOD = (1000)*(1000)*(1000) + 7;
inline int mod(ll a){
    int b = a%MOD;
    if(b<0)b += MOD;
    return b;
}
int fun(string &s,int g,int A,int B){
    int left = 10 - g - 1;
    if(left%2){
        if(A > B + left/2 + 1 || B > A + left/2)return g + 1;
    }else{
        if(A > B + left/2  || B > A + left/2)return g + 1;
    }
    if(s[g] == '?'){
        if(g%2==0)return min(fun(s,g+1,A+1,B),fun(s,g+1,A,B));
        else return min(fun(s,g+1,A,B+1),fun(s,g+1,A,B));
    }else{
        if(g%2==0)return fun(s,g+1,A + s[g] - '0',B);
        else return fun(s,g+1,A,B+s[g] - '0');
    }
}

void testcase(){
    //remove debug statements
    string s;cin>>s;
    cout<<fun(s,0,0,0)<<nl;;
}

int32_t main() {
    fastio();
    int t=1;
    cin>>t;
    while(t--){
        testcase();
    } 
}