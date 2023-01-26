#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long tt;
  cin >> tt;
  while (tt--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long c = 0, nc = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] % 2 == 0)
        c++;
      else
        nc++;
    }
    if ((n % 2 == 0 && (c - nc) != 0) || (n % 2 == 1 && abs(c - nc) != 1)) {
      cout << "-1\n";
      continue;
    }
    if (n == 1) {
      cout << "0\n";
      continue;
    }
    if (n % 2 == 0) {
      long long poz = 0, ans = 0;
      if (a[0] % 2 == 0) poz = 1;
      for (long long i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
          ans += abs(poz - i);
          poz += 2;
        }
      }
      long long poz1 = n - 1, ans1 = 0;
      if (a[poz1] % 2 == 0) poz1 = n - 2;
      for (long long i = n - 1; i >= 0; i--) {
        if (a[i] % 2 == 1) {
          ans1 += abs(i - poz1);
          poz1 -= 2;
        }
      }
      ans = min(ans, ans1);
      cout << ans << '\n';
    } else {
      long long poz = 0, ans = 0;
      if (nc < c) poz = 1;
      for (long long i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
          ans += abs(i - poz);
          poz += 2;
        }
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
