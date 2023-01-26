#include <bits/stdc++.h>
class mint {
 public:
  unsigned int v;
  mint(unsigned int _v = 0) : v(_v) {}
  mint operator+(const mint &x) const {
    unsigned int r = v + x.v;
    if (r >= ((int)1e9 + 7)) r -= ((int)1e9 + 7);
    return r;
  }
  mint &operator+=(const mint &x) {
    *this = *this + x;
    return *this;
  }
  mint operator*(const mint &x) const {
    unsigned int r = (unsigned long long int)v * x.v % ((int)1e9 + 7);
    return r;
  }
  mint &operator*=(const mint &x) {
    *this = *this * x;
    return *this;
  }
  operator unsigned int() const { return v; }
};
char s[2048], t[2048];
std::pair<mint, mint> _dp[2][2048 * 2], *dpa = _dp[0] + 2048,
                                        *dpb = _dp[1] + 2048;
int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; ++tc) {
    int n;
    scanf("%d%s%s", &n, s, t);
    assert((int)strlen(s) == n);
    assert((int)strlen(t) == n);
    std::fill(dpa - 2048, dpa + 2048, std::pair<mint, mint>(0, 0));
    dpa[0] = {1, 0};
    for (int i = 0; i < n; ++i) {
      std::fill(dpb - 2048, dpb + 2048, std::pair<mint, mint>(0, 0));
      if ((s[i] == '0' || s[i] == '?') && (t[i] == '0' || t[i] == '?')) {
        for (int j = -n; j <= n; ++j) {
          dpb[j].first += dpa[-j].first;
          dpb[j].second += (mint)std::abs(j) * dpa[-j].first + dpa[-j].second;
        }
      }
      if ((s[i] == '0' || s[i] == '?') && (t[i] == '1' || t[i] == '?')) {
        for (int j = -n; j <= n; ++j) {
          dpb[j].first += dpa[-(j - 1)].first;
          dpb[j].second +=
              (mint)std::abs(j) * dpa[-(j - 1)].first + dpa[-(j - 1)].second;
        }
      }
      if ((s[i] == '1' || s[i] == '?') && (t[i] == '0' || t[i] == '?')) {
        for (int j = -n; j <= n; ++j) {
          dpb[j].first += dpa[-(j + 1)].first;
          dpb[j].second +=
              (mint)std::abs(j) * dpa[-(j + 1)].first + dpa[-(j + 1)].second;
        }
      }
      if ((s[i] == '1' || s[i] == '?') && (t[i] == '1' || t[i] == '?')) {
        for (int j = -n; j <= n; ++j) {
          dpb[j].first += dpa[-j].first;
          dpb[j].second += (mint)std::abs(j) * dpa[-j].first + dpa[-j].second;
        }
      }
      std::swap(dpa, dpb);
      for (int j = -n; j < n; ++j)
        if (dpa[j].first) 0;
    }
    int ans = dpa[0].second;
    printf("%d\n", ans);
  }
  return 0;
}
