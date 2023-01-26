#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n, t, c, d, e;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int a[n + 2];
    for (i = 1; i <= n; i++) cin >> a[i];
    int k = 0, s = 0, t = 0, c = 0;
    while (1) {
      s = 0, t = 0;
      for (i = 1; i <= n - 2; i += 2) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
          s = 1;
        }
      }
      if (s) c++;
      for (i = 2; i <= n - 1; i += 2) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
          t = 1;
        }
      }
      if (t) c++;
      if (s == 0 && t == 0) break;
    }
    cout << c << endl;
  }
}
