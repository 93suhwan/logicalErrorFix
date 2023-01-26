#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <random>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// #define readInputFile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define pb push_back
#define eb emplace_back
#define mem(a, b) memset(a, (b), sizeof(a))
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define ff first
#define ss second
#define print2d(mat,n,m){for(int i=0;i<(int)(n);i++){for(int j=0;j<(m);j++){cout<<mat[i][j]<<' ';}cout<< endl;}}
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
typedef map<ll,ll> mll;
typedef set<ll> sll;
//debug template
void __print(int x) {cerr << x;} void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;} void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;} void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;} void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;} void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';} void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
//Print Template.
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second);
    cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""),
                __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
template <typename T>
void print(vector <T> v) { for (T i : v) cout << i << " "; cout << '\n'; }
template <typename T>
void print(vector <vector <T>>& v) { for (vector <T>& vv : v) { for (T& i : vv) cout << i << " "; cout << '\n'; } }
template <typename T>
void read(vector <T>& v) {for (T& i : v) cin >> i;}
template <typename T>
void read(T&& t) {cin >> t;}
template <typename T, typename... Args>
void read(T&& t, Args&&... args){ cin >> t; read(forward<Args>(args)...); }
template <typename T>
void print(T&& t) {cout << t << '\n';}
template <typename T, typename... Args>
void print(T&& t, Args&&... args){ cout << t << " "; print(forward<Args>(args)...); }
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}



void loop(){
    ll n;
    cin>>n;
    vll v(n);
    cin>>v;
    vector<array<ll,2>> good;
    for(ll i=0;i<n;i++){
        if(v[i]-1 <= i){
            ll offset = i - (v[i]-1);
            good.pb({v[i],offset});
        }
    }
    sort(all(good),[&](auto &l, auto &r){
        return l[1] < r[1];
    });
    vector<array<ll,2>> final;
    vll seen(2e5+10);
    for(ll i=0;i<good.size();i++){
        if(seen[good[i][0]] == 0){
            seen[good[i][0]] = 1;
            final.pb({good[i][0],good[i][1]});
        }
    }
    debug(final);
    sort(all(final),[&](auto &l , auto &r){
        if(l[1] == r[1]) return l[0] < r[0];
        return l[1] < r[1];
    });
    ll mx = 0;
    for(ll i=0;i<final.size();i++){
        ll j = i; ll cnt = 1; ll sum = final[j][1];
        while(j+1 < final.size() and final[j][0] < final[j+1][0] and sum <= final[j+1][1]){
            sum += final[j+1][1] - final[j][1];
            cnt += 1; j++;
        }
        mx = max(mx, cnt);
        i = j;
    }
    print(mx);
}



int32_t  main(){
    fast;
    ll t;
    // cin>>t;
    t = 1;
    // seive();
    while(t--){
      loop();
    }
}