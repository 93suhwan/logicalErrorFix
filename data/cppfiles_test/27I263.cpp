#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
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
#ifndef ONLINEJUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
//debug template ends

//#define int long long

#define nl "\n"
#define sep " "
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define FOR(i,begin,end) for(auto i=(begin)-((begin)>(end));i!=(end)-((begin)>(end));i+=1-2*((begin)>(end)))
#define scan(arr,n) FOR(scan_idx,0,n)cin>>arr[scan_idx];
#define inp(v,n) int n;cin>>n;vi v(n);scan(v,n)
#define inpl(v,n) ll n;cin>>n;vl v(n);scan(v,n)
#define setbits(x) __builtin_popcountll(x)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define present(ab,cd) ((ab).find((cd)) != (ab).end())
#define acc accumulate



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

//remove debug statements
//#define debug if(false)debug
//check tips if stuck

//press ctrl + shift + b before submitting, compile with all the flags

void testcase(){
    ll n,m,k;cin>>n>>m>>k;k--;
    if(m < n-1){
        NO();
    }
    if(m> n*(n-1)/2){
        NO();
    }
    if(m == n*(n-1)/2){
        if(k <= 1){
            NO();
        }
        YES();
    }
    if(k > 2){
        YES();
    }
    NO();
}

int32_t main() {
    //comment it while solving interactive 
    fastio();

    cout<<fixed<<setprecision(10);

    int t=1;
    cin>>t;
    while(t--){
        testcase();
    } 
}
/*
    Coded by : Dip Turkar
    
    {TIPS WHILE STARTING}
    --figure out logic first, then start writing pls!!!!!!!
    --check for long long overflows
    --using a set? check for PBDS!!!
    --modulo of negative numbers is not a%b, it is a%b + abs(b)!!!!!!!
    --lower_bound and set.lower_bound are different, use it wisely
    --string .append() or += is O1, but s = s + s is On, use wisely
    --check if you have to input t or not
*/