#include <bits/stdc++.h>
using namespace std;
const int maxn = 11;
int t, n, k, a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  a[0] = -1;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int s = 0, d = 0, x;
    for (x = 1; x <= n; x++) {
      d = pow(10, a[x] - a[x - 1]) - 1;
      s += d;
      if (k < s) {
        if (k < d)
          cout << k + 1 << endl;
        else {
          cout << k - d + 1;
          for (int j = 1; j <= a[x]; j++) cout << 9;
          cout << endl;
        }
        break;
      }
    }
    if (x > n) {
      cout << k - s + 10;
      for (int i = 1; i <= a[n]; i++) cout << 9;
      cout << endl;
    }
  }
  return 0;
}
