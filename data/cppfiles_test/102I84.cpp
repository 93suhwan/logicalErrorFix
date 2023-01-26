// Chrollo_Lucifer (nlather)
// Nishant Raj Lather

/* ------------------------------ TEMPLATE BEGIN ------------------------------ */

// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

/* ----------------- ORDERED SET (POLICY BASED DS) ----------------- */
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T>
// using ordered_set = tree
//     <T, null_type, less<T>, rb_tree_tag,
//     tree_order_statistics_node_update>;

/* -------------- BETTER RANDOM (RAND() IS DANGEROUS) -------------- */
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(x, y) uniform_int_distribution<ll>(x, y)(rng)

/* ----------------- CUSTOM HASH FUNCTION FOR UMAP ----------------- */
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://left_endhift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

/* ----------------------- DEBUGGING UTILITY ----------------------- */
#define cerr cout
void _print() {cerr << "]\n";}
template <typename T, typename... V> void _print(T t, V... v) {
    cerr << t; if(sizeof...(v)) cerr << ", "; _print(v...);
}
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)

#define boost ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define rep(i, x, n) for (ll i = (ll)(x); i < (ll)(n); i++)
#define rrep(i, x, n) for (ll i = (ll)(x); i >= (ll)(n); i--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define minSelf(a, b) a = min(a, b)
#define maxSelf(a, b) a = max(a, b)
#define mem(arr, x) memset(arr, x, sizeof(arr))
using ll = int64_t;
using ld = long double;
template <typename T, typename V>
using P = pair<T, V>;
template <typename T>
using V = vector<T>;
constexpr ll MOD = 998244353;
constexpr ll INF = 0x3f3f3f3f; // ~1e9 (1061109567)
constexpr ld EPS = 1e-9;
#define endl '\n' // REMOVE FOR INTERACTIVE TASKS
constexpr ll MAX = 3e5+5;

/* ------------------------------- TEMPLATE END ------------------------------- */

ll power(ll a, ll b) {
    ll res = 1;
    while(b > 0) {
        if(b&1) (res *= a) %= MOD;
        (a *= a) %= MOD, b >>= 1;
    }
    return res;
}

void solve() {
    ll k, A, h;
    cin >> k >> A >> h;
    map<ll, ll> has, has2;
    auto go = [&] (ll mask, ll mask2) {
        debug(mask, mask2);
        ll pos[1<<k-1], pos2[1<<k-1], rank[1<<k];
        rep(i, 0, 1<<k-1) pos[i] = i;
        rep(match, 0, 1<<k-1) {
            ll loser = pos[(match<<1|(mask>>match&1)^1)&((1<<k-1)-1)];
            pos[match] = pos[(match<<1|mask>>match&1)&((1<<k-1)-1)];
            if(match < (1<<k-1)-1) rank[loser] = 1<<__lg((1<<k-1)-match-1)+1|1;
            debug(loser, rank[loser]);
        }
        rep(i, 0, 1<<k-1) pos2[i] = i+(1<<k-1);
        rep(match, 0, 1<<k-1) {
            ll loser = pos2[(match<<1|(mask2>>match&1)^1)&((1<<k-1)-1)];
            pos2[match] = pos2[(match<<1|mask2>>match&1)&((1<<k-1)-1)];
            if(match < (1<<k-1)-1) rank[loser] = 1<<__lg((1<<k-1)-match-1)+1|1;
            debug(loser, rank[loser]);
        }
        if(mask>>((1<<k-1)-1)&1) {
            rank[pos2[(1<<k-1)-2]] = 1;
            rank[pos[(1<<k-1)-2]] = 2;
        } else {
            rank[pos[(1<<k-1)-2]] = 1;
            rank[pos2[(1<<k-1)-2]] = 2;
        }
        rep(i, 0, 1<<k) cout << rank[i] << ' ';
        cout << endl;
    };
    rep(mask, 0, 1<<(1<<k-1)) {
        ll pos[1<<k-1], pos2[1<<k-1], val = 0, val2 = 0;
        rep(i, 0, 1<<k-1) pos[i] = i, pos2[i] = i+(1<<k-1);
        rep(match, 0, 1<<k-1) {
            ll result = mask>>match&1;
            ll loser = pos[(match<<1|result^1)&((1<<k-1)-1)] + 1;
            ll loser2 = pos2[(match<<1|result^1)&((1<<k-1)-1)] + 1;
            pos[match] = pos[(match<<1|result)&((1<<k-1)-1)];
            pos2[match] = pos2[(match<<1|result)&((1<<k-1)-1)];
            ll rank = 1<<__lg((1<<k-1)-match-1)+1|1;
            if(match < (1<<k-1)-1) {
                val += (loser * power(A, rank)) % MOD;
                val %= MOD;
                val2 += (loser2 * power(A, rank)) % MOD;
                val2 %= MOD;
            }
        }
        if(mask>>((1<<k-1)-1)&1) {
            val += ((pos[(1<<k-1)-2]+1) * power(A, 2)) % MOD;
            val %= MOD;
            val2 += ((pos2[(1<<k-1)-2]+1) * power(A, 1)) % MOD;
            val2 %= MOD;
        } else {
            val += ((pos[(1<<k-1)-2]+1) * power(A, 1)) % MOD;
            val %= MOD;
            val2 += ((pos2[(1<<k-1)-2]+1) * power(A, 2)) % MOD;
            val2 %= MOD;
        }

        has[val] = mask;
        has2[val2] = mask;
        if(has2.count((h-val+MOD)%MOD)) {
            ll mask2 = has2[(h-val+MOD)%MOD];
            if((mask>>((1<<k-1)-1)&1) == (mask2>>((1<<k-1)-1)&1)) {
                return go(mask, mask2);
            }
        } else if(has.count((h-val2+MOD)%MOD)) {
            ll mask2 = has[(h-val2+MOD)%MOD];
            if((mask>>((1<<k-1)-1)&1) == (mask2>>((1<<k-1)-1)&1)) {
                return go(mask2, mask);
            }
        }
    }
    cout << "-1\n";
}

int main() {
    boost
    ll t = 1;
    // cin >> t;
    rep(i, 1, t+1) solve();
}
