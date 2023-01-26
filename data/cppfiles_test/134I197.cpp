#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd(b % a, a);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    if (n == 2) {
      if (a[0] == a[1]) cout << 0 << '\n';
      cout << max(a[0], a[1]) << '\n';
      continue;
    }
    long long d = a[0];
    for (long long i = 0; i < n; i += 2) {
      d = gcd(d, a[i]);
    }
    bool flag = true;
    if (d > 1) {
      for (long long i = 1; i < n; i += 2) {
        if (a[i] % d == 0) {
          flag = false;
          break;
        }
      }
    }
    if (d <= 1 || !flag) {
      d = a[1];
      for (long long i = 1; i < n; i += 2) {
        d = gcd(d, a[i]);
      }
      if (d > 1) {
        for (long long i = 0; i < n; i += 2) {
          if (a[i] % d == 0) {
            cout << 0 << '\n';
            flag = false;
            break;
          }
        }
      } else {
        cout << 0 << '\n';
        flag = false;
      }
    }
    if (flag) cout << d << '\n';
  }
  return 0;
}
