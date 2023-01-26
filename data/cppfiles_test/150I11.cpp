#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n + 1];
    for (long long i = 1; i <= n; i++) {
      cin >> a[i];
    }
    bool two = 0;
    bool one = 0;
    bool onepr = 0;
    long long req[n + 1];
    for (long long i = 1; i <= n; i++) {
      if (a[i] % 3 == 1) {
        one = 1;
        req[i] = a[i] / 3 + 1;
      }
      if (a[i] % 3 == 2) {
        two = 1;
        req[i] = a[i] / 3 + 1;
      }
      if (a[i] % 3 == 0) {
        req[i] = a[i] / 3;
      }
      if (a[i] == 1) {
        onepr = 1;
      }
    }
    long long ans = a[1];
    long long ind = 0;
    for (long long i = 1; i <= n; i++) {
      if (a[i] >= ans) {
        ans = a[i];
        ind = i;
      }
    }
    if (!two && !one) {
      cout << ans / 3 << endl;
      continue;
    }
    if (!onepr) {
      if (!one) {
        ans = 0;
        for (long long i = 1; i <= n; i++) {
          if (a[i] % 3 == 2) {
            a[i] -= 2;
            req[i] = a[i] / 3;
          }
          if (req[i] > ans) {
            ans = req[i];
          }
        }
        ans++;
        cout << ans << endl;
        continue;
      }
      if (!two) {
        ans = 0;
        for (long long i = 1; i <= n; i++) {
          if (a[i] % 3 == 1) {
            a[i] -= 1;
            req[i] = a[i] / 3;
          }
          if (req[i] > ans) {
            ans = req[i];
          }
        }
        ans++;
        cout << ans << endl;
        continue;
      }
      ans = 0;
      if (a[ind] % 3 == 1) {
        for (long long i = 1; i <= n; i++) {
          if (a[i] % 3 == 2) {
            a[i] -= 2;
          }
          if (a[i] % 3 == 1) {
            a[i] -= 4;
          }
          req[i] = a[i] / 3;
          if (req[i] > ans) {
            ans = req[i];
          }
        }
        ans += 2;
        cout << ans << endl;
        continue;
      }
      if (a[ind] % 3 == 0) {
        ans = 0;
        for (long long i = 1; i <= n; i++) {
          if (a[i] % 3 == 0) {
            a[i] -= 3;
          }
          if (a[i] % 3 == 2) {
            a[i] -= 2;
          }
          if (a[i] % 3 == 1) {
            a[i] -= 1;
          }
          req[i] = a[i] / 3;
          if (req[i] > ans) {
            ans = req[i];
          }
        }
        ans += 2;
        cout << ans << endl;
      }
    }
    if (onepr) {
      if (!two) {
        ans = 0;
        for (long long i = 1; i <= n; i++) {
          if (a[i] % 3 == 1) {
            a[i] -= 1;
            req[i] = a[i] / 3;
          }
          if (req[i] > ans) {
            ans = req[i];
          }
        }
        ans++;
        cout << ans << endl;
        continue;
      }
      ans = 0;
      for (long long i = 1; i <= n; i++) {
        if (a[i] % 3 == 0) {
          a[i] -= 3;
        }
        if (a[i] % 3 == 2) {
          a[i] -= 2;
        }
        if (a[i] % 3 == 1) {
          a[i] -= 1;
        }
        req[i] = a[i] / 3;
        if (req[i] > ans) {
          ans = req[i];
        }
      }
      ans += 2;
      cout << ans << endl;
    }
  }
  return 0;
}
