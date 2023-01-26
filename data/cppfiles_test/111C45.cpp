#include <bits/stdc++.h>
class mint {
 public:
  unsigned int v;
  mint(unsigned int _v = 0) : v(_v) {}
  mint operator+(const mint &x) const {
    unsigned int r = v + x.v;
    if (r >= 998244353) r -= 998244353;
    return r;
  }
  mint &operator+=(const mint &x) {
    *this = *this + x;
    return *this;
  }
  mint operator*(const mint &x) const {
    unsigned int r = (unsigned long long int)v * x.v % 998244353;
    return r;
  }
  mint &operator*=(const mint &x) {
    *this = *this * x;
    return *this;
  }
  operator unsigned int() const { return v; }
};
mint comb[2048][2048];
mint dp[2048][128], td[128], tdi[128];
int a[2048];
int main() {
  for (int i = 0; i < 2048; ++i) {
    comb[i][0] = 1;
    for (int j = 1; j < i; ++j)
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  dp[0][0] = 1;
  int ba = 0;
  int rb = 1;
  for (int i = 0; i < n; ++i) {
    int nx = std::max(ba, std::max(0, a[i] - m));
    int de = nx - ba;
    int rn = std::max(0, a[i] + m + 1 - nx);
    int mn = std::min(std::max(0, rb - de), rn);
    memset(td, 0, sizeof(td));
    for (int j = i; j >= 0; --j) {
      mint ca = 0;
      memcpy(tdi, td, sizeof(tdi));
      memset(td, 0, sizeof(td));
      for (int k = 0; k < de; ++k) ca += dp[j][k];
      for (int k = 0; k < mn; ++k) {
        tdi[k] += ca;
        tdi[k] += dp[j][k + de] * (mint)(j - (nx + k) + 1);
        td[k] = dp[j][k + de] * (mint)j;
        ca += dp[j][k + de];
      }
      for (int k = mn; k < rn; ++k) tdi[k] += ca;
      memcpy(dp[j + 1], tdi, sizeof(dp[j + 1]));
    }
    memcpy(dp[0], td, sizeof(dp[0]));
    ba = nx;
    rb = rn;
    for (int j = 0; j <= n; ++j)
      for (int k = 0; k < rb; ++k)
        if (n + 1 - (ba + k) >= 0 && j - (ba + k) >= 0) 0;
  }
  mint ans;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j < rb; ++j)
      if (n + 1 - (ba + j) >= 0 && i - (ba + j) >= 0)
        ans += dp[i][j] * comb[n + 1 - (ba + j)][i - (ba + j)];
  printf("%d\n", (int)ans);
  return 0;
}
