#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4,popcnt,fma")
#pragma GCC optimize("unroll-loops")

typedef long long int ll;
typedef long double ld;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define endl '\n'
#define pb push_back
#define conts continue
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(), a.rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define ff first
#define ss second
#define ceil2(x,y) (x+y-1) / y
#define sz(a) a.size()
#define setbits(x) __builtin_popcountll(x)
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x <<" = "; print(x); cout << endl;
#else
#define debug(x)
#endif

#define rep(i,n) for(ll i = 0; i < n; ++i)
#define rep1(i,n) for(ll i = 1; i <= n; ++i)

bool iseven(ll n) {if ((n & 1) == 0) return true; return false;}

void print(ll t) {cout << t;}
void print(int t) {cout << t;}
void print(string t) {cout << t;}
void print(char t) {cout << t;}
void print(double t) {cout << t;}
void print(ld t) {cout << t;}

template <class T, class V> void print(pair <T, V> p);
template <class T> void print(vector <T> v);
template <class T> void print(set <T> v);
template <class T, class V> void print(map <T, V> v);
template <class T> void print(multiset <T> v);
template <class T, class V> void print(pair <T, V> p) {cout << "{"; print(p.ff); cout << ","; print(p.ss); cout << "}";}
template <class T> void print(vector <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]";}
template <class T> void print(set <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]";}
template <class T> void print(multiset <T> v) {cout << "[ "; for (T i : v) {print(i); cout << " ";} cout << "]";}
template <class T, class V> void print(map <T, V> v) {cout << "[ "; for (auto i : v) {print(i); cout << " ";} cout << "]";}

void usaco(string filename){
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

const ll MOD = 1e9+7;
const ll maxn = 1e5 + 5;
const ll inf = 1e18;

void solve()
{
    // https://youtu.be/0wtOyCcdUWo?t=2232
    int t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> a(n);
        rep(i,n) cin >> a[i];

        ll ans = inf;

        // not optimal to take > 2 1s
        // [1,1] = 1,2
        // [1,2] = 1,2,3

        // not optimal to take > 3 2s
        // [2,2,2] = 2,4,6
        // [1,2,3] = 1,2,3,4,5,6
        
        rep(mxones, 2){
            rep(mxtwos, 3){
                ll mxthrees = 0;

                rep(i,n){
                    ll mn = inf;
                    rep(ones, mxones+1){
                        rep(twos, mxtwos+1){
                            ll tosub = (ones * 1) + (twos * 2);
                            ll temp = a[i] - tosub;
                            if(temp % 3 != 0) conts;
                            mn = min(mn, temp / 3);
                        }
                    }

                    mxthrees = max(mxthrees, mn);
                }

                ll sum = mxones + mxtwos + mxthrees;
                ans = min(ans, sum);
            }
        }

        cout << ans << endl;
    }
}

int main()
{
    fastio;
    solve();
    return 0;
}