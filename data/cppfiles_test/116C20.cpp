#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, x, i;
  long long mod = 998244353;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> dp1(n + 2);
    vector<long long> dp2(n + 2);
    dp1[0] = 1;
    for (i = 0; i < n; i++) {
      cin >> x;
      dp1[x + 1] = (((dp1[x + 1] * 2) % mod) + dp1[x]) % mod;
      if (x > 0) {
        dp2[x - 1] = (((dp2[x - 1] * 2) % mod) + dp1[x - 1]) % mod;
      }
      dp2[x + 1] = (dp2[x + 1] * 2) % mod;
    }
    long long res = 0;
    for (i = 0; i < n + 2; i++) {
      res = (res + dp1[i]) % mod;
      res = (res + dp2[i]) % mod;
    }
    res = (res + mod - 1) % mod;
    cout << res << "\n";
  }
  return 0;
}
