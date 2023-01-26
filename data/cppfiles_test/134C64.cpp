#include <bits/stdc++.h>
using namespace std;
long long gcd_fun(long long a, long long b) {
  if (a > b) swap(a, b);
  if (a == 0) return b;
  return gcd_fun(b % a, a);
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 2) {
      if (a[0] == a[1])
        cout << 0 << '\n';
      else
        cout << max(a[0], a[1]) << '\n';
      continue;
    }
    long long n1 = a[0], n2 = a[1];
    long long num;
    for (long long i = 0; i < n; i += 2) {
      n1 = gcd_fun(n1, a[i]);
    }
    for (long long i = 1; i < n; i += 2) {
      n2 = gcd_fun(n2, a[i]);
    }
    for (long long i = 0; i < n; i += 2) {
      if (a[i] % n2 == 0) {
        n2 = 0;
        break;
      }
    }
    for (long long i = 1; i < n; i += 2) {
      if (a[i] % n1 == 0) {
        n1 = 0;
        break;
      }
    }
    if (n1 == 0 && n2 == 0) {
      cout << 0 << '\n';
    } else if (n1 > 0) {
      cout << n1 << '\n';
    } else {
      cout << n2 << '\n';
    }
  }
  return 0;
}
