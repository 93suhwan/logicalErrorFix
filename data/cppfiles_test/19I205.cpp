#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 10;
int T, n, a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = (0); i <= (n - 1); ++i) cin >> a[i];
    sort(a, a + n);
    bool ok = 0;
    for (int i = (0); i <= (n - 1); ++i) {
      if (a[i] == 0 || (i > 0 && a[i] == a[i - 1])) ok = 1;
    }
    for (int i = (0); i <= (n - 1); ++i) {
      for (int j = (0); j <= (n - 1); ++j)
        if (a[j] == -a[i]) {
          ok = 1;
          break;
        }
      for (int x = (0); x <= ((1 << n) - 1); ++x)
        if (!(x >> i & 1)) {
          for (int mask = x; mask; mask = (mask - 1) & x) {
            int sum = 0;
            for (int j = (0); j <= (n - 1); ++j)
              if (x >> j & 1) {
                if (mask >> j & 1)
                  sum += a[j];
                else
                  sum -= a[j];
              }
            if (sum == a[i]) {
              ok = 1;
              break;
            }
          }
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
