#include <bits/stdc++.h>
using namespace std;
long long t, n, m, a[200005], cap = 1e18, dp[200005];
vector<pair<long long, long long> > b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    b.clear();
    for (int i = 1; i <= m; i++) {
      long long x, y;
      cin >> x >> y;
      b.push_back({x, y});
    }
    sort(a + 1, a + n + 1);
    a[n + 1] = cap;
    a[0] = -cap;
    sort(b.begin(), b.end());
    for (int i = 1; i <= m; i++) dp[i] = cap;
    for (int i = 1; i <= n; i++) {
      long long pos = upper_bound(b.begin(), b.end(),
                                  pair<long long, long long>{a[i] + 1, -1}) -
                      b.begin();
      long long jarak = 0, lanjut = dp[pos];
      for (int j = pos; j >= 1; j--) {
        if (b[j - 1].first < a[i - 1]) break;
        jarak = max(jarak, a[i] - b[j - 1].second);
        dp[pos] = min(dp[pos], dp[j - 1] + jarak);
        lanjut = min(lanjut, dp[j - 1] + 2 * jarak);
      }
      for (int j = pos + 1; j <= m; j++) {
        if (b[j - 1].first > a[i + 1]) break;
        long long jarak = b[j - 1].first - a[i];
        dp[j] = min(dp[j], lanjut + jarak);
      }
    }
    cout << dp[m] << '\n';
  }
}
