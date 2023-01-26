#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return f == -1 ? ~x + 1 : x;
}
long long n;
vector<long long> ve[11];
long long sum[11];
const long long N = 1e6, mod1 = 998244353, mod2 = 1e9 + 7;
long long cnt, tmp, ans;
long long m1(long long x) { return (x % mod1 + mod1) % mod1; }
void dfs1(long long x, long long v) {
  if (v > n) return;
  if (x > 6) return;
  ++cnt;
  ve[x].push_back(m1(cnt - v));
  sum[x] += m1(cnt - v);
  for (long long i = 0; i < 10; ++i) dfs1(x + 1, v * 10 + i);
}
void dfs2(long long x, long long v) {
  if (v > n) return;
  if (x >= 1) {
    if (v * N * 10 > n && v * N + N - 1 <= n) {
      for (long long i = 0, t = 1; i <= 6; ++i, t *= 10) {
        long long val = m1(cnt - v * t);
        long long pos =
            lower_bound(ve[i].begin(), ve[i].end(), mod1 - val) - ve[i].begin();
        (ans += val * ve[i].size() + sum[i] - mod1 * (ve[i].size() - pos)) %=
            mod2;
      }
      cnt += tmp;
      return;
    }
    ++cnt;
    (ans += m1(cnt - v)) %= mod2;
  }
  for (long long i = (x == 0 ? 1 : 0); i <= 9; ++i) dfs2(x + 1, v * 10 + i);
}
signed main() {
  n = read();
  dfs1(0, 0);
  tmp = cnt;
  cnt = 0;
  for (long long i = 0; i <= 6; ++i) sort(ve[i].begin(), ve[i].end());
  dfs2(0, 0);
  printf("%d\n", ans);
}
