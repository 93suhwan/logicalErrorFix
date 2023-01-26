#include <bits/stdc++.h>
using namespace std;
const int N = 210000;
const int M = 1100000;
const int mod = 998244353;
const int inf = (int)1e9;
const double eps = 1e-9;
const long long INF = 1e15;
int n, ans, cur;
long long a[N], b[N], g[M];
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
void ask(int k, int l, int r, long long q, int cnt, int op, int ll, int rr) {
  if (l == r) {
    if (q == -1) return;
    if (gcd(g[k], q) > 1) cnt++;
    ans = max(ans, cnt);
    cur = cnt;
    return;
  }
  int mid = (l + r) / 2;
  if (q == -1) {
    if (g[k << 1] == 1 && g[k << 1 | 1] == 1) {
      ask(k << 1, l, mid, q, cnt, op, l, r);
      ask(k << 1 | 1, mid + 1, r, q, cnt, op, l, r);
    } else {
      if (g[k << 1] > 1) {
        int len = mid - l + 1;
        if (k % 2 == 1 && k != 1) {
          cur = 0;
          ask(k - 1, ll, l - 1, g[k << 1], 0, 1, l, r);
          len += cur;
        }
        ask(k << 1 | 1, mid + 1, r, g[k << 1], len, 0, l, r);
      }
      if (g[k << 1 | 1] > 1) {
        int len = r - mid;
        if (k % 2 == 0) {
          cur = 0;
          ask(k + 1, r + 1, rr, g[k << 1 | 1], 0, 0, l, r);
          len += cur;
        }
        ask(k << 1, l, mid, g[k << 1 | 1], len, 1, l, r);
      }
    }
  } else {
    if (op == 1) {
      long long now = gcd(q, g[k << 1 | 1]);
      if (now > 1)
        ask(k << 1, l, mid, now, cnt + r - mid, op, l, r);
      else
        ask(k << 1 | 1, mid + 1, r, q, cnt, op, l, r);
    } else {
      long long now = gcd(q, g[k << 1]);
      if (now > 1)
        ask(k << 1 | 1, mid + 1, r, now, cnt + mid - l + 1, op, l, r);
      else
        ask(k << 1, l, mid, q, cnt, op, l, r);
    }
  }
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
  if (g[1] > 1)
    ans = n;
  else {
    ask(1, 1, n, -1, 0, -1, 1, n);
  }
  ans++;
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
