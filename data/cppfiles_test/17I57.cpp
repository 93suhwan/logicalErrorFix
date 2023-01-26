#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define pll pair<long long, long long>
#define vll vector<long long>
#define vvll vector<vector<long long>>
#define vpll vector<pair<long long, long long>>
#define vec vector
#define indexed_set                                          \
    tree<long long, null_type, less<long long>, rb_tree_tag, \
         tree_order_statistics_node_update>
#define indexed_map                                     \
    tree<pair<long long, long long>, null_type,         \
         less<pair<long long, long long>>, rb_tree_tag, \
         tree_order_statistics_node_update>
#define fast_map gp_hash_table

#define FOR(i, s, e) for (long long int i = s; i < e; i++)
#define CFOR(i, s, e) for (long long int i = s; i <= e; i++)
#define RFOR(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define TRAV(a, c) for (auto a : c)
#define ITER(it, cs, ce) for (auto it = cs; it != ce; it++)
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define dbg(x) cerr << "ln" << __LINE__ << ": " << #x << " = " << x << endl

template <class T>
string to_string(vector<T> &vec) {
    std::ostringstream vts;
    if (!vec.empty()) {
        std::copy(vec.begin(), vec.end() - 1,
                  std::ostream_iterator<T>(vts, ", "));
        vts << vec.back();
    }
    return "[" + vts.str() + "]";
}

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define FASTIO ;
#define PRECISION ;
//#define FILE ;

//#define SINGLE ;
#define MULTIPLE ;
//#define GOOGLE ;

void solve() {
    ll n;
    cin >> n;
    indexed_set dq;
    fast_map<ll, ll> fm;
    ll ans = 0;
    FOR(i, 0, n) {
        ll a;
        cin >> a;
        ll ord = dq.order_of_key(a);
        ans += min(ord, i - ord - fm[a]);
        dq.insert(a);
        fm[a]++;
    }
    cout << ans << "\n";
}

int main() {
#ifdef FASTIO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#endif
#ifdef PRECISION
    cout << fixed << setprecision(10);
#endif
#ifdef FILE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
#ifdef SINGLE
    solve();
#endif
#ifdef MULTIPLE
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
#endif
#ifdef GOOGLE
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
#endif
}
