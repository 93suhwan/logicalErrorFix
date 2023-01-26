#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define pb push_back

using namespace std;
typedef long long ll;

void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

int a[1000010];
int c[1000010];

bitset <8192> dp[5010];

bitset <8192> b;

vector <int> v;

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        c[i] = 1 << (32 - __builtin_clz(a[i]));
        mx = max(mx, a[i]);
    }
    for (int i = 0; i <= mx; ++i)
        dp[i][0] = 1;
    int f;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0)
            continue;
        b = ~dp[a[i]];
        f = b._Find_next(0);
        while (f < c[i]) {
            if ((f ^ a[i]) > f && b[f ^ a[i]]) {
                b[f ^ a[i]] = 0;
                f = b._Find_next(f);
                continue;
            }
            if (!b[f ^ a[i]]) {
                for (int j = i; j <= mx; ++j)
                    dp[j][f] = 1;
            }
            f = b._Find_next(f);
        }
    }
    for (int i = 0; i < (1 << (32 - __builtin_clz(mx))); ++i) {
        if (dp[mx][i])
            v.pb(i);
    }
    cout << sz(v) << '\n';
    for (auto i : v)
        cout << i << " ";
}
