#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    long long pw = 1;
    for (int i = 0; i < 32; ++i) {
      if (k & (1 << i)) ans = (ans + pw);
      if (ans >= mod) ans -= mod;
      pw = pw * n % mod;
    }
    cout << ans << '\n';
  }
  return 0;
}
