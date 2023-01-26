#include <bits/stdc++.h>
using namespace std;
const long long FULL = (1e5) + 100;
const long long INF = 1e18;
const long long MOD = (1e9) + 7;
long long dp[FULL];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(9);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<bool> mp(n + 3);
    for (long long i = 0; i < m; i++) {
      long long a, b, c;
      cin >> a >> b >> c;
      mp[b] = 1;
    }
    for (long long i = 1; i <= n; i++) {
      if (mp[i] == 0) {
        for (long long j = 1; j <= n; j++) {
          if (j != i) cout << i << ' ' << j << '\n';
        }
        break;
      }
    }
  }
  return 0;
}
