#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N = 1e5 + 5;
#define div efeaargr
vi div[N], mul[N], pdiv[N];
bool isprime[N];
int a[N];
int occ[N];
ll f[N];
gp_hash_table<int, null_type> s;

int32_t main() {
    fastio;
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = 0;
    for(int i = 2; i < N; i++) {
        for(int j = i; j < N; j += i) {
            div[j].pb(i);
            if(isprime[i]) {
                isprime[j] = j == i;
                pdiv[j].pb(i);
            }
        }
    }
    int n; cin >> n;
    rep1(i, n) cin >> a[i];
    ll big = 0, small = 0;
    rep1(i, n) {
        for(int p: pdiv[i]) {
            for(int x = p; x <= n; x += p) s.insert(x);
        }
        for(int x: s) big += gcd(a[i], a[x]) * 1LL * (gcd(i, x) - 1);
        s.clear();
    }
    rep1(i, n) for(int x: div[a[i]]) occ[x]++;
    occ[1] = n;
    for(int i = N - 1; i > 0; i--) if(occ[i]) {
        f[i] = occ[i] * 1LL * occ[i];
        for(int j = i + i; j < N; j += i) f[i] -= f[j];
        small += i * 1LL * f[i];
    }
    ll t = 0; rep1(i, n) rep1(j, n) t += gcd(a[i], a[j]);
    cout << t << endl;
    cout << small << ' ' << big << ' ' << small + big << endl;
}
