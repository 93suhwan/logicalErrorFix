#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 998244353;
struct Mint {
  int val;
  Mint() { val = 0; }
  Mint(ll x) {
    val = (-MOD <= x && x < MOD) ? x : x % MOD;
    if (val < 0) val += MOD;
  }
  template <typename U>
  explicit operator U() const {
    return (U)val;
  }
  friend bool operator==(const Mint& a, const Mint& b) {
    return a.val == b.val;
  }
  friend bool operator!=(const Mint& a, const Mint& b) { return !(a == b); }
  friend bool operator<(const Mint& a, const Mint& b) { return a.val < b.val; }
  Mint& operator+=(const Mint& m) {
    if ((val += m.val) >= MOD) val -= MOD;
    return *this;
  }
  Mint& operator-=(const Mint& m) {
    if ((val -= m.val) < 0) val += MOD;
    return *this;
  }
  Mint& operator*=(const Mint& m) {
    val = (ll)val * m.val % MOD;
    return *this;
  }
  friend Mint modex(Mint a, ll p) {
    assert(p >= 0);
    Mint ans = 1;
    for (; p; p >>= 1, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  Mint& operator/=(const Mint& m) { return *this *= modex(m, MOD - 2); }
  Mint& operator++() { return *this += 1; }
  Mint& operator--() { return *this -= 1; }
  Mint operator++(int) {
    Mint result(*this);
    *this += 1;
    return result;
  }
  Mint operator--(int) {
    Mint result(*this);
    *this -= 1;
    return result;
  }
  Mint operator-() const { return Mint(-val); }
  friend Mint operator+(Mint a, const Mint& b) { return a += b; }
  friend Mint operator-(Mint a, const Mint& b) { return a -= b; }
  friend Mint operator*(Mint a, const Mint& b) { return a *= b; }
  friend Mint operator/(Mint a, const Mint& b) { return a /= b; }
  friend ostream& operator<<(ostream& os, const Mint& x) { return os << x.val; }
  friend string to_string(const Mint& b) { return to_string(b.val); }
};
vector<Mint> fac(1, 1), invfac(1, 1);
Mint binom(int n, int k) {
  if (k < 0 || k > n) return 0;
  while (fac.size() <= n) {
    fac.push_back(fac.back() * fac.size());
    invfac.push_back(1 / fac.back());
  }
  return fac[n] * invfac[k] * invfac[n - k];
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  binom(n, 0);
  vector<int> B(n);
  for (int& b : B) scanf("%d", &b);
  vector<vector<Mint>> dp(1, vector<Mint>(2 * k + 1));
  dp[0][k] = 1;
  for (int i = 0; i < n; ++i) {
    vector<vector<Mint>> ndp(i + 2, vector<Mint>(2 * k + 1));
    vector<vector<Mint>> rdp(i + 2, vector<Mint>(2 * k + 1));
    for (int big = 0; big <= i; ++big) {
      for (int d = 0; d <= 2 * k; ++d) {
        if (dp[big][d] == 0) continue;
        int mex = (i == 0 ? 0 : B[i - 1]) + d - k;
        assert(mex >= 0);
        int nd = mex + k - B[i];
        if (nd >= 0 && nd <= 2 * k) {
          ndp[big][nd] += dp[big][d] * (big + mex);
          ndp[big + 1][nd] += dp[big][d];
        }
        nd = max(nd + 1, 0);
        if (nd > 2 * k) continue;
        int nmex = B[i] + nd - k;
        int lastNd = min(2 * k, big + 1 + mex + k - B[i]);
        if (nd > lastNd) continue;
        int lastNmex = B[i] + lastNd - k;
        rdp[big - (nmex - mex - 1)][nd] += dp[big][d] * fac[big];
        if (big - (lastNmex - mex - 1) - 1 >= 0 && lastNd + 1 <= 2 * k)
          rdp[big - (lastNmex - mex - 1) - 1][lastNd + 1] -=
              dp[big][d] * fac[big];
      }
    }
    for (int big = i; big >= 0; --big) {
      for (int d = 0; d <= 2 * k; ++d) {
        if (big < i && d > 0) rdp[big][d] += rdp[big + 1][d - 1];
        ndp[big][d] += rdp[big][d] * invfac[big];
      }
    }
    swap(dp, ndp);
  }
  Mint ans = 0;
  for (int big = 0; big <= n; ++big) {
    for (int d = 0; d <= 2 * k; ++d) {
      int mex = B[n - 1] + d - k;
      if (mex > n) continue;
      ans += dp[big][d] * binom(n - mex, big) * fac[big];
    }
  }
  printf("%d\n", ans.val);
}
