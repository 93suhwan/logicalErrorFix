#include <bits/stdc++.h>
using namespace std;
template <int MOD>
struct ModInt {
  long long v;
  ModInt(long long _v = 0) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  ModInt &operator+=(const ModInt &other) {
    v += other.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &other) {
    v -= other.v;
    if (v < 0) v += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &other) {
    v = v * other.v % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &other) { return *this *= inverse(other); }
  bool operator==(const ModInt &other) const { return v == other.v; }
  bool operator!=(const ModInt &other) const { return v != other.v; }
  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }
  friend ModInt operator-(const ModInt &a) { return 0 - a; }
  friend ModInt power(ModInt a, long long b) {
    ModInt ret(1);
    while (b > 0) {
      if (b & 1) ret *= a;
      a *= a;
      b >>= 1;
    }
    return ret;
  }
  friend ModInt inverse(ModInt a) { return power(a, MOD - 2); }
  friend istream &operator>>(istream &is, ModInt &m) {
    is >> m.v;
    m.v = (-MOD < m.v && m.v < MOD) ? m.v : m.v % MOD;
    if (m.v < 0) m.v += MOD;
    return is;
  }
  friend ostream &operator<<(ostream &os, const ModInt &m) { return os << m.v; }
};
using M = ModInt<998244353>;
const int inf = 1e9;
int t;
const int maxn = 25;
int freq[maxn][26];
M dp[1 << 24];
M F[1 << 24];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string S;
    cin >> S;
    for (int j = 0; j < (int)S.size(); j++) {
      freq[i][S[j] - 'a']++;
    }
  }
  int maxmask = 1 << n;
  for (int mask = 1; mask < maxmask; mask++) {
    int par = __builtin_popcount(mask) % 2;
    vector<int> mn(26, inf);
    M to_add = 1;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        for (int j = 0; j < 26; j++) {
          mn[j] = min(mn[j], freq[i][j]);
        }
      }
    }
    for (int i = 0; i < 26; i++) {
      to_add *= M(mn[i] + 1);
    }
    dp[mask] = to_add;
    if (par == 0) dp[mask] = -to_add;
  }
  for (int i = 0; i < maxmask; ++i) F[i] = dp[i];
  for (int i = 0; i < n; ++i)
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (mask & (1 << i)) F[mask] = F[mask] + F[mask ^ (1 << i)];
    }
  long long ans = 0;
  for (int mask = 0; mask < maxmask; mask++) {
    int k = __builtin_popcount(mask);
    int sm = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) sm += (i + 1);
    }
    long long val = F[mask].v * (long long)k * (long long)sm;
    ans ^= val;
  }
  cout << ans << "\n";
}
