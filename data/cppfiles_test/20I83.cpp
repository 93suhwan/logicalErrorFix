#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
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

const int N = 400 + 5;
const int K = 26;
const int KS = 1e8 + 5;
const int P = 31;
const int INF = 1e18;
const double d_INF = 2000000000.0;
const double EPS = 1e-20;
const int MOD = 998244353;
const int LOG = 29;
const double PI = 3.14159265359;

char a[N][N];
int mas[N][N];
int pref[N][N];

int get(int i, int j, int i1, int j1) {
    return pref[i1][j1] - pref[i1][j - 1] - pref[i - 1][j1] + pref[i - 1][j - 1];
}

int check(int i, int j, int i1, int j1) {
    int cur = 0;
    cur += get(i + 1, j + 1, i1 - 1, j1 - 1);
    cur += i1 - i - 1 - get(i + 1, j, i1 - 1, j);
    cur += i1 - i - 1 - get(i + 1, j1, i1 - 1, j1);
    cur += j1 - j - 1 - get(i, j + 1, i, j1 - 1);
    cur += j1 - j - 1 - get(i1, j + 1, i1, j1 - 1);
    return cur;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= m; j ++) {
            mas[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (a[i][j] == '1');
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            for (int j1 = j - 1; j1 >= 1; j1 --) {
                if (j - j1 + 1 < 4 || i < 5) continue;
                if (check(mas[j][j1], j1, i, j) > check(i - 4, j1, i, j)) {
                    mas[j][j1] = i - 4;
                }
                ans = min(ans, check(mas[j][j1], j1, i, j));
            }
        }
    }
    cout << ans;
}

main () {
    int test = 1;
    booost;
    cin >> test;
    while (test --) {
        solve();
    }
}
