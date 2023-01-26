#include <bits/stdc++.h>
using namespace std;
const int ms = 200005;
#pragma GCC optimize(3, "Ofast", "inline")
long long a[ms], f[ms];
long long z, y, n, k, jis, qs, h, ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    ans = 0;
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      ans += a[i];
    }
    int jis = 0;
    sort(a + 1, a + n + 1);
    qs = a[1];
    for (int i = 1; i <= n; i++) {
      f[i] = a[i] + f[i - 1];
    }
    if (ans <= k) {
      cout << jis << endl;
    } else {
      h = 0;
      for (int i = n; ans - h > k;) {
        h = (f[n] - f[i]) - (n - i) * qs + (a[1] - qs);
        if (ans - h <= k) {
          break;
        }
        if (i - 1 >= 1) {
          jis++;
          z = (f[n] - f[i - 1] + a[1]) - (n - (i - 1) + 1) * qs;
          y = (f[n] - f[i] + a[1]) - (n - i + 1) * (qs - 1);
          if (z > y) {
            i--;
          } else {
            qs--;
          }
        } else {
          long long qss = (ans - k) / n;
          jis += qss - (a[1] - qs);
          if (ans - (n * qss) <= k) {
            break;
          } else {
            jis++;
            break;
          }
        }
      }
      cout << jis << endl;
    }
  }
  return 0;
}
