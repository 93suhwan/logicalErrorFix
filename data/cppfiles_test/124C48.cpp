#include <bits/stdc++.h>
using namespace std;
const int N = (int)2005;
const int MOD = (int)1e9 + 7;
struct mi {
  typedef decay<decltype(MOD)>::type T;
  T v;
  explicit operator T() const { return v; }
  mi() { v = 0; }
  mi(long long _v) {
    v = (-MOD < _v && _v < MOD) ? _v : _v % MOD;
    if (v < 0) v += MOD;
  }
  friend bool operator==(const mi& a, const mi& b) { return a.v == b.v; }
  friend bool operator!=(const mi& a, const mi& b) { return !(a == b); }
  friend bool operator<(const mi& a, const mi& b) { return a.v < b.v; }
  mi& operator+=(const mi& m) {
    if ((v += m.v) >= MOD) v -= MOD;
    return *this;
  }
  mi& operator-=(const mi& m) {
    if ((v -= m.v) < 0) v += MOD;
    return *this;
  }
  mi& operator*=(const mi& m) {
    v = (long long)v * m.v % MOD;
    return *this;
  }
  mi& operator/=(const mi& m) { return (*this) *= inv(m); }
  friend mi pow(mi a, long long p) {
    mi ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a)
      if (p & 1) ans *= a;
    return ans;
  }
  friend mi inv(const mi& a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  mi operator-() const { return mi(-v); }
  mi& operator++() { return *this += 1; }
  mi& operator--() { return *this -= 1; }
  friend mi operator+(mi a, const mi& b) { return a += b; }
  friend mi operator-(mi a, const mi& b) { return a -= b; }
  friend mi operator*(mi a, const mi& b) { return a *= b; }
  friend mi operator/(mi a, const mi& b) { return a /= b; }
};
int n;
string s0, s1;
mi dp[N][2 * N];
mi dp0[N][2 * N];
char flip(char c) {
  if (c == '1')
    return '0';
  else if (c == '0')
    return '1';
  return '?';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> s0 >> s1;
    s0 = " " + s0;
    s1 = " " + s1;
    for (int i = 2; i <= n; i += 2) {
      s0[i] = flip(s0[i]);
      s1[i] = flip(s1[i]);
    }
    for (int i = 0; i < (n + 1); ++i) {
      fill(dp[i], dp[i] + 2 * N, 0);
      fill(dp0[i], dp0[i] + 2 * N, 0);
    }
    dp0[0][N] = 1;
    for (int i = 1; i <= n; i++) {
      int a0 = (s0[i] == '?' || s0[i] == '0');
      int a1 = (s0[i] == '?' || s0[i] == '1');
      int b0 = (s1[i] == '?' || s1[i] == '0');
      int b1 = (s1[i] == '?' || s1[i] == '1');
      for (int j = 0; j < 2 * N; j++) {
        if (a0 && b0) {
          dp[i][j] += (dp[i - 1][j] + abs(j - N) * dp0[i - 1][j]);
          dp0[i][j] += dp0[i - 1][j];
        }
        if (a1 && b1) {
          dp[i][j] += (dp[i - 1][j] + abs(j - N) * dp0[i - 1][j]);
          dp0[i][j] += dp0[i - 1][j];
        }
        if (a0 && b1 && j < 2 * N) {
          dp[i][j] += (dp[i - 1][j + 1] + abs(j + 1 - N) * dp0[i - 1][j + 1]);
          dp0[i][j] += dp0[i - 1][j + 1];
        }
        if (a1 && b0 && j >= 1) {
          dp[i][j] += (dp[i - 1][j - 1] + abs(j - 1 - N) * dp0[i - 1][j - 1]);
          dp0[i][j] += dp0[i - 1][j - 1];
        }
      }
    }
    cout << (int)dp[n][N] << endl;
  }
}
