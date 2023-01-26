#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 500;
struct node {
  int tot;
  int cnt[5];
} a[maxn];
int n;
void solve() {
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    a[i].tot = str.size();
    for (int j = 0; j < 5; j++) a[i].cnt[j] = 0;
    for (char it : str) {
      a[i].cnt[it - 'a']++;
    }
  }
  for (int m = 0; m < 5; m++) {
    int ans = 0, ths = 0, othr = 0;
    sort(a + 1, a + n + 1, [&](node& x, node& y) {
      return 2 * x.cnt[m] - x.tot > 2 * y.cnt[m] - y.tot;
    });
    auto check = [&]() { return ths > othr; };
    ths = a[1].cnt[m];
    othr = a[1].tot - ths;
    if (!check()) continue;
    ans = 1;
    for (int i = 2; i <= n; i++) {
      ths += a[i].cnt[m];
      othr += a[i].tot - a[i].cnt[m];
      if (!check()) break;
      ans++;
    }
    res = max(res, ans);
  }
  cout << res << '\n';
}
signed main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
