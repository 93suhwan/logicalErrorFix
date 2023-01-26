#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const long long INF = 1e15;
int n, ans, cur;
long long a[N], b[N], g[M], c[N][25];
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void update(int k) { g[k] = gcd(g[k << 1], g[k << 1 | 1]); }
void build(int k, int l, int r) {
  if (l == r) {
    g[k] = a[l];
    return;
  }
  int mid = (l + r) / 2;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  update(k);
}
long long ask(int k, int l, int r, int a, int b) {
  if (l == a && r == b) return g[k];
  int mid = (l + r) / 2;
  long long res;
  if (b <= mid)
    res = ask(k << 1, l, mid, a, b);
  else if (a > mid)
    res = ask(k << 1 | 1, mid + 1, r, a, b);
  else
    res = gcd(ask(k << 1, l, mid, a, mid),
              ask(k << 1 | 1, mid + 1, r, mid + 1, b));
  return res;
}
void solve() {
  scanf("%d", &n);
  ans = 0;
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]);
  if (n == 1) {
    printf("1\n");
    return;
  }
  for (int i = 1; i < n; i++) a[i] = abs(b[i + 1] - b[i]);
  n--;
  build(1, 1, n);
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= 20; j++) c[i][j] = 1;
  for (int i = 1; i <= n; i++) {
    for (int now = 0; now <= 20; now++) {
      if (i + (1 << now) > n) break;
      c[i][now] = ask(1, 1, n, i, i + (1 << now));
    }
  }
  ans = 0;
  for (int i = 1; i <= n; i++) {
    long long r = a[i];
    if (r == 1) continue;
    int pos = i;
    for (int now = 20; now >= 0; now--) {
      if (pos + (1 << now) > n) continue;
      long long nr = gcd(r, c[pos][now]);
      if (nr == 1) continue;
      r = nr;
      pos += (1 << now);
    }
    ans = max(ans, pos - i + 1);
  }
  printf("%d\n", ans + 1);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
