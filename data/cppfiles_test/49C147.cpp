#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
class Mint {
 private:
  int value;

 public:
  constexpr Mint() : value() {}
  template <typename T>
  Mint(const T& x) {
    value = (-mod <= x && x < mod) ? x : x % mod;
    if (value < 0) value += mod;
  }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  Mint& operator+=(const Mint& a) {
    if ((value += a.value) >= mod) value -= mod;
    return *this;
  }
  Mint& operator-=(const Mint& a) {
    if ((value -= a.value) < 0) value += mod;
    return *this;
  }
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
  Mint operator-() const { return Mint(-value); }
  Mint& operator*=(const Mint& a) {
    value = (long long)value * a.value % mod;
    return *this;
  }
  Mint& operator/=(const Mint& a) {
    assert(a.value != 0);
    return *this *= inverse(a);
  }
  friend Mint pow(Mint a, int b) {
    Mint r = 1;
    for (; b; a *= a, b >>= 1) {
      if (b & 1) r *= a;
    }
    return r;
  }
  static Mint inverse(const Mint& a) { return pow(a, mod - 2); }
  friend bool operator==(const Mint& a, const Mint& b) {
    return a.value == b.value;
  }
  friend bool operator!=(const Mint& a, const Mint& b) {
    return a.value != b.value;
  }
  friend bool operator<(const Mint& a, const Mint& b) {
    return a.value < b.value;
  }
  friend Mint operator+(const Mint& a, const Mint& b) { return Mint(a) += b; }
  friend Mint operator-(const Mint& a, const Mint& b) { return Mint(a) -= b; }
  friend Mint operator*(const Mint& a, const Mint& b) { return Mint(a) *= b; }
  friend Mint operator/(const Mint& a, const Mint& b) { return Mint(a) /= b; }
  friend ostream& operator<<(ostream& stream, const Mint& a) {
    return stream << a.value;
  }
  friend istream& operator>>(istream& stream, Mint& a) {
    return stream >> a.value;
  }
  friend string to_string(const Mint& a) { return to_string(a.value); }
};
void foo() {
  int n;
  cin >> n;
  const int S = 1 << n;
  vector<int> f(n);
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  vector<vector<Mint>> p(n, vector<Mint>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      p[i][j] = Mint(f[i]) / (f[i] + f[j]);
    }
  }
  vector<vector<Mint>> all_out(n, vector<Mint>(S, 1));
  for (int i = 0; i < n; i++) {
    for (int s = 0; s < S; s++) {
      for (int u = 0; u < n; u++) {
        if (s & (1 << u)) {
          all_out[i][s] *= p[i][u];
        }
      }
    }
  }
  vector<map<int, Mint>> g(S);
  for (int s = 1; s < S; s++) {
    for (int j = s; j > 0; j = (j - 1) & s) {
      g[s][j] = 1;
      int other = s ^ j;
      for (int v = 0; v < n; v++) {
        if (j & (1 << v)) {
          g[s][j] *= all_out[v][other];
        }
      }
    }
  }
  vector<Mint> scc(S);
  for (int s = 1; s < S; s++) {
    scc[s] = 1;
    for (int sub = ((s - 1) & s); sub > 0; sub = (sub - 1) & s) {
      scc[s] -= scc[sub] * g[s][sub];
    }
  }
  Mint ans = 0;
  for (int i = 0; i < S; i++) {
    ans += scc[i] * g[S - 1][i] * __builtin_popcount(i);
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  foo();
}
