#include <bits/stdc++.h>
using namespace std;
template <class T>
void rd(T &x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + ch - '0';
  x *= f;
}
template <class T>
void cmin(T &x, T y) {
  x = min(x, y);
}
template <class T>
void cmax(T &x, T y) {
  x = max(x, y);
}
const long long mod = 1e9 + 7;
template <class T>
T add(T x, T y) {
  return (x + y) % mod;
}
template <class T>
T sub(T x, T y) {
  return (x - y + mod) % mod;
}
template <class T>
T mul(T x, T y) {
  return 1ll * x * y % mod;
}
template <class T>
void Add(T &x, T y) {
  x = (x + y) % mod;
}
template <class T>
void Sub(T &x, T y) {
  x = (x - y + mod) % mod;
}
template <class T>
void Mul(T &x, T y) {
  x = 1ll * x * y % mod;
}
template <class T>
T qpow(T a, T b = mod - 2) {
  T ret = 1;
  for (; b; b >>= 1, Mul(a, a))
    if (b & 1) Mul(ret, a);
  return ret;
}
const long long N = 3e5 + 10;
long long n, Q, k, a[N], b[N], c[N], cnt, stk[N], top, dp[N], sq[N], ql = 1, qr;
pair<long long, long long> st[N][22];
long long ans[N];
vector<pair<long long, pair<long long, long long> > > q[N];
pair<long long, long long> getmin(long long l, long long r) {
  long long k = log2(r - l + 1);
  return min(st[l][k], st[r - (1 << k) + 1][k]);
}
signed main() {
  rd(n), rd(Q), rd(k);
  for (long long i = 1; i <= n; i++) rd(a[i]);
  for (long long i = 1; i <= n; i++) {
    while (ql <= qr && sq[ql] < i - k) ++ql;
    while (ql <= qr && a[sq[qr]] >= a[i]) --qr;
    sq[++qr] = i;
    b[i] = a[sq[ql]];
  }
  for (long long i = 1; i <= Q; i++) {
    long long l, r;
    rd(l), rd(r);
    ans[i] = a[l];
    r = l + (r - l) / k * k;
    l += k;
    if (l <= r) {
      q[l % k].push_back(make_pair(i, make_pair(l / k + 1, r / k + 1)));
    }
  }
  for (long long i = 0; i <= k - 1; i++) {
    cnt = 0;
    for (long long j = i; j <= n; j += k) c[++cnt] = b[j];
    for (long long j = 1; j <= cnt; j++) st[j][0] = make_pair(c[j], j);
    for (long long j = 1; j <= 20; j++)
      for (long long k = 1; k <= cnt - (1 << j) + 1; k++)
        st[k][j] = min(st[k][j - 1], st[k + (1 << (j - 1))][j - 1]);
    dp[cnt + 1] = 0;
    top = 0;
    for (long long j = cnt; j >= 1; j--) {
      while (top && c[stk[top]] >= c[j]) --top;
      long long p = cnt + 1;
      if (top) p = stk[top];
      dp[j] = dp[p] + 1ll * c[j] * (p - j);
      stk[++top] = j;
    }
    for (auto o : q[i]) {
      long long l = o.second.first, r = o.second.second;
      pair<long long, long long> tmp = getmin(l, r);
      long long p = tmp.second;
      ans[o.first] += dp[l] - dp[p] + 1ll * c[p] * (r - p + 1);
    }
  }
  for (long long i = 1; i <= Q; i++) printf("%lld\n", ans[i]);
  return 0;
}
