#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 10;
long long a[N];
long long st[N];
signed main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  st[1] = 1;
  for (long long i = 2; i <= 300; i++) {
    for (long long j = 2; j < i; j++) {
      if (i % j == 0) {
        st[i] = 1;
        break;
      }
    }
  }
  while (t--) {
    memset(a, 0, sizeof a);
    long long n;
    cin >> n;
    char c;
    for (long long i = 1; i <= n; i++) {
      cin >> c;
      a[i] = c - '0';
    }
    long long ok = 0;
    for (long long i = 1; i <= n; i++) {
      if (st[a[i]] == 1) {
        cout << 1 << "\n";
        cout << a[i] << "\n";
        ok = 1;
        break;
      }
    }
    if (ok == 0) {
      for (long long i = 1; i <= n; i++) {
        if (ok == 1) break;
        for (long long j = i + 1; j <= n; j++) {
          if (st[a[i] * 10 + a[j]] == 1) {
            cout << 2 << "\n";
            cout << a[i] * 10 + a[j] << "\n";
            ok = 1;
            break;
          }
        }
      }
    }
    if (ok == 0) {
      for (long long i = 1; i <= n; i++) {
        if (ok == 1) break;
        for (long long j = i + 1; j <= n; j++) {
          if (ok == 1) break;
          for (long long k = j + 1; k <= n; k++) {
            if (st[a[i] * 100 + a[j] * 10 + a[k]] == 1) {
              cout << 3 << "\n";
              cout << a[i] * 100 + a[j] * 10 + a[k] << "\n";
              ok = 1;
              break;
            }
          }
        }
      }
    }
  }
  return 0;
}
