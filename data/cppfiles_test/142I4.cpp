#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const long long INF = 1e18;
long long biex(long long a, long long b) {
  if (b == 0) return 1;
  long long ans = biex(a, b / 2);
  ans = ans * ans;
  if (b & 1)
    return ans * a;
  else
    return ans;
}
void solve() {
  int m, n;
  cin >> m >> n;
  int p[m + 1][n + 1];
  int lo = 1e9, hi = 1;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      cin >> p[i][j];
      hi = max(hi, p[i][j]);
      lo = min(lo, p[i][j]);
    }
  while (lo + 1 < hi) {
    int mid = (lo + hi) / 2;
    bool c1 = 1, c2 = 0;
    for (int j = 1; j <= n; j++) {
      bool f = 0;
      for (int i = 1; i <= m; i++) {
        if (p[i][j] >= mid) {
          f = 1;
          break;
        }
      }
      if (!f) {
        c1 = 0;
        break;
      }
    }
    for (int i = 1; i <= m; i++) {
      int cnt = 0;
      for (int j = 1; j <= n; j++) cnt += (p[i][j] >= mid);
      if (cnt > 1) {
        c2 = 1;
        break;
      }
    }
    if (c1 && c2)
      lo = mid;
    else
      hi = mid;
  }
  cout << lo << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) solve();
  return 0;
}
