#include <bits/stdc++.h>
using namespace std;
const int MAXD = 60 + 5;
const int MAXN = 2e3 * 60 + 5;
const int mod = 1e9 + 7;
inline long long pw(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
inline int get_lb(long long x) {
  int res = 0;
  while (x >> res) ++res;
  return res - 1;
}
int d;
long long a[MAXN];
int b[MAXN];
long long pt[MAXN];
int pcnt = 0, must[MAXN], dp[MAXN][5];
int f[MAXD];
inline int get(long long u) {
  int pos = lower_bound(pt + 1, pt + pcnt + 1, u) - pt;
  if (pos > pcnt || pt[pos] != u) return -1;
  return pos;
}
inline vector<int> get_dp(long long u) {
  int id = get(u);
  if (id != -1)
    return vector<int>(dp[id], dp[id] + 3);
  else
    return vector<int>(3, f[d - get_lb(u)]);
}
int main(void) {
  int n;
  scanf("%d%d", &d, &n);
  for (int i = 1; i <= n; ++i) {
    static char t[100];
    scanf("%lld%s", &a[i], t + 1);
    b[i] = t[1] == 'w' || t[1] == 'y' ? 1 : t[1] == 'g' || t[1] == 'b' ? 2 : 3;
  }
  f[1] = 1;
  for (int i = 2; i <= d; ++i) f[i] = 4ll * f[i - 1] * f[i - 1] % mod;
  pt[++pcnt] = 1;
  for (int i = 1; i <= n; ++i) {
    long long u = a[i];
    while (u) {
      pt[++pcnt] = u;
      u >>= 1;
    }
  }
  sort(pt + 1, pt + pcnt + 1);
  pcnt = unique(pt + 1, pt + pcnt + 1) - pt - 1;
  for (int i = 1; i <= n; ++i) must[get(a[i])] = b[i];
  for (int i = pcnt; i >= 1; --i) {
    if (pt[i] >= (1ll << (d - 1))) {
      if (!must[i])
        dp[i][0] = dp[i][1] = dp[i][2] = 1;
      else
        dp[i][must[i] - 1] = 1;
      continue;
    }
    long long u = pt[i];
    vector<int> ls = get_dp(u << 1);
    vector<int> rs = get_dp(u << 1 | 1);
    for (int x = 0; x < 3; ++x) {
      if (must[i] && x != must[i] - 1) continue;
      for (int y = 0; y < 3; ++y)
        if (y != x)
          for (int z = 0; z < 3; ++z)
            if (z != x) dp[i][x] = (dp[i][x] + (long long)ls[y] * rs[z]) % mod;
    }
  }
  int ans = 0;
  for (int i = 0; i < 3; ++i) ans = (ans + dp[1][i]) % mod;
  ans = ans * pw(2, (1ll << d) - 1 - n) % mod;
  printf("%d", ans);
  return 0;
}
