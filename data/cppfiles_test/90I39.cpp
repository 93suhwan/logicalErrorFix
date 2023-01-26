#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m;
  vector<long long> canl, canr;
  vector<long long> a;
  vector<pair<long long, long long> > b;
  cin >> n >> m;
  a.resize(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  b.resize(m);
  for (long long i = 0; i < m; i++) {
    cin >> b[i].first >> b[i].second;
  }
  sort(b.begin(), b.end());
  vector<long long> mini(m + 1, 1000000000000000);
  for (long long i = m - 1; i >= 0; i--) {
    mini[i] = min(mini[i + 1], b[i].second);
  }
  vector<pair<long long, long long> > c;
  for (long long i = 0; i < m; i++) {
    if (mini[i + 1] <= b[i].second) continue;
    c.push_back(b[i]);
  }
  m = c.size();
  long long p = 0;
  sort(a.begin(), a.end());
  b.resize(0);
  for (long long i = 0; i < m; i++) {
    while (p < n && a[p] < c[i].first) p++;
    if (p < n && a[p] <= c[i].second) continue;
    b.push_back(c[i]);
  }
  m = b.size();
  if (m == 0) {
    cout << 0 << '\n';
    return;
  }
  canl.assign(n, m);
  canr.assign(n, -1);
  p = 0;
  for (long long i = 0; i < m; i++) {
    while (p + 1 < n && a[p + 1] < b[i].first) p++;
    canr[p] = i;
  }
  p = n - 1;
  for (long long i = m - 1; i >= 0; i--) {
    while (p - 1 >= 0 && a[p - 1] > b[i].second) p--;
    canl[p] = i;
  }
  vector<vector<long long> > dp(n, vector<long long>(2, 1000000000000000));
  dp[0][0] = max(0ll, a[0] - b[0].second);
  dp[0][1] = max(0ll, a[0] - b[0].second) * 2;
  p = 0;
  for (long long i = 0; i + 1 < n; i++) {
    while (p < m && b[p].first < a[i]) p++;
    if (p == m || b[p].first > a[i + 1]) {
      dp[i + 1] = dp[i];
      continue;
    }
    long long x = dp[i][0];
    long long y = dp[i][1];
    for (long long j = p; j < m; j++) {
      if (b[j].first > a[i + 1]) break;
      if (j == m - 1) {
        dp[i + 1][0] = min(dp[i + 1][0], x + 2 * (b[j].first - a[i]));
        dp[i + 1][1] = min(dp[i + 1][1], x + 2 * (b[j].first - a[i]));
        dp[i + 1][0] = min(dp[i + 1][0], y + (b[j].first - a[i]));
        dp[i + 1][1] = min(dp[i + 1][1], y + (b[j].first - a[i]));
        continue;
      }
      dp[i + 1][0] =
          min(dp[i + 1][0], x + 2 * (b[j].first - a[i]) +
                                max(0ll, a[i + 1] - b[j + 1].second));
      dp[i + 1][1] =
          min(dp[i + 1][1], x + 2 * (b[j].first - a[i]) +
                                2 * max(0ll, a[i + 1] - b[j + 1].second));
      dp[i + 1][0] =
          min(dp[i + 1][0],
              y + (b[j].first - a[i]) + max(0ll, a[i + 1] - b[j + 1].second));
      dp[i + 1][1] =
          min(dp[i + 1][1], y + (b[j].first - a[i]) +
                                2 * max(0ll, a[i + 1] - b[j + 1].second));
    }
    dp[i + 1][0] = min(dp[i + 1][0], x + max(0ll, a[i + 1] - b[p].second));
    dp[i + 1][1] = min(dp[i + 1][1], x + 2 * max(0ll, a[i + 1] - b[p].second));
    dp[i + 1][0] = min(dp[i + 1][0], y + max(0ll, a[i + 1] - b[p].second));
    dp[i + 1][1] = min(dp[i + 1][1], y + 2 * max(0ll, a[i + 1] - b[p].second));
  }
  dp[n - 1][0] += 2 * max(0ll, b[m - 1].first - a[n - 1]);
  dp[n - 1][1] += max(0ll, b[m - 1].first - a[n - 1]);
  if (min(dp[n - 1][0], dp[n - 1][1]) > 4000000000) assert(0);
  if (min(dp[n - 1][0], dp[n - 1][1]) < 0) assert(0);
  cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  while (n--) {
    solve();
  }
}
