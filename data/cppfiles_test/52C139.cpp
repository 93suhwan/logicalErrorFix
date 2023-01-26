#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
long long int binmod(long long int k, long long int x) {
  if (x == 0) return 1;
  if (x == 1) return k % mod;
  long long int res = binmod(k, x / 2);
  if (x % 2) return ((res * res % mod) * k) % mod;
  return res * res % mod;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int TESTCASE;
  cin >> TESTCASE;
  while (TESTCASE--) {
    long long int n, k;
    cin >> n >> k;
    vector<long long int> bit(32);
    for (long long int i = 0; i < 32; i++) {
      if (k & (1 << i)) {
        bit[i] = 1;
      }
    }
    long long int ans = 0;
    for (long long int i = 0; i < 32; i++) {
      if (bit[i]) ans = (ans + binmod(n, i)) % mod;
    }
    cout << ans << "\n";
  }
  return 0;
}
