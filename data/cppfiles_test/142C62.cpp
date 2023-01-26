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
  vector<vector<long long int>> p(m, vector<long long int>(n, -1));
  bool f = false;
  for (long long int i = 0; i < m; i++) {
    for (long long int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }
  long long int low = 0;
  long long int high = (long long int)1e18;
  long long int ans = -1;
  function<bool(long long int)> ok = [&](long long int x) {
    bool f = true;
    for (long long int j = 0; j < n; j++) {
      long long int cnt = 0;
      for (long long int i = 0; i < m; i++) {
        if (p[i][j] >= x) ++cnt;
      }
      if (!cnt) {
        f = false;
        break;
      }
    }
    if (!f) return f;
    f = false;
    for (long long int i = 0; i < m; i++) {
      long long int cnt = 0;
      for (long long int j = 0; j < n; j++)
        if (p[i][j] >= x) ++cnt;
      if (cnt >= 2) return true;
    }
    return f;
  };
  while (low <= high) {
    long long int mid = (low + high) / 2;
    if (ok(mid)) {
      ans = mid;
      low = mid + 1;
    } else
      high = mid - 1;
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
