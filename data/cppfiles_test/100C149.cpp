#include <bits/stdc++.h>
using namespace std;
vector<long long int> fact(200005, 1);
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modInverse(long long int n, long long int p) {
  return power(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) %
          p) %
         p;
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  long long int m = INT_MIN;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    m = max(m, a[i]);
  }
  long long int mx = 0, d = 0;
  for (long long int i = 0; i < n; i++) {
    if (a[i] == m) {
      mx++;
    }
    if (abs(a[i] - m) > 1) {
      d++;
    }
  }
  if (mx > 1) {
    cout << fact[n];
    return;
  }
  if (d + mx == n) {
    cout << 0;
    return;
  }
  long long int ans = 0;
  for (long long int i = 0; i <= d; i++) {
    ans +=
        ((fact[n - 1 - i] % 998244353) *
         (fact[i] % 998244353 * nCrModPFermat(d, i, 998244353) % 998244353)) %
        998244353;
  }
  long long int x = (fact[n] % 998244353 - ans % 998244353) % 998244353;
  if (x < 0) x += 998244353;
  cout << x;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  for (long long int i = 1; i <= 200005; i++) {
    fact[i] = (fact[i - 1] % 998244353 * i) % 998244353;
  }
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
