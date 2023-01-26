#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e2 + 7;
int mod = 1, n, m, all;
struct modint {
  int v;
  inline void norm() {
    while (v < 0) v += mod;
    while (v >= mod) v -= mod;
  }
  modint(int _v = 0) {
    v = _v;
    norm();
  }
  modint operator+(const modint& oth) const {
    modint ret = *this;
    ret.v += oth.v;
    ret.norm();
    return ret;
  }
  modint operator*(const modint& oth) const {
    modint ret = *this;
    ret.v = 1ll * ret.v * oth.v % mod;
    return ret;
  }
};
modint C[maxn][maxn];
modint f[maxn][maxn][maxn];
bool vis[maxn][maxn][maxn];
modint dp(int siz, int need, int dis) {
  if (siz + 1 < need * 2 || siz < need) return 0;
  if (dis > m && need > 0) {
    return 0;
  }
  if (dis == m && need > 1) return 0;
  if (siz == 0) return need == 0;
  if (vis[siz][need][dis]) return f[siz][need][dis];
  vis[siz][need][dis] = 1;
  modint& w = f[siz][need][dis];
  int tmp = need;
  if (dis == m) --tmp;
  for (int a = 0; a <= siz - 1; ++a) {
    for (int b = 0; b <= tmp; ++b) {
      w = (w + C[siz - 1][a] * dp(a, b, dis + 1) *
                   dp(siz - 1 - a, tmp - b, dis + 1));
    }
  }
  return w;
}
int main() {
  scanf("%d %d %d %d", &n, &m, &all, &mod);
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }
  printf("%d\n", dp(n, all, 1).v);
  return 0;
}
