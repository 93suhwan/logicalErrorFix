#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long fun(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t, n, x, y, i, j, k, ans, res, c, temp, l, r, d, index, ans1;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    ans = 0;
    c = 0;
    while (k > 0) {
      d = (k % 2);
      if (d == 1) ans = (ans + fun(n, c)) % mod;
      k /= 2;
      c++;
    }
    cout << ans << "\n";
  }
}
