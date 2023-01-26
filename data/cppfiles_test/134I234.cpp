#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for (int i = (a - 1); i >= (b); i--)
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define sz(a) (int)a.size()
#define reset(a) memset(a,0,sizeof(a));
#define int long long
#define ll long long
#define ld long double
template<typename T>
using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<int, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
typedef vector<int> vi;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
// ll mod = 1000000007;
//ll mod=67280421310721;
ll mod=998244353;
ll INF=1e18;
const ld eps=1e-9;

// DEBUGGING TEMPLATE
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifndef ONLINE_JUDGE
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int powmod(int a, int b)
{
    ll res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

const int MAXN = 200005;

void solve()
{  
    int n;
    cin >> n;

    vector<int> a(n);
    FOR(i, 0, n) cin >> a[i];

    int p = a[0], q = a[1];
    FOR(i, 0, n){
        if(i&1) q = gcd(q, a[i]);
        else p = gcd(p, a[i]);
    }
    if(p == q){
        cout << 0 << '\n';
    }
    else{
        if(p > q){
            for(int i = 1; i < n; i += 2){
                if(a[i] % p) continue;
                cout << 0 << '\n';
                return;
            }
            cout << p << '\n';
        }
        else{
            for(int i = 0; i < n; i += 2){
                if(a[i] % q) continue;
                cout << 0 << '\n';
                return;
            }
            cout << q << '\n';
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;

    cin>>t;
    while (t--)
    {
        solve();
    }
    // debug() << "TIME: " << clock() << endl;
    return 0;
}
