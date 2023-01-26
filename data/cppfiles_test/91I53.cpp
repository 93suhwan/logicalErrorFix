#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<long long>;
using vpii = vector<pair<int, int>>;
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using vvpii = vector<vector<pair<int, int>>>;
using mii = map<int, int>;
using seti = set<int>;
using useti = unordered_set<int>;
template <int mod>
struct Mod {
  long long x;
  Mod() : x(0) {}
  Mod(long long xx) : x(xx) {
    if (abs(x) >= mod) x %= mod;
    if (x < 0) x += mod;
  }
  operator int() const { return x; }
  operator long long() const { return x; }
  Mod operator+(const Mod &a) const {
    Mod n;
    n.x = x + a.x;
    if (n.x >= mod) n.x -= mod;
    return n;
  }
  Mod operator-(const Mod &a) const {
    Mod n;
    n.x = x - a.x;
    if (n.x < 0) n.x += mod;
    return n;
  }
  Mod operator*(const Mod &a) const { return x * a.x; }
  Mod operator+=(const Mod &a) {
    x += a.x;
    if (x >= mod) x -= mod;
    return *this;
  }
  Mod operator-=(const Mod &a) {
    x -= a.x;
    if (x < 0) x += mod;
    return *this;
  }
  Mod operator++() {
    *this += 1;
    return *this;
  }
  Mod operator++(int) {
    Mod temp = *this;
    *this += 1;
    return temp;
  }
  Mod operator--() {
    *this -= 1;
    return *this;
  }
  Mod operator--(int) {
    Mod temp = *this;
    *this -= 1;
    return temp;
  }
  Mod operator*=(const Mod &a) {
    x = (x * a.x) % mod;
    return *this;
  }
  Mod pow(long long b) const {
    Mod ans = 1;
    Mod a = *this;
    while (b > 0) {
      if (b & 1) ans *= a;
      a *= a;
      b /= 2;
    }
    return ans;
  }
  Mod inv() const { return pow(mod - 2); }
  Mod operator/(const Mod &a) const { return (*this) * a.inv(); }
  Mod operator/=(const Mod &a) { return (*this) *= a.inv(); }
  bool operator==(const Mod &o) const { return x == o.x; }
  bool operator!=(const Mod &o) const { return x != o.x; }
  long long operator()() const { return x; }
  template <int _mod>
  friend ostream &operator<<(ostream &os, const Mod<_mod> &num) {
    os << num.x;
    return os;
  }
  template <int _mod>
  friend istream &operator>>(istream &is, Mod<_mod> &num) {
    is >> num.x;
    if (abs(num.x) >= mod) num.x %= mod;
    if (num.x < 0) num.x += mod;
    return is;
  }
};
using base = Mod<998244353>;
using vbase = vector<base>;
using vvbase = vector<vector<base>>;
base two = 2;
using umii = unordered_map<int, pair<int, base>>;
pair<int, base> operator+(pair<int, base> a, pair<int, base> b) {
  pair<int, base> ans = {0, 0};
  ans.first = a.first + b.first;
  ans.second = a.second + b.second;
  return ans;
}
inline void __run_test() {
  int n;
  cin >> n;
  vi a(n);
  for (int i = 0; i < (n); i++) cin >> a[i];
  umii *possible = new umii();
  base res = 0;
  for (int i = (n)-1; i >= 0; i--) {
    umii *temp = new umii();
    (*temp)[a[i]] = {1, 0};
    for (auto d : *possible) {
      if (d.first >= a[i]) {
        if (i) (*temp)[min(a[i], a[i - 1])] = (*temp)[a[i]] + d.second;
        res += base(d.second.second);
      } else {
        int divs = (a[i] + d.first - 1) / d.first;
        res += base(d.second.first) * base(divs - 1) + base(d.second.second);
        if (i)
          (*temp)[min(a[i - 1], a[i] / divs)] =
              (*temp)[a[i] / divs] +
              make_pair(d.second.first, d.second.second + base(d.second.first) *
                                                              base(divs - 1));
      }
    }
    delete possible;
    possible = temp;
  }
  cout << res << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int __tests;
  cin >> __tests;
  while (__tests--) __run_test();
}
