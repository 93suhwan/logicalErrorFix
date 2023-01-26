#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
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
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int S = 1 << n;
  vector<vector<int>> cntL(n, vector<int>(26));
  for (int i = 0; i < n; i++) {
    for (char ch : a[i]) {
      cntL[i][ch - 'a']++;
    }
  }
  vector<Mint> cnt1(n, Mint(1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      cnt1[i] *= cntL[i][j] + 1;
    }
  }
  vector<Mint> cnt(S, Mint(1));
  cnt[0] = 0;
  for (int m = 1; m < S; m++) {
    for (int c = 0; c < 26; c++) {
      int mn = 1e9;
      for (int i = 0; i < n; i++) {
        if (m & (1 << i)) {
          mn = min(mn, cntL[i][c]);
        }
      }
      cnt[m] *= mn + 1;
    }
    if (__builtin_parity(m) == 0) {
      cnt[m] = -cnt[m];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int s = S - 1; s > 0; s--) {
      if (s & (1 << i)) {
        cnt[s] += cnt[s ^ (1 << i)];
      }
    }
  }
  long long ans = 0;
  for (int s = 1; s < S; s++) {
    int sum = 0;
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (s & (1 << i)) {
        sum += i + 1;
        k++;
      }
    }
    ans ^= (long long)cnt[s] * k * sum;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  foo();
}
