// #include<bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <utility>
#include <climits>
#include <map>
#include <queue>
#include<chrono>
#include <bitset>
#include <cstring>
#include <assert.h>
#include <numeric>
#include <stack>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

typedef long double ldb;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

#define pb push_back
#define ff first
#define ss second
#define sz(a) ((long long)(a).size())
#define modd1 1000000007ll
#define modd2 998244353ll
#define nline "\n"
#define all(x) x.begin() , x.end()
#define google cout << "Case #" << test_num << ": "

#ifndef ONLINE_JUDGE
#define dbg(a) cerr << #a << "::- \n"; _print(a); cerr << endl;
#else
#define dbg(a) // No more TLEs
#endif

void _print(ll t){cerr<<t;}
void _print(int t){cerr<<t;}
void _print(string t){cerr<<t;}
void _print(char t){cerr<<t;}
void _print(ldb t){cerr<<t;}
void _print(double t){cerr<<t;}
// void _print(ull t){cerr<<t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p){cerr<< "{";_print(p.ff);cerr<<",";_print(p.ss);cerr<<"}";}
template <class T> void _print(vector <T> v){cerr<<"[";for(T i: v){_print(i);cerr<<" ";}cerr << "]" << endl;}
template <class T> void _print(set <T> v){cerr<<"[";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(unordered_multiset <T> v){cerr<<"[";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T> void _print(multiset <T> v){cerr<<"[";for(T i: v){_print(i);cerr<<" ";}cerr << "]";}
//void _print(ordered_set &v){cerr<<"[ ";for(int i: v){_print(i);cerr<<" ";}cerr << "]";}
template <class T, class V> void _print(map <T, V> v){cerr<<"[";for(auto i: v){_print(i);cerr<<" ";}cerr << "]";}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

/*----------------------------- # --- MATH ALGORITHMS --- # -----------------------------*/

template <class T> T gcd(T a , T b){ while(a != 0){T temp = a; a = b % a; b = temp;}return b;}
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
template <class T> T expo(T base , T exp , T mod){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinvfermat(T a , T mod){return expo<T>(a , mod - 2 , mod);} // fermat little theorem - ((1 / a) % m = (a ^ (m − 2))%m)
template <class T> T mod_add(T a, T b, T m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
template <class T> T mod_mul(T a, T b, T m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
template <class T> T mod_sub(T a, T b, T m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
template <class T> T mod_div(T a, T b, T m) {a = a % m; b = b % m; return (mod_mul(a, expo(b, m - 2, m), m) + m) % m;}  //only for prime m
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
vector<ll> AllDivisors(int n){ vector<ll> v; for (int i = 1; i <= sqrt(n); i++) { if (n % i == 0) {if (n / i == i){v.push_back(i);}else {v.push_back(i);v.push_back(n / i);}}}dbg(v);return v;}
const ll infl = 1e18 + 5; const int inf = 1e9 + 5;
ll expo_mod(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo_mod(a, b - 2,b);}

/*----------------------------- # --- MAIN CODE --- # -----------------------------*/

void runn(int test_num) {

    dbg(test_num);
    ll n;
    cin >> n;

    if(n % 2 == 0){
        cout << n / 2 << " " << (n / 2) - 1 << " " << 1 << nline;
    }
    else{
        ll num = (n - 1) / 2;
        cout << num - 2 << " " << num + 2 << " " << 1 << nline;
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    auto start = high_resolution_clock::now();
    cout<<fixed<<setprecision(12);

    int t;
//    t = 1;
    cin >> t;

    for(int i = 1 ; i <= t ; i++){
        runn(i);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

#ifndef ONLINE_JUDGE
    cerr << "Time: " << duration.count() << endl;
#endif
    return 0;
}