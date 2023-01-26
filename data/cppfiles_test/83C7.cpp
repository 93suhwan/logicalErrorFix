#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const int MOD = 1000000007;
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
int main() {
  ll n;
  scanf("%lld", &n);
  const int mod = 998244353;
  int blockCnt = 0;
  array<vector<int>, 7> vals;
  array<Mint, 7> sumVals{};
  function<void(ll, int)> precalc = [&](ll x, int d) {
    int v = (blockCnt - x + mod) % mod;
    vals[d].push_back(v);
    ++blockCnt;
    if (d == 6) return;
    for (int i = 0; i <= 9; ++i) {
      precalc(x * 10 + i, d + 1);
    }
  };
  precalc(0, 0);
  for (int i = 0; i <= 6; ++i) {
    sort(vals[i].begin(), vals[i].end());
    sumVals[i] = accumulate(vals[i].begin(), vals[i].end(), Mint(0));
  }
  Mint ans = 0;
  ll cnt = 0;
  function<void(ll)> go = [&](ll pref) {
    if (pref * 1000000 + 999999 <= n && pref * 10000000 > n) {
      int p10 = 1;
      for (int d = 0; d <= 6; ++d) {
        int add = ((cnt - pref * p10) % mod + mod) % mod;
        ans += sumVals[d];
        if (add > 0) {
          ans += Mint(add) * vals[d].size();
          int pos = lower_bound(vals[d].begin(), vals[d].end(), mod - add) -
                    vals[d].begin();
          ans -= Mint(vals[d].size() - pos) * mod;
        }
        p10 *= 10;
      }
      cnt += blockCnt;
      return;
    }
    ans += ((cnt - pref) % mod + mod) % mod;
    ++cnt;
    for (int d = pref ? 0 : 1; d <= 9; ++d) {
      if (pref * 10 + d <= n) go(pref * 10 + d);
    }
  };
  go(0);
  42;
  printf("%d\n", ans.val);
}
