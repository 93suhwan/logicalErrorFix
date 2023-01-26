#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long pwr = 1;
    long long ans = 0;
    long long MOD = 1000000007;
    for (long long j = 0; j < 31; j++) {
      if (k & (1 << j)) ans = (ans + pwr) % MOD;
      pwr *= n;
      pwr = pwr % MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
