#include <bits/stdc++.h>
constexpr int MOD = 998244353;
struct mi {
  int v;
  explicit operator int() const { return v; }
  mi() : v(0) {}
  mi(long long _v) : v(int(_v % MOD)) { v += (v < 0) * MOD; }
};
mi& operator+=(mi& a, mi b) {
  if ((a.v += b.v) >= MOD) a.v -= MOD;
  return a;
}
mi& operator-=(mi& a, mi b) {
  if ((a.v -= b.v) < 0) a.v += MOD;
  return a;
}
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((long long)a.v * b.v); }
mi& operator*=(mi& a, mi b) { return a = a * b; }
mi pow(mi a, long long p) {
  return p == 0 ? 1 : pow(a * a, p / 2) * (p & 1 ? a : 1);
}
mi inv(mi a) { return pow(a, MOD - 2); }
mi operator/(mi a, mi b) { return a * inv(b); }
bool operator==(mi a, mi b) { return a.v == b.v; }
using std::cin;
using std::cout;
constexpr int MAX_N = 200004;
mi fac[MAX_N];
mi facInv[MAX_N];
void solve() {
  int n;
  cin >> n;
  fac[0] = 1;
  for (int i = 1; i < MAX_N; i++) fac[i] = fac[i - 1] * mi(i);
  facInv[MAX_N - 1] = inv(fac[MAX_N - 1]);
  for (int i = MAX_N - 1; i >= 1; i--) facInv[i - 1] = facInv[i] * mi(i);
  auto C = [&](int n, int m) { return fac[n] * facInv[n - m] * facInv[m]; };
  std::map<char, std::vector<char> > choice;
  choice['?'].push_back('W');
  choice['?'].push_back('B');
  choice['B'].push_back('B');
  choice['W'].push_back('W');
  int cB = 0;
  int cW = 0;
  std::vector<int> cBW(n);
  std::vector<int> cWB(n);
  std::vector<int> count(n);
  for (int i = 0; i < n; i++) {
    char l, r;
    cin >> l >> r;
    if (l == 'B') cB += 1;
    if (l == 'W') cW += 1;
    if (r == 'B') cB += 1;
    if (r == 'W') cW += 1;
    for (char c1 : choice[l]) {
      for (char c2 : choice[r]) {
        if (c1 == 'B' && c2 == 'W') {
          cBW[i] = 1;
        }
        if (c1 == 'W' && c2 == 'B') {
          cWB[i] = 1;
        }
      }
    }
  }
  if (cB > n || cW > n) {
    cout << 0 << "\n";
    return;
  }
  mi ans = C(2 * n - cB - cW, n - cB);
  mi tot1 = 1;
  int tot2 = 1;
  int tot3 = 1;
  for (int i = 0; i < n; i++) {
    tot1 *= (cBW[i] + cWB[i]);
    tot2 *= cBW[i];
    tot3 *= cWB[i];
  }
  ans -= tot1;
  ans += tot2 + tot3;
  cout << ans.v;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  solve();
  return 0;
}
