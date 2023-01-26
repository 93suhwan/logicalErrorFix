#include <bits/stdc++.h>
using namespace std;
long long maxm = -1e18;
long long minm = 1e18;
long long mod = 1e9 + 7;
long long mod1 = 1e9 + 9;
const long double Pi = 3.141592653;
long long int fact(long long int n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return 1;
  }
  long long int res = 1;
  for (long long int i = 2; i <= n; i++) res = res * i;
  return res;
}
long long int nCr(long long int n, long long int r) {
  return fact(n) / (fact(r) * fact(n - r));
}
bool isint(double n) {
  long long int j = n;
  double w = n - j;
  if (w > 0) {
    return false;
  }
  return true;
}
long long int count3(long long int x) {
  long long int ret = 0;
  while (x % 3 == 0) {
    ret++;
    x /= 3;
  }
  return ret;
}
long long int sqr(long long int a) { return a * a; }
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int ans = 1;
    if (n == 1) {
      cout << 1 << '\n';
      continue;
    }
    for (long long int i = 1; i <= 2 * n - 1; i++) {
      ans = (ans * i);
      ans = (ans) % mod;
    }
    ans = (ans * n) % mod;
    cout << ans << '\n';
  }
  return 0;
}
