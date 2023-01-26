#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, f = 1;
  char _ch = getchar();
  while (!('0' <= _ch && _ch <= '9')) (_ch == '-') && (f = -1), _ch = getchar();
  while (('0' <= _ch && _ch <= '9')) s = s * 10 + _ch - 48, _ch = getchar();
  return s * f;
}
const long long N = 3e5 + 10, inf = 1e17;
long long n, q, k, a[N], b[N];
struct ST {
  long long len;
  vector<long long> a, f[20];
  void bld() {
    f[0].push_back(0);
    for (register long long i = 1; i <= len; i++) f[0].push_back(i);
    for (long long l = 1; (1 << l) <= len; l++) {
      f[l].push_back(0);
      for (long long i = 1; i + (1 << l) - 1 <= len; i++) {
        f[l].push_back(0);
        if (a[f[l - 1][i]] < a[f[l - 1][i + (1 << l - 1)]])
          f[l][i] = f[l - 1][i];
        else
          f[l][i] = f[l - 1][i + (1 << l - 1)];
      }
    }
  }
  inline long long qry(long long l, long long r) {
    long long t = log2(r - l + 1);
    return (a[f[t][l]] < a[f[t][r - (1 << t) + 1]]) ? f[t][l]
                                                    : f[t][r - (1 << t) + 1];
  }
} st[N], st1;
long long stk[N];
vector<long long> dp[N], nxt[N];
inline void ycl() {
  st1.len = n;
  st1.a.push_back(0);
  for (register long long i = 1; i <= n; i++) st1.a.push_back(a[i]);
  st1.bld();
  for (register long long i = k + 1; i <= n; i++) b[i] = a[st1.qry(i - k, i)];
  for (long long i = 1; i <= k; i++) {
    long long m = (n - i) / k;
    st[i].len = m;
    st[i].a.clear();
    st[i].a.push_back(0);
    for (long long j = 1; j <= m; j++) st[i].a.push_back(b[j * k + i]);
    st[i].bld();
    nxt[i].resize(m + 2);
    dp[i].resize(m + 2);
    long long tp = 0;
    for (long long j = m; j; j--) {
      while (tp && b[stk[tp] * k + i] > b[j * k + i]) tp--;
      nxt[i][j] = tp ? stk[tp] : m + 1;
      dp[i][j] = dp[i][nxt[i][j]] + (nxt[i][j] - j) * b[j * k + i];
      stk[++tp] = j;
    }
  }
}
inline long long Qry(long long x, long long l, long long r) {
  if (l > r) return 0;
  long long p = st[x].qry(l, r);
  return dp[x][l] - dp[x][p] + (r - p + 1) * st[x].a[p];
}
signed main() {
  n = read(), q = read(), k = read();
  for (register long long i = 1; i <= n; i++) a[i] = read();
  ycl();
  while (q--) {
    long long l = read(), r = read(), x = l % k == 0 ? k : l % k;
    cout << a[l] + Qry(x, (l - x) / k + 1, (r - x) / k) << '\n';
  }
  return 0;
}
