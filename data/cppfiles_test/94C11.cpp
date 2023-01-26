#include <bits/stdc++.h>
using namespace std;
const int maxn = 11;
int t, n, k, a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int s = 0, d = 0, x;
    for (x = 2; x <= n; x++) {
      d = pow(10, a[x] - a[x - 1]) - 1;
      s += d;
      if (k < s) {
        s -= d;
        cout << k - s + 1;
        for (int j = 1; j <= a[x - 1]; j++) cout << 9;
        cout << endl;
        break;
      }
    }
    if (x > n) {
      cout << k - s + 1;
      for (int i = 1; i <= a[n]; i++) cout << 9;
      cout << endl;
    }
  }
  return 0;
}
