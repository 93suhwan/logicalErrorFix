#include <bits/stdc++.h>
using namespace std;
const int N = 400010;
const int mod = 1e9 + 7;
const int INF = INT32_MAX;
const double Pi = acos(-1.0);
int t;
int n, m;
int a[N], b[N];
long long c[N], seg[N][5];
long long minn, pre, k, ans, sum;
int dir[][2] = {{0, 0},  {0, 1},   {-1, 0}, {0, -1}, {1, 0},
                {-1, 1}, {-1, -1}, {1, -1}, {1, 1}};
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
inline int gcd(int x, int y) {
  if (!x) return y;
  return gcd(y % x, x);
}
inline int power(int x, int k, int p) {
  int res = 1;
  for (; k; k >>= 1, x = (long long)x * x % p)
    if (k & 1) res = (long long)res * x % p;
  return res;
}
void pushup(long long p) {
  seg[p][0] = seg[p << 1][0] + seg[p << 1 | 1][0];
  seg[p][1] = min(seg[p << 1][1], seg[p << 1][0] + seg[p << 1 | 1][1]);
  seg[p][2] = max(seg[p << 1][2], seg[p << 1][0] + seg[p << 1 | 1][2]);
  seg[p][3] = max(seg[p << 1 | 1][3], seg[p << 1][3] + seg[p << 1 | 1][0]);
  seg[p][4] = max(seg[p][4], seg[p << 1][4]);
  seg[p][4] = max(seg[p][4], seg[p << 1 | 1][4]);
  seg[p][4] = max(seg[p][4], seg[p][2]);
  seg[p][4] = max(seg[p][4], seg[p][3]);
}
void build(long long p, long long l, long long r) {
  if (l == r) {
    seg[p][0] = seg[p][1] = seg[p][2] = seg[p][3] = seg[p][4] = c[l];
    return;
  }
  long long mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void query(long long p, long long l, long long r, long long ql, long long qr) {
  if (ql <= l && r <= qr) {
    sum += seg[p][0];
    minn = min(minn, seg[p][1] + pre);
    pre += seg[p][0];
    ans = max(ans, seg[p][4]);
    ans = max(ans, k + seg[p][2]);
    k = max(k + seg[p][0], seg[p][3]);
    return;
  }
  long long mid = (l + r) >> 1;
  if (ql <= mid) query(p << 1, l, mid, ql, qr);
  if (mid + 1 <= qr) query(p << 1 | 1, mid + 1, r, ql, qr);
}
void solve() {
  n = read();
  m = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 1; i <= n; ++i) b[i] = read();
  for (int i = 1; i <= n; ++i) c[i] = b[i] - a[i];
  build(1, 1, n);
  while (m--) {
    int l = read(), r = read();
    minn = LONG_LONG_MAX, pre = 0, k = 0, ans = 0, sum = 0;
    query(1, 1, n, l, r);
    if (minn >= 0 && sum == 0)
      printf("%lld\n", ans);
    else
      puts("-1");
  }
  return;
}
int main() {
  solve();
  return 0;
}
