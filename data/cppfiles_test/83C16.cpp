#include <bits/stdc++.h>
using namespace std;
const long long p = 998244353;
const long long mod = 1e9 + 7;
long long read() {
  long long s = 0;
  char c = getchar(), lc = '+';
  while (c < '0' || '9' < c) lc = c, c = getchar();
  while ('0' <= c && c <= '9') s = s * 10 + c - '0', c = getchar();
  return lc == '-' ? -s : s;
}
void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x < 10)
    putchar(x + '0');
  else
    write(x / 10), putchar(x % 10 + '0');
}
void print(long long x, char c = '\n') {
  write(x);
  putchar(c);
}
long long pw[8], sum[7], cnt = 0, ans = 0, n;
vector<long long> v[7];
void dfs0(long long deep, long long val) {
  v[deep].push_back((cnt++ - val + p) % p);
  if (deep < 6)
    for (long long i = 0; i <= 9; i++) dfs0(deep + 1, val * 10 + i);
}
void dfs1(long long deep, long long val) {
  static long long idx = 0;
  if (val > n) return;
  if (val * pw[6] > n / 10 && (val + 1) * pw[6] - 1 <= n) {
    for (long long i = 0; i <= 6; i++) {
      long long now = (idx - val % p * pw[i] % p + p) % p, siz = v[i].size();
      long long tot =
          v[i].end() - lower_bound(v[i].begin(), v[i].end(), p - now);
      ans = (ans + sum[i] + now * siz - p * tot) % mod;
    }
    idx += cnt;
    return;
  }
  ans = (ans + (idx++ - val % p + p) % p) % mod;
  for (long long i = !deep; i <= 9; i++) dfs1(deep + 1, val * 10 + i);
}
void Multi_test_no_horses() {
  n = read();
  dfs0(0, 0);
  for (long long i = pw[0] = 1; i <= 7; i++) pw[i] = pw[i - 1] * 10;
  for (long long i = 0; i <= 6; i++) {
    sort(v[i].begin(), v[i].end());
    for (long long j : v[i]) sum[i] += j;
  }
  dfs1(0, 0);
  print(ans);
}
signed main(signed Hello, char *CodeForces[]) {
  (void)Hello, (void)CodeForces;
  long long T = 1;
  while (T--) Multi_test_no_horses();
  return 0;
}
