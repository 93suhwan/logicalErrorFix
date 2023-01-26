#include <bits/stdc++.h>
using namespace std;
template <class T>
using maxheap = priority_queue<T, vector<T>, less<T>>;
template <class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
void setmax(T& a, T b) {
  a = max(a, b);
};
template <typename T>
void setmin(T& a, T b) {
  a = min(a, b);
};
template <typename T>
bool in(T lo, T v, T hi) {
  return lo <= v && v <= hi;
};
template <typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
  out << "[";
  int n = v.size();
  for (int i = 0; i < n; i++) out << v[i] << (i + 1 < n ? ", " : "");
  out << "]";
  return out;
}
struct timestamp {
  string algo;
  long double A, B;
  timestamp(string _algo) {
    algo = _algo;
    A = B = clock();
  }
  void print() {
    long double B_ = clock();
    long double section = (B_ - B) / CLOCKS_PER_SEC;
    long double cumulative = (B_ - A) / CLOCKS_PER_SEC;
    cout << algo << " profile(seconds): section: " << section
         << " cumulative: " << cumulative << '\n'
         << flush;
    B = B_;
  }
};
template <long long MOD>
struct ModInt {
  long long x = 0;
  ModInt() { x = 0; }
  ModInt(long long _x) {
    x = _x;
    if (x >= MOD || x <= -MOD) x %= MOD;
    if (x < 0) x += MOD;
  }
  friend ModInt operator+(ModInt a, ModInt b) { return ModInt(a.x + b.x); }
  friend ModInt operator-(ModInt a, ModInt b) { return ModInt(a.x - b.x); }
  friend ModInt operator*(ModInt a, ModInt b) { return ModInt(a.x * b.x); }
  friend ModInt operator/(ModInt a, ModInt b) { return a * inv(b); }
  friend ModInt operator+=(ModInt& a, ModInt b) { return a = a + b; }
  friend ModInt power(ModInt a, long long b) {
    if (b == 0) return 1;
    ModInt c = power(a, b / 2);
    return c * c * ((b & 1) ? a : 1);
  }
  friend ModInt inv(ModInt a) { return power(a, MOD - 2); }
  friend ostream& operator<<(ostream& os, const ModInt& a) {
    os << a.x;
    return os;
  }
  friend istream& operator>>(istream& is, ModInt& a) {
    long long y;
    is >> y;
    a = ModInt(y);
    return is;
  }
};
using mint = ModInt<998244353>;
using vm = vector<mint>;
using vvm = vector<vm>;
struct Solution {
  long long xor_sum(long long n) {
    if (n == 0) return 0;
    long long X = 0;
    for (int i = 0; i < 22; i++) {
      long long cnt = (n / (1 << (i + 1))) * (i + 1);
      long long rem = n % (1 << (i + 1));
      cnt += max(0ll, rem - (1 << i) + 1);
      if (cnt & 1) X ^= (1 << i);
    }
    return X;
  }
  void solve() {
    long long m, x;
    cin >> m >> x;
    long long y = xor_sum(m - 1);
    long long target = y ^ x;
    if (y == x) {
      cout << m << '\n';
    } else if (target == m) {
      cout << (m + 2) << '\n';
    } else {
      cout << (m + 1) << '\n';
    }
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    Solution second;
    second.solve();
  }
  return 0;
}
