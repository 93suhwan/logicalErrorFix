#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
typedef decay<decltype(MOD)>::type T;
struct mi {
  T val;
  explicit operator T() const { return val; }
  mi() { val = 0; }
  mi(const long long& v) {
    val = (-MOD <= v && v < MOD) ? v : v % MOD;
    if (val < 0) val += MOD;
  }
  friend ostream& operator<<(ostream& os, const mi& a) { return os << a.val; }
  friend bool operator==(const mi& a, const mi& b) { return a.val == b.val; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.val < b.val; }
  mi operator-() const { return mi(-val); }
  mi& operator+=(const mi& m) {
    if ((val += m.val) >= MOD) val -= MOD;
    return *this;
  }
  mi& operator-=(const mi& m) {
    if ((val -= m.val) < 0) val += MOD;
    return *this;
  }
  mi& operator*=(const mi& m) {
    val = (long long)val * m.val % MOD;
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
    return pow(a, MOD - 2);
  }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int e = 0, o = 0;
    int arr[n];
    for (long long i = 0; i < n; i++) {
      int x;
      cin >> x;
      arr[i] = x % 2;
      if (arr[i]) {
        o++;
      } else {
        e++;
      }
    }
    if (n % 2 == 0) {
      if (o != e) {
        cout << -1 << '\n';
        ;
        continue;
      }
    } else {
      if (abs(o - e) > 1) {
        cout << -1 << '\n';
        ;
        continue;
      }
    }
    int cur = 0;
    long long r1 = 0;
    for (int i = 1; i < n; i += 2) {
      while (arr[cur] != 1) {
        cur++;
      }
      r1 += abs(cur - i);
      cur++;
    }
    cur = 0;
    long long r2 = 0;
    for (int i = 0; i < n; i += 2) {
      while (arr[cur] != 1) {
        cur++;
      }
      r2 += abs(cur - i);
      cur++;
    }
    cout << min(r1, r2) << '\n';
    ;
  }
}
