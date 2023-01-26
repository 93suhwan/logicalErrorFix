#include <bits/stdc++.h>
using namespace std;
const long long max_n = 2e5 + 10, max_m = 3e5 + 10, mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, k, n;
  cin >> t;
  while (t--) {
    long long ans = 0;
    cin >> n >> k;
    for (long long i = 1; k; i *= n, k /= 2) ans = (ans + i * (k % 2)) % mod;
    cout << ans % mod << '\n';
  }
}
