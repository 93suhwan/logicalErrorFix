#include <bits/stdc++.h>
using namespace std;
template <int MOD>
class ModInt {
 public:
  int v;
  ModInt() : v(0) {}
  ModInt(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? (_v) : (_v % MOD));
    if (v < 0) v += MOD;
  }
  friend bool operator==(const ModInt &a, const ModInt &b) {
    return a.v == b.v;
  }
  friend bool operator!=(const ModInt &a, const ModInt &b) {
    return a.v != b.v;
  }
  friend bool operator<(const ModInt &a, const ModInt &b) { return a.v < b.v; }
  friend bool operator<=(const ModInt &a, const ModInt &b) {
    return a.v <= b.v;
  }
  friend bool operator>(const ModInt &a, const ModInt &b) { return a.v > b.v; }
  friend bool operator>=(const ModInt &a, const ModInt &b) {
    return a.v >= b.v;
  }
  ModInt &operator+=(const ModInt &a) {
    if ((v += a.v) >= MOD) v -= MOD;
    return *this;
  }
  ModInt &operator-=(const ModInt &a) {
    if ((v -= a.v) < 0) v += MOD;
    return *this;
  }
  ModInt &operator*=(const ModInt &a) {
    v = 1ll * v * a.v % MOD;
    return *this;
  }
  ModInt &operator/=(const ModInt &a) { return (*this) *= inverse(a); }
  friend ModInt pow(ModInt a, long long x) {
    ModInt res = 1;
    assert(x >= 0);
    for (; x; x /= 2, a *= a)
      if (x & 1) res *= a;
    return res;
  }
  friend ModInt inverse(ModInt a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  ModInt operator+() const { return ModInt(v); }
  ModInt operator-() const { return ModInt(-v); }
  ModInt operator++() const { return *this += 1; }
  ModInt operator--() const { return *this -= 1; }
  friend ModInt operator+(ModInt a, const ModInt &b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt &b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt &b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt &b) { return a /= b; }
  friend istream &operator>>(istream &is, ModInt &v) {
    is >> v.v;
    return is;
  }
  friend ostream &operator<<(ostream &os, const ModInt &v) {
    os << v.v;
    return os;
  }
};
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
using Mint = ModInt<MOD>;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  vector<int> prime(MAX);
  vector<int> mobius(MAX);
  for (int i = 1; i < MAX; i++) {
    prime[i] = true;
    mobius[i] = 1;
  }
  for (int i = 2; i < MAX; i++) {
    if (!prime[i]) {
      continue;
    }
    for (int j = i + i; j < MAX; j += i) {
      prime[j] = false;
    }
    for (int j = i; j < MAX; j += i) {
      mobius[j] *= -1;
    }
    for (long long j = 1ll * i * i; j < MAX; j += 1ll * i * i) {
      mobius[j] = 0;
    }
  }
  vector<vector<int>> divisors(MAX);
  for (int i = 1; i < MAX; i++) {
    for (int j = i; j < MAX; j += i) {
      divisors[j].emplace_back(i);
    }
  }
  vector<Mint> dp_mu(MAX);
  for (int i = 1; i < MAX; i++) {
    Mint add = Mint(1) * mobius[i] / i;
    for (int j = i; j < MAX; j += i) {
      dp_mu[j] += add;
    }
  }
  vector<int> que;
  vector<int> freq(MAX);
  const auto Solve = [&](int q) {
    for (int i = q; i <= N; i += q) {
      for (auto p : divisors[A[i]]) {
        freq[p]++;
        if (freq[p] == 1) {
          que.emplace_back(p);
        }
      }
    }
    Mint res = 0;
    for (auto p : que) {
      res += p * dp_mu[p] * freq[p] * freq[p];
    }
    for (auto p : que) {
      freq[p] = 0;
    }
    que.clear();
    return res;
  };
  Mint ans = 0;
  for (int q = 1; q <= N; q++) {
    ans += q * dp_mu[q] * Solve(q);
  }
  cout << ans << '\n';
  return 0;
}
