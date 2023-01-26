#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e3 + 2;
long long a[maxn][maxn], dp[maxn][maxn], ans[maxn][maxn], tot = 0, n, m;
map<long long, pair<long long, long long> > to;
long long max_st(long long x, long long y) {
  long long d1 = dp[x][y], d2 = dp[x][y + 1];
  d2 = min(d2, d1);
  d1 = min(d1, d2 + 1);
  return d1 + d2;
}
void calc_diag(long long d) {
  long long x = to[d].first, y = to[d].second;
  if (x > n || y > m || x < 1 || y < 1) {
    return;
  }
  while (x >= 1 && y >= 1) {
    if (a[x][y] == 1) {
      dp[x][y] = 0;
    } else {
      dp[x][y] = dp[x + 1][y + 1] + 1;
    }
    x--;
    y--;
  }
}
void calc_ans(long long d) {
  long long x = to[d].first, y = to[d].second;
  if (x > n || y > m || x < 1 || y < 1) {
    return;
  }
  while (x >= 1 && y >= 1) {
    tot -= ans[x][y];
    if (a[x][y]) {
      ans[x][y] = 0;
    } else
      ans[x][y] = max_st(x, y) + max_st(x + 1, y);
    tot += ans[x][y];
    x--;
    y--;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long q;
  cin >> n >> m >> q;
  for (long long i = 1; i <= n; i++) {
    to[i - m] = {i, m};
    calc_diag(i - m);
  }
  for (long long j = 1; j < m; j++) {
    to[n - j] = {n, j};
    calc_diag(n - j);
  }
  for (long long i = 1; i <= n; i++) {
    calc_ans(i - m);
  }
  for (long long j = 1; j < m; j++) {
    calc_ans(n - j);
  }
  while (q--) {
    long long x, y;
    cin >> x >> y;
    a[x][y] ^= 1;
    calc_diag(x - y);
    calc_diag(x - y - 1);
    calc_diag(x - y + 1);
    calc_ans(x - y);
    calc_ans(x - y - 1);
    calc_ans(x - y + 1);
    cout << tot << "\n";
  }
  return 0;
}
