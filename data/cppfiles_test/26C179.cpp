#include <bits/stdc++.h>
using namespace std;
const int N = 2e7;
const long long inf = 1e18;
const long long mod = 1e9 + 7;
long long mypower(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long ret = mypower(x, y / 2);
  ret = (ret * ret) % mod;
  if (y % 2) ret = (ret * x);
  return ret;
}
long long t, n, fac[200009];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fac[0] = 1;
  for (int i = 1; i <= 2e5; i++) {
    fac[i] = ((fac[i - 1] % mod) * (i % mod)) % mod;
  }
  cin >> t;
  while (t--) {
    cin >> n;
    long long ans = (fac[n * 2] * mypower(2, mod - 2)) % mod;
    cout << ans << "\n";
  }
  return 0;
}
