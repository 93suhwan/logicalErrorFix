#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2.0;
const long long INF = 1e18L + 5;
long long int mod = 1e9 + 7;
void tc() {
  long long int n, k;
  cin >> n >> k;
  long long int p = 1;
  long long int ans = 0;
  for (long long int i = 0; i <= 31; i++) {
    if (k & 1) {
      ans = (ans % mod + p % mod) % mod;
    }
    p = ((p % mod) * (n % mod)) % mod;
    k /= 2;
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    tc();
  }
}
