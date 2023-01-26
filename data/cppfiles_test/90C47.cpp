#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)2e5 + 5;
long long mem[MAXN][2];
long long dp[MAXN];
pair<int, int> seg[MAXN];
int X[MAXN];
int n, m;
void filter() {
  sort(seg + 1, seg + m + 1);
  vector<pair<int, int>> vec;
  for (int i = 1; i <= m; i++) {
    while (!vec.empty() && vec.back().second > seg[i].second) {
      vec.pop_back();
    }
    vec.push_back(seg[i]);
  }
  for (int i = 0; i < (int)(vec).size(); i++) {
    seg[i + 1] = vec[i];
  }
  m = (int)(vec).size();
}
int f(int l, int x, int r) {
  l = min(l, x);
  r = max(r, x);
  return r - l + min(x - l, r - x);
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> X[i];
  }
  sort(X + 1, X + n + 1);
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    int p = lower_bound(X + 1, X + n + 1, l) - X;
    if (p <= n && X[p] <= r) {
      --i;
      --m;
      continue;
    }
    seg[i] = {l, r};
  }
  filter();
  dp[0] = 0;
  fill(dp + 1, dp + m + 1, (long long)1e18);
  int p = 0, q = 0, t = 0;
  X[0] = (int)-2e9;
  X[n + 1] = (int)2e9;
  for (int i = 1; i <= n; i++) {
    while (t + 1 <= m && seg[t + 1].second < X[i - 1]) {
      ++t;
    }
    while (p + 1 <= m && seg[p + 1].second < X[i]) {
      p++;
    }
    while (q + 1 <= m && seg[q + 1].second < X[i + 1]) {
      q++;
    }
    long long mem0 = (long long)1e18, mem1 = (long long)1e18;
    for (int l = t + 1; l <= p; l++) {
      int A = X[i] - seg[l].second;
      mem0 = min(mem0, dp[l - 1] + A * 2);
      mem1 = min(mem1, dp[l - 1] + A);
    }
    for (int r = p + 1; r <= q; r++) {
      int B = seg[r].first - X[i];
      dp[r] = min(dp[r], mem0 + B);
      dp[r] = min(dp[r], mem1 + B * 2);
    }
    for (int r = p + 1; r <= q; r++) {
      dp[r] = min(dp[r], dp[p] + seg[r].first - X[i]);
    }
    for (int l = t + 1; l <= p; l++) {
      dp[p] = min(dp[p], dp[l - 1] + X[i] - seg[l].second);
    }
  }
  cout << dp[m] << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
