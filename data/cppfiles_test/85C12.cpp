#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const long long int MAX = 1e9 + 7;
void array_show(int* array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%d%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(long long int* array, int array_n, char middle = ' ') {
  for (int i = 0; i < array_n; i++)
    printf("%lld%c", array[i], (i != array_n - 1 ? middle : '\n'));
}
void array_show(vector<int>& vec_s, int vec_n = -1, char middle = ' ') {
  if (vec_n == -1) vec_n = vec_s.size();
  for (int i = 0; i < vec_n; i++)
    printf("%d%c", vec_s[i], (i != vec_n - 1 ? middle : '\n'));
}
void array_show(vector<long long int>& vec_s, int vec_n = -1,
                char middle = ' ') {
  if (vec_n == -1) vec_n = vec_s.size();
  for (int i = 0; i < vec_n; i++)
    printf("%lld%c", vec_s[i], (i != vec_n - 1 ? middle : '\n'));
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v1) {
  int n = v1.size();
  for (int i = 0; i < n; i++) {
    if (i) os << " ";
    os << v1[i];
  }
  return os;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  os << p.first << " " << p.second;
  return os;
}
template <typename T>
istream& operator>>(istream& is, vector<T>& v1) {
  int n = v1.size();
  for (int i = 0; i < n; i++) is >> v1[i];
  return is;
}
template <typename T1, typename T2>
istream& operator>>(istream& is, pair<T1, T2>& p) {
  is >> p.first >> p.second;
  return is;
}
template <typename T>
T ext_gcd(T a, T b, T& x, T& y) {
  if (a < b) return ext_gcd(b, a, y, x);
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  T gcd_val = ext_gcd(b, a % b, x, y);
  swap(x, y);
  y -= x * (a / b);
  if (x > b) y += (x / b) * a, x %= b;
  if (y > a) x += (y / a) * b, y %= a;
  return gcd_val;
}
long long int mod = 1e9 + 7;
class modint {
 private:
  long long int val;
  long long int gcd(long long int a, long long int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
  }

 public:
  bool prime = false;
  modint() : val(0) {}
  template <class T>
  modint(T a) {
    val = (long long int)a % mod;
    if (val < 0) val += mod;
  }
  long long int value() const { return val; }
  long long int get_mod() const { return mod; }
  modint& operator++() {
    val++;
    if (val == mod) val = 0;
    return *this;
  }
  modint operator++(int) {
    modint ans = *this;
    ++*this;
    return ans;
  }
  modint& operator--() {
    if (val == 0) val = mod;
    val--;
    return *this;
  }
  modint operator--(int) {
    modint ans = *this;
    --*this;
    return ans;
  }
  modint& operator+=(const modint& a) {
    val += a.value();
    if (val >= mod) val -= mod;
    return *this;
  }
  modint& operator-=(const modint& a) {
    val -= a.value();
    if (val < 0) val += mod;
    return *this;
  }
  modint& operator*=(const modint& a) {
    val *= a.value();
    if (val >= mod) val %= mod;
    return *this;
  }
  modint pow(long long int index) const {
    assert(index >= 0);
    if (prime && index >= mod - 1) index %= mod - 1;
    modint a = *this, ans = 1;
    for (long long int i = 1; i >= 0 && i <= index; i <<= 1) {
      if (index & i) ans *= a;
      a *= a;
    }
    return ans;
  }
  modint inverse() const {
    if (prime) {
      assert(val != 0);
      return pow(mod - 2);
    }
    long long int x, y;
    long long int g = ext_gcd<long long int>(val, mod, x, y);
    assert(g == 1);
    return x;
  }
  modint& operator/=(const modint& a) {
    if (prime) {
      *this = (*this) * a.inverse();
      return *this;
    }
    long long int g = gcd(val, a.value());
    modint a2 = a.value() / g;
    val /= g;
    *this = (*this) * a2.inverse();
    return *this;
  }
  friend modint operator-(const modint& a, const modint& b) {
    return (modint)a -= b;
  }
  friend modint operator+(const modint& a, const modint& b) {
    return (modint)a += b;
  }
  friend modint operator*(const modint& a, const modint& b) {
    return (modint)a *= b;
  }
  friend modint operator/(const modint& a, const modint& b) {
    return (modint)a /= b;
  }
  friend bool operator==(const modint& a, const modint& b) {
    return a.value() == b.value();
  }
  friend bool operator!=(const modint& a, const modint& b) {
    return a.value() != b.value();
  }
  friend modint pow(const modint& a, const long long int b) { return a.pow(b); }
  modint operator+() const { return *this; }
  modint operator-() const { return modint() - *this; }
  friend ostream& operator<<(ostream& os, const modint& a) {
    os << a.value();
    return os;
  }
  friend istream& operator>>(istream& is, modint& a) {
    long long int val;
    is >> val;
    a = val;
    return is;
  }
};
namespace sol {
const int N = 222;
modint kai[N];
modint comb[N][N];
void solve() {
  int n, mi;
  int i, j, k;
  int a, b, c;
  int x, y;
  cin >> n >> mod;
  modint s = 2;
  kai[0] = 1;
  for (i = 1; i < N; i++) {
    kai[i] = kai[i - 1] * i;
  }
  for (i = 1; i < N; i++) {
    for (j = 0; j <= i; j++) {
      comb[i][j] = kai[i] / (kai[j] * kai[i - j]);
    }
  }
  for (mi = n; mi >= 1; mi--) {
    vector<int> v1(n), v2(n + 1);
    v2[0] = 0;
    for (j = 0; j < n; j++) {
      v1[j] = max(n + 1 - j, mi);
      if (j && v1[j] == mi + 1) v1[j] = mi;
      v2[j + 1] = v2[j] + v1[j];
    }
    if (v1[0] * mi < v2[n]) break;
    x = v1[0] * mi - v2[n], y = v1[0] - v1.back();
    vector<vector<vector<modint> > > dp(
        n + 1, vector<vector<modint> >(x + 1, vector<modint>(y + 2)));
    dp[0][x][y + 1] = 1;
    for (i = 0; i < n; i++) {
      for (j = 0; j <= x; j++) {
        for (k = 0; k <= y + 1; k++) {
          if (dp[i][j][k] == 0) continue;
          for (a = v1[i] - mi; a < k; a++) {
            for (b = i + 1; b <= n; b++) {
              c = v2[b] - v2[i];
              c = (a + mi) * (b - i) - c;
              if (j < c) break;
              dp[b][j - c][a] += dp[i][j][k] * comb[b][i];
            }
          }
        }
      }
    }
    for (i = 0; i <= x; i++) {
      s += dp[n][i][0];
    }
  }
  cout << s << endl;
}
}  // namespace sol
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  sol::solve();
}
