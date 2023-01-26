#include <bits/stdc++.h>
#include <bits/extc++.h>

#define sz(v) int (v.size())
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int MOD = 1000000009;
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());

double GetTime() { return clock() / (double) CLOCKS_PER_SEC; };
/// Actual code starts here
int n;
const int N = 100005;
int dp[N][3];
pair<int, int> pp[N][3];
bool used[N][3];
int mas[N];

int go(int p, int last) {
    if (p == n) return 0;
    if (used[p][last]) return dp[p][last];
    used[p][last] = true;
    int res = MOD;
    if (mas[p] == 2) {
        for (int i = 0; i < 2; i++) {
            int v = go(p + 1, i) + (last == i);
            if (v < res) {
                res = v;
                pp[p][last] = {p + 1, i};
            }
        }
    } else {
        res = go(p + 1, mas[p]) + (last == mas[p]);
        pp[p][last] = {p + 1, mas[p]};
    }
    dp[p][last] = res;
    return res;
}

string key = "BR";

void solve() {
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 2; j++) {
            used[i][j] = false;
            pp[i][j] = {-1, -1};
        }
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') mas[i] = 0;
        else if (s[i] == 'R') mas[i] = 1;
        else mas[i] = 2;
    }
    string res;
    int ans = go(0, 2);
    for (pair<int, int> i = {0, 2};; i = pp[i.ff][i.ss]) {
        if (i.ss != 2) res.pb(key[i.ss]);
        if (i.ff == -1) break;
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
}
