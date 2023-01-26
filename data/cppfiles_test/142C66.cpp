#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
long long int pow_mod(long long int a, long long int b) {
  long long int res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2;
  }
  return res;
}
long long int inv_mod(long long int a) { return pow_mod(a, mod - 2); }
void input(long long int a[], long long int n) {
  for (long long int i = 0; i < n; i++) cin >> a[i];
}
void output(long long int a[], long long int n, bool spaces = true) {
  for (long long int i = 0; i < n; i++) {
    cout << a[i];
    if (!spaces)
      cout << "\n";
    else
      cout << " ";
  }
  if (spaces) cout << endl;
}
void solve() {
  long long int m, n;
  cin >> m >> n;
  long long int p[m][n];
  bool f = false;
  for (long long int i = 0; i < m; i++) {
    for (long long int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }
  long long int ans = 0;
  ans = (long long int)1e18;
  for (long long int j = 0; j < n; j++) {
    long long int res = 0;
    for (long long int i = 0; i < m; i++) res = max(res, p[i][j]);
    ans = min(ans, res);
  }
  if (m >= n) {
    long long int mx = 0;
    for (long long int i = 0; i < m; i++) {
      for (long long int j = 0; j < n; j++) {
        for (long long int k = j + 1; k < n; k++)
          mx = max(mx, min(p[i][j], p[i][k]));
      }
    }
    if (mx < ans) ans = mx;
  }
  cout << ans << endl;
}
int main() {
  long long int t;
  t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
