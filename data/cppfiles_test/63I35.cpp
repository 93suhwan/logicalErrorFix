#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//#define int long long
#define double long double
#define ft first
#define sc second
#define pb push_back
#define booost ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); cerr.tie(0);
#define all(x) (x).begin(),(x).end()
#define file(x) freopen(string(string((x)) + ".in").c_str(), "r", stdin); freopen(string(string((x)) + ".out").c_str(), "w", stdout);
#define GG cout << " OPA " << '\n';

using namespace std;
using namespace __gnu_pbds;
typedef pair <int, int> pi;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
random_device rd;
mt19937_64 gen(rd());
uniform_int_distribution <int> uid(0, 1000000000);
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int N = 21;
const int K = 4e5 + 5;
const int KS = 1e6 + 5;
const int P = 37;
const int INF = 1e9;
const double d_INF = 2000000000.0;
const double EPS = 1e-20;
const int MOD = 998244353;
const int LOG = 17;
const double PI = 3.14159265359;

int dp[(1 << N)][N][2];
int sum[(1 << N)];
int res[N];
int le[N][K];
int cnt[N][K];
string s[N];

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        cin >> s[i];
        for (int j = 0; j < K; j ++) {
            le[i][j] = -1;
        }
        int cur = 0;
        bool ok = true;
        int cr = 0;
        gp_hash_table <int, int> mp;
        for (int j = 0; j < s[i].size(); j ++) {
            if (s[i][j] == '(') cur ++;
            else cur --;
            if (cur < 0) ok = false;
            if (ok && cur == 0) cr ++;
            if (cur < 0 && le[i][-cur] == -1) {
                le[i][-cur] = mp[-cur - 1];
            }
            if (cur <= 0) {
                mp[-cur] ++;
                cnt[i][-cur] ++;
            }
        }
        res[i] = cur;
        dp[(1 << i)][i][(ok == true ? 0 : 1)] = cr;
        ans = max(ans, cr);
    }
    for (int mask = 1; mask < (1 << n); mask ++) {
        for (int j = 0; j < n; j ++) {
            if (((mask >> j) & 1) == 1) sum[mask] += res[j];
        }
    }
    for (int mask = 1; mask < (1 << n); mask ++) {
        for (int last = 0; last < n; last ++) {
            if (((mask >> last) & 1) == 0) continue;
            for (int nw = 0; nw < n; nw ++) {
                if (((mask >> nw) & 1) == 1) continue;
                int cur = sum[mask];
                int new_mask = (mask | (1 << nw));
                if (le[nw][cur + 1] != -1) {
                    dp[new_mask][nw][1] = max(dp[new_mask][nw][1], dp[mask][last][0] + le[nw][cur + 1]);
                    ans = max(ans, dp[new_mask][nw][1]);
                }
                else {
                    dp[new_mask][nw][0] = max(dp[new_mask][nw][0], dp[mask][last][0] + cnt[nw][cur]);
                    ans = max(ans, dp[new_mask][nw][0]);
                }
            }
        }
    }
    cout << ans;
}

main () {
    int test = 1;
    booost;
//    cin >> test;
    while (test --) {
        solve();
    }
}
