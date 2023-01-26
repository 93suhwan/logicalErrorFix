#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
long long ceel(long long a, long long b) { return ((a + b - 1ll) / b); }
void solve() {
  long long n;
  cin >> n;
  long long a[n][5];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < 5; j++) {
      cin >> a[i][j];
    }
  }
  long long flag = 0;
  for (long long i = 0; i < 5; i++) {
    for (long long j = 0; j < 5; j++) {
      if (i == j) continue;
      long long f = 0;
      long long s = 0;
      long long b = 0;
      for (long long k = 0; k < n; k++) {
        if (a[k][i] && a[k][j])
          b++;
        else if (a[k][i])
          f++;
        else if (a[k][j])
          s++;
      }
      if (f < n / 2) {
        long long rem = n / 2 - f;
        b -= rem;
      }
      if (s < n / 2) {
        long long rem = n / 2 - s;
        b -= rem;
      }
      if (b >= 0) {
        flag = 1;
      }
    }
  }
  if (flag)
    cout << "YES" << '\n';
  else
    cout << "NO" << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  for (long long tc = 0; tc < t; tc++) solve();
  return 0;
}
