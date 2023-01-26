#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template <int MOD>
struct Modular {
  int val;
  Modular() : val(0){};
  Modular(int _val) : val(_val % MOD){};
  void norm() {
    val %= MOD;
    if (val < 0) val += MOD;
  }
  Modular& operator+=(const Modular& other) {
    val += other.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }
  Modular operator+(const Modular& other) const {
    auto tmp(*this);
    tmp += other;
    return tmp;
  }
  Modular& operator-=(const Modular& other) {
    val -= other.val;
    if (val < 0) val += MOD;
    return *this;
  }
  Modular operator-(const Modular& other) const {
    auto tmp(*this);
    tmp -= other;
    return tmp;
  }
  Modular& operator*=(const Modular& other) {
    val = (val * 1LL * other.val) % MOD;
    return *this;
  }
  Modular operator*(const Modular& other) const {
    auto tmp(*this);
    tmp *= other;
    return tmp;
  }
  Modular bin_pow(int n) const {
    Modular res(1);
    Modular a = *this;
    for (; n; n >>= 1, a *= a)
      if (n & 1) res *= a;
    return res;
  }
  Modular inv() const { return this->bin_pow(MOD - 2); }
  Modular& operator/=(const Modular& other) { return *this *= other.inv(); }
  Modular operator/(const Modular& other) const { return *this * other.inv(); }
};
template <int MOD>
std::ostream& operator<<(std::ostream& out, const Modular<MOD>& x) {
  out << x.val;
  return out;
}
const int MOD = (int)1e9 + 7;
using Mint = Modular<MOD>;
int bit(int mask, int k) { return (mask >> k) & 1; }
const int N = 14;
int a[N];
Mint p[N][1 << N];
Mint scc[1 << N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto getp = [&](int i, int j) { return Mint(a[i]) / Mint(a[i] + a[j]); };
  auto getpp = [&](int mask1, int mask2) {
    Mint res(1);
    for (int i = 0; i < n; ++i) {
      if (bit(mask1, i)) {
        res *= p[i][mask2];
      }
    }
    return res;
  };
  for (int i = 0; i < n; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (bit(mask, i)) continue;
      p[i][mask] = Mint(1);
      for (int j = 0; j < n; ++j) {
        if (bit(mask, j)) {
          p[i][mask] *= getp(i, j);
        }
      }
    }
  }
  Mint ans(0);
  for (int mask = 0; mask < (1 << n); ++mask) {
    scc[mask] = Mint(1);
    if (__builtin_popcount(mask) > 1) {
      for (int smask = (mask - 1) & mask; smask; smask = (smask - 1) & mask) {
        scc[mask] -= scc[smask] * getpp(smask, mask ^ smask);
      }
    }
    ans += Mint(__builtin_popcount(mask)) * scc[mask] *
           getpp(mask, mask ^ ((1 << n) - 1));
  }
  cout << ans << '\n';
}
