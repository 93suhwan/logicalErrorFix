#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
class int_mod {
 private:
  int x;
  static int q_pow(int a, int x = mod - 2) {
    int res = 1;
    a = a % mod;
    while (x) {
      if (x & 1) {
        res = 1LL * res * a % mod;
      }
      a = 1LL * a * a % mod;
      x >>= 1;
    }
    return res;
  }

 public:
  int_mod(int v = 0) : x(v < 0 ? v + mod : v >= mod ? v - mod : v) {}
  int to_int() const { return x; }
  int_mod inv() const {
    assert(x);
    return int_mod(q_pow(x));
  }
  int_mod pow(int k) const { return int_mod(q_pow(x, k)); }
  int_mod operator-() const { return int_mod(mod - x); }
  int_mod& operator+=(const int_mod& oth) {
    x += oth.x;
    if (x >= mod) {
      x -= mod;
    }
    return *this;
  }
  int_mod& operator-=(const int_mod& oth) {
    x -= oth.x;
    if (x < 0) {
      x += mod;
    }
    return *this;
  }
  int_mod& operator*=(const int_mod& oth) {
    x = 1LL * x * oth.x % mod;
    return *this;
  }
  int_mod& operator/=(const int_mod& oth) {
    x = 1LL * x * q_pow(oth.x) % mod;
    return *this;
  }
  bool operator==(const int_mod& oth) const { return x == oth.x; }
  inline friend int_mod operator+(const int_mod& a, const int_mod& b) {
    return int_mod(a) += b;
  }
  inline friend int_mod operator-(const int_mod& a, const int_mod& b) {
    return int_mod(a) -= b;
  }
  inline friend int_mod operator*(const int_mod& a, const int_mod& b) {
    return int_mod(a) *= b;
  }
  inline friend int_mod operator/(const int_mod& a, const int_mod& b) {
    return int_mod(a) /= b;
  }
  inline friend istream& operator>>(istream& is, int_mod& a) {
    int x;
    is >> x;
    a = x;
    return is;
  }
  inline friend ostream& operator<<(ostream& os, const int_mod& a) {
    os << a.to_int();
    return os;
  }
};
const int maxn = 2e5 + 50;
int n, q;
int_mod a[maxn];
int_mod sum1[maxn];
int_mod sum2[maxn];
inline int_mod get_sum1(int l, int r) { return sum1[r] - sum1[l - 1]; }
inline int_mod get_sum2(int l, int r) { return sum2[r] - sum2[l - 1]; }
signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    sum1[i] = sum1[i - 1] + a[i];
    sum2[i] = sum2[i - 1] + a[i].pow(2);
  }
  while (q--) {
    int l, r;
    int_mod d;
    cin >> l >> r >> d;
    int_mod len = r - l + 1;
    int_mod x = (get_sum1(l, r) - d * (len - 1) * len / 2) / len;
    int_mod res1 = x * x * len + d * x * (len - 1) * len +
                   d * d * (len - 1) * len * (2 * len - 1) / 6;
    int_mod res2 = get_sum2(l, r);
    cout << (res1 == res2 ? "Yes" : "No") << '\n';
  }
  return 0;
}
