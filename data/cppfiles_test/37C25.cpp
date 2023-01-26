#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
ostream& operator<<(ostream& cout, pair<A, B> const& p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v) {
  cout << "[";
  for (int i = 0; i < (int)v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
typedef std::decay<decltype(998244353)>::type mod_t;
struct mi {
  mod_t val;
  explicit operator mod_t() const { return val; }
  mi() { val = 0; }
  mi(const long long& v) {
    val = (-998244353 <= v && v < 998244353) ? v : v % 998244353;
    if (val < 0) val += 998244353;
  }
  friend std::istream& operator>>(std::istream& in, mi& a) {
    long long x;
    std::cin >> x;
    a = mi(x);
    return in;
  }
  friend std::ostream& operator<<(std::ostream& os, const mi& a) {
    return os << a.val;
  }
  friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
  friend bool operator>(const mi& a, const mi& b) { return a.val > b.val; }
  friend bool operator<=(const mi& a, const mi& b) { return a.val <= b.val; }
  friend bool operator>=(const mi& a, const mi& b) { return a.val >= b.val; }
  mi operator-() const { return mi(-val); }
  mi& operator+=(const mi& m) {
    if ((val += m.val) >= 998244353) val -= 998244353;
    return *this;
  }
  mi& operator-=(const mi& m) {
    if ((val -= m.val) < 0) val += 998244353;
    return *this;
  }
  mi& operator*=(const mi& m) {
    val = (long long)val * m.val % 998244353;
    return *this;
  }
  friend mi pow(mi a, long long p) {
    mi ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) {
    assert(a != 0);
    return pow(a, 998244353 - 2);
  }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  for (int ti = 0; ti < (t); ti++) {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < (n - 1); i++) {
      int x, y;
      cin >> x >> y;
      x--;
      y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    vector<mi> v(n);
    bool good;
    function<bool(int, int, int)> check = [&](int u, int par, int k) {
      int x = 0;
      for (int oth : adj[u])
        if (oth != par) x += check(oth, u, k);
      if (x % k == 0) {
        return true;
      }
      if ((x + 1) % k == 0) {
        return false;
      }
      good = false;
      return false;
    };
    for (int k = 2; k <= n; k++) {
      if ((n - 1) % k) continue;
      good = true;
      if (!check(0, -1, k)) good = false;
      if (good) {
        v[k - 1] = true;
      }
    }
    for (int k = n; k >= 2; k--) {
      for (int z = k + k; z <= n; z += k) {
        if (v[z - 1] > 0) v[k - 1] = 0;
      }
    }
    v[0] = pow((mi)2, n - 1);
    for (int i = 1; i < n; i++) {
      v[0] -= v[i];
    }
    for (int i = 0; i < (n); i++) cout << v[i] << " ";
    cout << "\n";
  }
}
