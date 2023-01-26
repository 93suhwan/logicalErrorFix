#include <bits/stdc++.h>
using namespace std;
const int maxn = 2 * 1e5 + 10;
long long min(long long a, long long b) { return a > b ? b : a; }
long long fun(long long a, long long b) {
  long double A = a;
  long double B = b;
  long double c = A / B;
  if (c >= 0)
    return long long(c);
  else {
    if (c == long long(c))
      return long long(c);
    else
      return long long(c - 1);
  }
}
long long a[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum <= k) {
      cout << 0 << endl;
      continue;
    }
    sort(a, a + n);
    long long res = 0;
    long long ans = sum - k;
    for (int i = n - 1; i > 0; i--) {
      res += a[i];
      long long tmp = sum - res + 1ll * (n - i) * a[0];
      long long times = n - i;
      if (tmp > k) {
        double x = tmp - k;
        double y = n - i + 1;
        times += ceil(x / y);
      }
      ans = min(ans, times);
    }
    cout << ans << endl;
  }
}
