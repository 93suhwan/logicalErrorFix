#include <bits/stdc++.h>
using namespace std;
const int MAXD = 60 + 5;
const int mod = 1e9 + 7;
inline void add_mod(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
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
int f[MAXD];
vector<long long> pt;
map<long long, int> must;
map<pair<long long, int>, int> dp;
int gao(long long u, int c) {
  if (dp.find({u, c}) != dp.end()) return dp[{u, c}];
  if (must.find(u) != must.end() && must[u] != c) return 0;
  if (u * 2 >= (1ll << d)) return 1;
  if (!binary_search(pt.begin(), pt.end(), u))
    return dp[{u, c}] = f[d - get_lb(u)];
  long long ls = u << 1, rs = u << 1 | 1;
  int suml = 0, sumr = 0;
  for (int i = 1; i <= 3; ++i)
    if (i != c) add_mod(suml, gao(ls, i)), add_mod(sumr, gao(rs, i));
  return dp[{u, c}] = (long long)suml * sumr % mod;
}
int main(void) {
  int n;
  scanf("%d%d", &d, &n);
  for (int i = 1; i <= n; ++i) {
    long long u;
    static char t[100];
    scanf("%lld%s", &u, t + 1);
    must[u] = t[1] == 'w' || t[1] == 'y'   ? 1
              : t[1] == 'g' || t[1] == 'b' ? 2
                                           : 3;
    while (u) pt.push_back(u), u >>= 1;
  }
  f[1] = 1;
  for (int i = 2; i <= d; ++i) f[i] = 4ll * f[i - 1] * f[i - 1] % mod;
  sort(pt.begin(), pt.end());
  pt.erase(unique(pt.begin(), pt.end()), pt.end());
  int ans = 0;
  for (int i = 1; i <= 3; ++i) add_mod(ans, gao(1, i));
  ans = ans * pw(2, (1ll << d) - 1 - n) % mod;
  printf("%d", ans);
  return 0;
}
