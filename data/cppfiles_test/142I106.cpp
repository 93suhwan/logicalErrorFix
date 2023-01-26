#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}
int n, m;
int p[N], mx[N], id[N];
bool st[N];
int f(int x, int y) { return x * m + y; }
signed main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n), scanf("%d", &m);
    for (int i = 0; i <= n; i++) mx[i] = st[i] = 0;
    for (int i = 0; i < n * m; i++) scanf("%d", &p[i]);
    bool ok = 0;
    int ans = -1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++)
        if (p[f(j, i)] > mx[i]) mx[i] = p[f(j, i)], id[i] = j;
      if (st[id[i]]) ok = 1;
      st[id[i]] = 1;
      if (ans == -1) ans = mx[i];
      ans = min(ans, mx[i]);
    }
    if (ok)
      cout << ans << '\n';
    else {
      int ans = -1;
      for (int i = 0; i < m; i++) {
        int tp = -1;
        for (int j = 0; j < m; j++) {
          if (j == i) continue;
          if (tp == -1) tp = p[f(id[j], i)];
          tp = max(tp, p[f(id[j], i)]);
        }
        for (int j = 0; j < m; j++) {
          if (j == i) continue;
          tp = min(tp, mx[j]);
        }
        if (ans == -1) ans = tp;
        ans = max(ans, tp);
      }
      for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
          int tp = -1;
          for (int k = 0; k < n; k++) tp = max(tp, min(p[f(k, i)], p[f(k, j)]));
          for (int k = 0; k < m; k++) {
            if (k == i || k == j) continue;
            tp = min(tp, mx[k]);
          }
          ans = max(ans, tp);
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
