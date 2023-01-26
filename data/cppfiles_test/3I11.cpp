#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ff                  first
#define ss                  second
#define pb                  push_back
#define eb                  emplace_back
#define mp                  make_pair
#define lb                  lower_bound
#define ub                  upper_bound
#define setbits(x)          __builtin_popcountll(x)
#define zrobits(x)          __builtin_ctzll(x)
#define sz(v)               (int)v.size()
#define ps(y)               cout << fixed << setprecision(y)
#define ms(arr, v)          memset(arr, v, sizeof(arr))
#define all(v)              v.begin(), v.end()
#define rall(v)             v.rbegin(), v.rend()
#define trav(x, v)          for(auto &x: v)
#define w(t)                int t; cin >> t; while(t--)
#define rep(i, a, b)        for(int i = a; i <= b; i++)
#define rrep(i, a, b)       for(int i = a; i >= b; i--)
#define rep0(i, n)          rep(i, 0, n - 1)
#define rrep0(i, n)         rrep(i, n - 1, 0)
#define rep1(i, n)          rep(i, 1, n)
#define rrep1(i, n)         rrep(i, n, 1)
#define inp(arr, n)         rep0(i, n) cin >> arr[i];

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef map<ll, ll> mii;
typedef map<char, ll> mci;
typedef priority_queue<ll> pq_mx;
typedef priority_queue<ll, vi, greater<>> pq_mn;
typedef tree<ll, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> pbds;
/*
 * find_by_order(i) -> returns an iterator to the element at ith position (0 based)
 * order_of_key(i)  -> returns the position of element i (0 based)
 */

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const ll inf = 1e18;
const ld eps = 1e-10, pi = acos(-1.0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void fio() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

string s;

ll f(int i, ll sum, int x) {
    if (i == sz(s)) {
//        if (sum % 25 == 0) cout << sum << endl;
        return sum % 25 == 0;
    }
    ll ans = 0;
    if (s[i] == '_') {
        rep0(j, 10) {
            if (i == 0 and j == 0 and i < sz(s) - 1) continue;
            ans += f(i + 1, sum * 10ll + j, x);
        }
    } else if (s[i] == 'X') {
        if (x == -1) {
            rep0(j, 10) {
                if (i == 0 and j == 0 and i < sz(s) - 1) continue;
                ans += f(i + 1, sum * 10ll + j, j);
            }
        } else ans += f(i + 1, sum * 10ll + x, x);
    } else ans += f(i + 1, sum * 10ll + (s[i] - '0'), x);
    return ans;
}

int main() {
    fio();

    cin >> s;
    cout << f(0, 0, -1);

    return 0;
}