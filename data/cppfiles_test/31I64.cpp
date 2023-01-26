// Author: Pawan Raj
// Problem: D. Vupsen, Pupsen and 0
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/D

/* clang-format off */
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define int long long
#define F(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end()
#define show(A) for (auto i: A) cout << -i << " "; cout << '\n';
#define show_(A, n) F(i, n) { show(A[i]) }
/* clang-format on */

using namespace std;
using ld = long double;
using vi = vector<int>;
using mi = map<int, int>;
using pi = pair<int, int>;

const int N = 300005;
const int MOD = 1e9 + 7;
const int inf = 1e18 + 1;
/***************************code begins here*****************************/

void solve() {
    int n, ans = 0;
    cin >> n;
    vi a(n);
    F(i, n) cin >> a[i];

    reverse(all(a));
    show(a);
    // cout << ans << '\n';
}

main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}