#include <bits/stdc++.h>
using namespace std;
long long int sub(long long int x, long long int y) {
  long long int z = (x - y) % 1000000007;
  if (z < 0) z += 1000000007;
  return z;
}
long long int add(long long int x, long long int y) {
  return (x + y) % 1000000007;
}
long long int mul(long long int x, long long int y) {
  return (x * y) % 1000000007;
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x %= 1000000007;
  while (y) {
    if (y & 1) res = mul(res, x);
    y >>= 1;
    x = mul(x, x);
  }
  return res;
}
long long int mod_inv(long long int x) { return power(x, 1000000007 - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n], b[n];
    for (long long int index = 0; index < n; index++) cin >> a[index];
    ;
    for (long long int index = 0; index < n; index++) cin >> b[index];
    ;
    long long int i = 0;
    long long int sum = 0;
    for (i = 1; i < n; i++) sum += a[i];
    if (n == 1) {
      cout << 0 << endl;
      continue;
    }
    if (n == 2) {
      cout << min(b[0], a[1]) << endl;
      continue;
    }
    long long int ans = sum;
    long long int x = 0;
    for (i = 1; i < n; i++) {
      sum -= a[i];
      x += b[i - 1];
      ans = min(ans, max(x, sum));
    }
    cout << ans << endl;
  }
  return 0;
}
