#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
const long long inf = 1LL << 60;
long long a[N], f[N], g[N];
pair<long long, long long> b[N], q[N];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i].first >> b[i].second;
  sort(a + 1, a + 1 + n);
  sort(b + 1, b + 1 + m);
  a[++n] = inf;
  for (int i = 1, j = 1; i <= n; ++i) {
    int s = 0;
    while (j <= m && b[j].first <= a[i]) {
      if (b[j].second < a[i]) q[++s] = b[j];
      ++j;
    }
    q[++s].first = a[i - 1];
    sort(q + 1, q + 1 + s);
    f[i] = g[i] = inf;
    long long mn = a[i];
    for (int k = s; k >= 1; --k) {
      long long u = q[k].first - a[i - 1], v = a[i] - mn;
      long long t = min(f[i - 1] + u * 2, g[i - 1] + u);
      f[i] = min(f[i], t + v);
      g[i] = min(g[i], t + v * 2);
      mn = min(mn, q[k].second);
    }
  }
  cout << f[n] << endl;
}
int main() {
  a[0] = -inf;
  int t;
  cin >> t;
  while (t--) solve();
}
