#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
long long f(int n) {
  long long q = 1;
  for (int i = 1; i <= n; i++) {
    q %= mod;
    q = (q * i) % mod;
    q % mod;
  }
  return q;
}
long long d(int n, int x) {
  long long s = 1;
  for (int i = 1; i <= n; i++) {
    if (i != x + 1) {
      s %= mod;
      s = (s * i) % mod;
      s %= mod;
    }
  }
  s = s * (x) % mod;
  s %= mod;
  return s;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long ans = 0, g = 0, j = 0;
    cin >> n;
    int a[n];
    long long mx = INT_MIN;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      mx = max(mx, x);
      a[i] = x;
    }
    for (int i = 0; i < n; i++) {
      if (a[i] == mx - 1) {
        g++;
      }
      if (a[i] == mx) {
        j++;
      }
    }
    if (j >= 2) {
      ans = f(n);
      ans %= mod;
    } else {
      if (g != 0) {
        ans = d(n, g);
      }
    }
    cout << ans << "\n";
  }
}
