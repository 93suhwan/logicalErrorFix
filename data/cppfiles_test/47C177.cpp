#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int bit[(int)5e5 + 100];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    vector<int> a, b;
    int mx = 0;
    for (int i = 1, x; i <= n; ++i) {
      cin >> x, mx = max(mx, abs(x));
      if (x > 0) a.emplace_back(x);
      if (x < 0) b.emplace_back(-x);
    }
    sort((a).begin(), (a).end());
    sort((b).begin(), (b).end());
    long long ans = 0;
    for (int i = (int)a.size() - 1; i >= 0; i -= k) ans += a[i] << 1;
    for (int i = (int)b.size() - 1; i >= 0; i -= k) ans += b[i] << 1;
    cout << ans - mx << "\n";
  }
  return 0;
}
