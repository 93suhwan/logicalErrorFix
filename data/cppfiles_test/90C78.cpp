#include <bits/stdc++.h>
using namespace std;
const long long INF = 191981019260817;
long long n, m, T, a[200003];
pair<long long, long long> b[200003];
long long dp[2][200003];
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  for (int i = 0; i < m; i++) scanf("%lld%lld", &b[i].first, &b[i].second);
  a[0] = -INF;
  a[n + 1] = INF;
  n += 2;
  sort(a, a + n);
  sort(b, b + m);
  vector<pair<long long, long long> > v;
  long long l, r, x, y;
  for (int i = 1, j = 0; i < n; i++) {
    while (j < m && b[j].first <= a[i]) {
      if (b[j].second < a[i]) v.push_back(b[j]);
      ++j;
    }
    v.push_back(make_pair(a[i - 1], 0));
    sort(v.begin(), v.end());
    dp[0][i] = INF;
    dp[1][i] = INF;
    long long minn = a[i], qaq;
    while (v.size()) {
      l = v.back().first;
      r = v.back().second;
      v.pop_back();
      x = l - a[i - 1];
      y = a[i] - minn;
      qaq = min(dp[0][i - 1] + x * 2, dp[1][i - 1] + x);
      dp[0][i] = min(dp[0][i], qaq + y);
      dp[1][i] = min(dp[1][i], qaq + y * 2);
      minn = min(minn, r);
    }
  }
  cout << dp[0][n - 1] << endl;
}
int main() {
  cin >> T;
  while (T--) solve();
}
