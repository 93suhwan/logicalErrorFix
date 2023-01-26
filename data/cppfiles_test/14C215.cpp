#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 10;
const long long mod = 1e9 + 7;
long long n;
long long a[55], b[55];
struct du_lieu {
  long long l, r, d;
};
void solve() {
  cin >> n;
  vector<du_lieu> ans;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b + 1, b + 1 + n);
  for (long long i = 1; i <= n; i++) {
    if (a[i] == b[i]) continue;
    for (long long j = i + 1; j <= n; j++) {
      if (a[j] == b[i]) {
        ans.push_back({i, j, j - i});
        long long end = a[j], r = j;
        while (r > i) {
          a[r] = a[r - 1];
          r--;
        }
        a[i] = end;
      }
    }
  }
  cout << ans.size() << '\n';
  for (du_lieu i : ans) cout << i.l << ' ' << i.r << ' ' << i.d << '\n';
}
signed main() {
  if (ifstream(""
               ".inp")) {
    freopen(
        ""
        ".inp",
        "r", stdin);
    freopen(
        ""
        ".out",
        "w", stdout);
  }
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
