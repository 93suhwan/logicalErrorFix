#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int SS = 1 << 18;
int t[N], dp[N];
pair<int, int> sorted[N];
pair<int, int> p[N];
int n;
int seg[N];
void cl(int ind) {
  if (ind < 0) return;
  for (ind += SS; ind > 0; ind >>= 1) seg[ind] = 0;
}
void add(int x, int ind) {
  if (ind < 0) return;
  for (ind += SS; ind > 0; ind >>= 1) seg[ind] = max(seg[ind], x);
}
int Query(int a, int b) {
  int res = 0;
  a += SS - 1, b += SS + 1;
  while ((a >> 1) != (b >> 1)) {
    if (!(a & 1)) res = max(res, seg[a + 1]);
    if (b & 1) res = max(res, seg[b - 1]);
    a >>= 1, b >>= 1;
  }
  return res;
}
int Bs(int x, int p, int k) {
  int sr;
  int res = 0;
  while (p <= k) {
    sr = p + (k - p) / 2;
    if (sorted[sr].first < x)
      res = sr, p = sr + 1;
    else
      k = sr - 1;
  }
  return res;
}
void divide(int a, int b) {
  if (b - a + 1 == 1) {
    if (t[a] <= n) dp[a] = max(dp[a], 1);
    return;
  }
  int n2 = (a + b) / 2;
  divide(a, n2);
  sort(sorted + a, sorted + n2 + 1);
  for (int i = n2 + 1; i <= b; i++) p[i] = {Bs(t[i], a, n2), i};
  sort(p + n2 + 1, p + b + 1);
  int w = 1;
  for (int i = n2 + 1; i <= b; i++) {
    if (p[i].first == 0) continue;
    while (w <= p[i].first) {
      add(dp[sorted[w].second], sorted[w].second - sorted[w].first);
      w++;
    }
    dp[p[i].second] =
        max(dp[p[i].second], Query(0, p[i].second - t[p[i].second]) + 1);
  }
  for (int i = a; i <= n2; i++) {
    cl(sorted[i].second - sorted[i].first);
    sorted[i] = {t[i], i};
  }
  divide(n2 + 1, b);
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) sorted[i] = {t[i], i};
  divide(1, n);
  int res = 0;
  for (int i = 1; i <= n; i++) res = max(res, dp[i]);
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
}
