#include <bits/stdc++.h>
using namespace std;
const long long N = 8 * 1e5 + 100;
long long n, k, rev[N], len, Inv[N];
string s[N];
vector<long long> w[25];
inline void add(long long &a, long long b) {
  a = ((a + b >= 998244353) ? a + b - 998244353 : a + b);
}
inline void del(long long &a, long long b) {
  a = ((a - b < 0) ? a - b + 998244353 : a - b);
}
inline void mul(long long &a, long long b) { a = a * b % 998244353; }
inline long long m_pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) mul(ans, a);
    b >>= 1;
    mul(a, a);
  }
  return ans;
}
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
void prework() {
  long long d = 20;
  for (long long i = 1; i <= d; i++) {
    w[i].resize(1 << i);
    w[i][0] = 1;
    w[i][1] = m_pow(3, (998244353 - 1) >> i);
    for (long long j = 2; j < (1 << i); j++)
      w[i][j] = w[i][j - 1] * w[i][1] % 998244353;
  }
}
vector<long long> operator+(vector<long long> a, vector<long long> &b) {
  a.resize(max((long long)a.size(), (long long)b.size()));
  for (long long i = 0; i < (long long)b.size(); i++) add(a[i], b[i]);
  return a;
}
vector<long long> operator-(vector<long long> a, vector<long long> &b) {
  a.resize(max((long long)a.size(), (long long)b.size()));
  for (long long i = 0; i < (long long)b.size(); i++) del(a[i], b[i]);
  return a;
}
inline void integ(vector<long long> &y) {
  for (long long i = (long long)y.size() - 2; i >= 0; i--)
    y[i + 1] = y[i] * Inv[i + 1] % 998244353;
  y[0] = 0;
}
inline void der(vector<long long> &y) {
  for (long long i = 1; i < (long long)y.size(); i++)
    y[i - 1] = y[i] * i % 998244353;
  y[(long long)y.size() - 1] = 0;
}
inline void change(long long len) {
  for (long long i = 0; i < len; i++) {
    rev[i] = rev[i >> 1] >> 1;
    if (i & 1) rev[i] |= (len >> 1);
  }
}
inline void DFT(vector<long long> &y, long long len, long long v) {
  for (long long i = 0; i < len; i++)
    if (i < rev[i]) swap(y[i], y[rev[i]]);
  for (long long i = 1, d = 1; i < len; i <<= 1, d++) {
    for (long long j = 0; j < len; j += (i << 1)) {
      long long *W = &w[d][0], a, b;
      for (long long k = j; k < j + i; k++) {
        a = y[k], b = y[k + i] * (*W++) % 998244353;
        y[k] = y[k + i] = a;
        add(y[k], b);
        del(y[k + i], b);
      }
    }
  }
  if (v == -1) {
    reverse(y.begin() + 1, y.end());
    long long invlen = m_pow(len, 998244353 - 2);
    for (long long i = 0; i < len; i++) mul(y[i], invlen);
  }
}
vector<long long> operator*(vector<long long> a, vector<long long> b) {
  if (a.empty()) return b;
  if (b.empty()) return a;
  long long n = (long long)a.size(), m = (long long)b.size();
  len = 1;
  while (len < n + m) len <<= 1;
  change(len);
  a.resize(len);
  b.resize(len);
  DFT(a, len, 1);
  DFT(b, len, 1);
  for (long long i = 0; i < len; i++) mul(a[i], b[i]);
  DFT(a, len, -1);
  a.resize(n + m - 1);
  return a;
}
vector<long long> solve(long long l, long long r) {
  if (l == r) {
    vector<long long> ans;
    if (s[l] == "WW") ans.resize(3), ans[2] = 1;
    if (s[l] == "BB") ans.resize(1), ans[0] = 1;
    if (s[l] == "W?" || s[l] == "?W") ans.resize(3), ans[1] = 1, ans[2] = 1;
    if (s[l] == "B?" || s[l] == "?B") ans.resize(2), ans[0] = 1, ans[1] = 1;
    if (s[l] == "??") ans.resize(3), ans[0] = 1, ans[1] = 2, ans[2] = 1;
    if (s[l] == "WB" || s[l] == "BW") ans.resize(2), ans[1] = 1;
    return ans;
  }
  long long mid = (l + r) >> 1;
  return solve(l, mid) * solve(mid + 1, r);
}
signed main() {
  prework();
  n = read();
  for (long long i = 1; i <= n; i++) cin >> s[i];
  vector<long long> ans = solve(1, n);
  long long cnt = 0, all = 1;
  if ((long long)ans.size() >= n + 1) cnt = ans[n];
  for (long long i = 1; i <= n; i++) {
    if (s[i] == "WW" || s[i] == "BB") {
      all = 0;
      break;
    }
    if (s[i] == "??") mul(all, 2);
  }
  del(cnt, all);
  bool bl = 1;
  for (long long i = 1; i <= n; i++) bl &= (s[i][0] != 'W' && s[i][1] != 'B');
  if (bl) add(cnt, 1);
  bl = 1;
  for (long long i = 1; i <= n; i++) bl &= (s[i][0] != 'B' && s[i][1] != 'W');
  if (bl) add(cnt, 1);
  printf("%lld\n", cnt);
}
