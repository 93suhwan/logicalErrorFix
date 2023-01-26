#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
long long powm(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * 1ll * a % 1000000007;
    a = a * 1ll * a % 1000000007;
    b >>= 1;
  }
  return res;
}
long long mul(long long x, long long y) { return (x * 1ll * y) % 1000000007; }
void solve() {
  long long i = 0, j = 0, k = 0, n = 0, m = 0;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n, greater<long long>());
  long long sum = 0;
  for (long long i = 2 * k; i < n; i++) sum += a[i];
  for (long long i = 0; i < k; i++) sum += (a[i + k] / a[i]);
  {
    cout << sum << "\n";
    return;
  };
}
signed main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout << setprecision(15);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
