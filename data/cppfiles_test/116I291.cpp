#include <bits/stdc++.h>
using namespace std;
bool multi = true;
long long n, mod = 998244353, res = 0;
long long a[1000005], f[1000005][2];
void solve() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    f[i][0] = 0, f[i][1] = 0;
  }
  f[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    long long x = a[i];
    if (x) f[x - 1][1] = (2 * f[x - 1][1] + f[x - 1][0]) % mod;
    f[x + 1][0] = (2 * f[x + 1][0] + f[x][0]) % mod;
    f[x + 1][1] = (2 * f[x + 1][1]) % mod;
  }
  res = 0;
  for (long long i = 0; i <= n; i++) {
    res = (res + f[i][0] + f[i][1]) % mod;
    f[i][0] = 0, f[i][1] = 0;
  }
  cout << res - 1;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  if (multi) {
    cin >> t;
  }
  while (t--) {
    solve();
    cout << "\n";
  }
}
