#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  for (auto& i : v) os << i << " ";
  return os;
}
template <typename T>
istream& operator>>(istream& is, pair<T, T>& v) {
  is >> v.first >> v.second;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, const pair<T, T>& v) {
  os << v.first << " " << v.second;
  return os;
}
inline int64_t gcd(int64_t a, int64_t b) {
  int64_t r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
inline int64_t egcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  x = 1, y = 0;
  int64_t x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int64_t q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}
inline int64_t mypow(int64_t base, int64_t exp) {
  int64_t result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base);
    base = (base * base);
    exp >>= 1;
  }
  return result;
}
inline int64_t modpow(int64_t base, int64_t exp, int64_t modulus) {
  base %= modulus;
  int64_t result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
inline int64_t log2(int64_t n) {
  int64_t r = 0;
  while (n >>= 1) r++;
  return r;
}
struct Matrix {
  int n;
  vector<vector<int64_t> > a;
  Matrix(int n = 0) : n(n) { a.assign(n, vector<int64_t>(n, 0)); }
  static Matrix identity(int n) {
    Matrix res(n);
    for (int i = 0; i < n; i++) {
      res.a[i][i] = 1;
    }
    return res;
  }
  Matrix operator*(Matrix& rhs) {
    Matrix res(this->n);
    assert(this->n == rhs.n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          res.a[i][j] += a[i][k] * rhs.a[k][j];
          res.a[i][j] %= 1000000007;
        }
      }
    }
    return res;
  }
};
Matrix mypow(Matrix base, uint64_t exp) {
  Matrix result = Matrix::identity(base.n);
  while (exp > 0) {
    if (exp & 1) result = (result * base);
    base = (base * base);
    exp >>= 1;
  }
  return result;
}
void solve() {
  int64_t l, r;
  cin >> l >> r;
  if (l == r) {
    cout << 0 << endl;
    return;
  }
  int64_t res = 1e9;
  auto calc = [](int64_t v, int64_t i) {
    int64_t res = ((v + 1) / i) * i / 2;
    int64_t rem = (v + 1) % i;
    if (rem < (i / 2))
      res += rem;
    else
      res += i / 2;
    return res;
  };
  for (int64_t i = 2; i < 2 * r; i *= 2) {
    int64_t rres = calc(r, i);
    int64_t lres = calc(l - 1, i);
    res = min(res, rres - lres);
  }
  cout << res << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
