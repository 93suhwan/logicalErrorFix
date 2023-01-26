#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, INF = 2e18;
const double PI = 3.141592653589793;
long long seiveSize = 0, factorialSize = 0;
vector<bool> seive(seiveSize + 1, 1);
vector<long long> fact(factorialSize + 1, 1);
void eSeive(long long n = seiveSize) {
  for (long long i = 4; i <= n; i += 2) seive[i] = 0;
  for (long long i = 3; i <= n; i += 2)
    for (long long j = i * i; j <= n; j += i) seive[j] = 0;
}
void facto(long long n = factorialSize) {
  for (long long i = 2; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
}
void solve() {
  long long n, m, t;
  cin >> n >> m >> t;
  char a[n][m], b[n][m];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      cin >> a[i][j];
      b[i][j] = '.';
    }
  }
  for (long long i = 1; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (i < t) break;
      if (a[i][j] == '*') {
        long long c = 0;
        for (long long p = 1;; p++) {
          if (i - p < 0 || j - p < 0 || j + p >= m) break;
          if (a[i - p][j - p] == '*' && a[i - p][j + p] == '*') {
            c++;
          } else
            break;
        }
        if (c >= t) {
          b[i][j] = '*';
          for (long long p = 1;; p++) {
            if (i - p < 0 || j - p < 0 || j + p >= m) break;
            if (a[i - p][j - p] == '*' && a[i - p][j + p] == '*') {
              b[i - p][j - p] = b[i - p][j + p] = '*';
            } else
              break;
          }
        }
      }
    }
  }
  bool test = true;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (a[i][j] != b[i][j]) {
        test = false;
      }
    }
  }
  if (test)
    cout << "YES\n";
  else
    cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long _t = 1;
  cin >> _t;
  while (_t--) solve();
  return 0;
}
