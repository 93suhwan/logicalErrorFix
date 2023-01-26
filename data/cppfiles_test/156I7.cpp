#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3, "Ofast", "inline")
long long a[200005], f[200005];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      ans += a[i];
      f[i] = a[i] + f[i - 1];
    }
    int jis = 0;
    long long qs = a[0];
    sort(a, a + n);
    if (ans <= k) {
      cout << jis << endl;
    } else {
      for (int i = n;;) {
        long long h = (f[n] - f[i]) - (n - i) * qs + (a[0] - qs);
        if (ans - h <= k) {
          break;
        }
        if (i - 1 >= 1) {
          jis++;
          long long z = (f[n] - f[i - 1]) - (n - i + 1) * qs + (a[0] - qs);
          long long y = (f[n] - f[i]) - (n - i) * (qs - 1) + (a[0] - (qs - 1));
          if (z > y) {
            i--;
          } else {
            qs--;
          }
        } else {
          jis++;
          qs--;
        }
      }
      cout << jis << endl;
    }
  }
  return 0;
}
