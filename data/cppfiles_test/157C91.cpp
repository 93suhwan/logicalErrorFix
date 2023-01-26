#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
template <long long MOD>
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
const long long mod = 998244353;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  string str;
  cin >> n >> k >> str;
  vector<long long> prefix(n + 1);
  prefix[0] = 0;
  for (long long x = 0; x < n; x++) {
    prefix[x + 1] = prefix[x] + (str[x] == '1');
  }
  vector<ModInt<mod> > factorials(n + 1);
  factorials[0] = 1;
  for (long long x = 1; x <= n; x++) {
    factorials[x] = (factorials[x - 1] * x);
  }
  map<pair<long long, long long>, long long> map3;
  ModInt<mod> total = 0;
  for (long long x = 0; x < n; x++) {
    for (long long y = x + 1; y < n; y++) {
      long long ones = prefix[y + 1] - prefix[x];
      long long zeros = y - x + 1 - ones;
      if (ones <= k) {
        if (str[x] == '1') {
          zeros--;
        }
        if (str[x] == '0') {
          ones--;
        }
        if (str[y] == '1') {
          zeros--;
        }
        if (str[y] == '0') {
          ones--;
        }
        if (ones >= 0 && zeros >= 0) {
          if (zeros < ones) {
            swap(zeros, ones);
          }
          map3[make_pair(zeros, ones)]++;
        }
      }
    }
  }
  while (map3.size() > 0) {
    pair<pair<long long, long long>, long long> curr = *map3.begin();
    total += curr.second * factorials[curr.first.first + curr.first.second] /
             factorials[curr.first.first] / factorials[curr.first.second];
    map3.erase(curr.first);
  }
  if (prefix[n] < k) {
    total = 0;
  }
  total += 1;
  cout << total << "\n";
  return 0;
}
