#include<bits/stdc++.h>
#include <unordered_map>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// Ordered Set Tree
typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
using namespace std;
#define _USE_MATH_DEFINES
# define M_PI           3.14159265358979323846  /* pi */
#define ll long long
#define ull unsigned long long
#define ld long double
#define vbe(v) ((v).begin()), ((v).end())
#define sz(v)     ((int)((v).size()))
#define prec(x)    << fixed<< setprecision(x)
#define clr(v, d)   memset(v, d, sizeof(v))
#define rep(i, v)   for(int i=0;i<sz(v);++i)
#define lp(i, n)    for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)  for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)  for(int i=(j);i>=(int)(n);--i)
#define MIN(x, y) (((x) < (y)) ? (x) : (y))
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cin.tie(0);
#define INFLL 1e18
#define INF 1e9
#define MOD 1000000007
#define MOD1 998244353
#define MAXN 200005

ll GCD(ll a, ll b) { return (a) ? GCD(b % a, a) : b; }

ll LCM(ll a, ll b) { return a * b / GCD(a, b); }

ll fastpow(ll b, ll p) {
    if (!p) return 1;
    ll ret = fastpow(b, p >> 1);
    ret *= ret;
    if (p & 1) ret *= b;
    return ret;
}

void solve(int tst) {
    int n;
    cin >> n;
    vector<ll> vec(n);
    lp(i, n)cin >> vec[i];
    ll g1 = 0;
    ll g2 = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) {
            g1 = GCD(g1, vec[i]);
        } else g2 = GCD(g2, vec[i]);
    }
    if(g1>=g2) {
        lp(i, n) {
            if (!(i & 1)) {
                if (vec[i] % g1 == 0) {
                    cout << 0;
                    return;
                }
            }
        }
    }
    if(g2>g1) {
        lp(i, n) {
            if ((i & 1)) {
                if (vec[i] % g2 == 0) {
                    cout << 0;
                    return;
                }
            }
        }
    }
    cout<<max(g2,g1);

}

int main() {
    FASTIO;
    //freopen("gaser.in", "r", stdin);
    int t = 1;
    cin >> t;
    lp(i, t) {
        solve(i + 1);
        cout << "\n";
    }
}