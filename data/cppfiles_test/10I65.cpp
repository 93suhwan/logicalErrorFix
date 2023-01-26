#include<bits/stdc++.h>
#define pi 3.141592653589793238
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define MOD 1000000007
#define INF 999999999999999999 
#define pb push_back
#define ff first
#define ss second
 
#define mt make_tuple
#define printclock cerr<<"Time : "<<1000*(long double)clock()/(long double)CLOCKS_PER_SEC<<"ms\n";
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll B) { return (unsigned ll)rng() % B;}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll power(ll x, ll y, ll p){
    ll res = 1;
    x = x % p;
    while (y > 0){
        if (y & 1)
            res = (res * x) % p;
 
 
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll f(ll x1, ll y1, ll x2, ll y2, ll r, ll c) {
    ll ans = 0;
    if (x1 > x2) swap(x1, x2), swap(y1, y2);
    ll nx1 = x1 + r, nx2 = x2 + r;
    ll ny1 = y1 + c, ny2 = y2 + c;
    ll X = min(nx2, nx1) - max(x1, x2);
    ll Y = min(ny2, ny1) - max(y1, y2) ;
    if (X > 0 && Y > 0) return X * Y;
    else return 0;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    fast;
    ll _T = 1;
    
    //cin >> _T;
    while (_T--) {
        ll n, m, k, r, c;
        cin >> n >> m >> k >> r >> c;
        ll ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        if(ax == bx && ay == by){
            cout << power(k, n * m, MOD) << "\n";
            return 0;
        }
        ll A = r * c;
        ll inter = f(ax, ay, bx, by, r, c);
        cout << inter << "##\n";
        ll left = n * m - 2 * A + inter;
        ll d = A - inter;
        ll ans;
        ans = power(k, d, MOD);
        ans *= power(k, left, MOD);
        ans %= MOD;
        cout << ans << "\n";
    }
    return 0;
}