#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, k = 0;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long sum = 1;
    if (a[0] == 1) sum++;
    for (long long i = 1; i < n; i++) {
      if (a[i] == 1) {
        if (a[i - 1] == 1)
          sum += 5;
        else
          sum++;
      } else if (a[i] == 0 && a[i - 1] == 0) {
        cout << -1 << endl;
        k = 1;
        break;
      } else
        continue;
    }
    if (k == 0) cout << sum << endl;
  }
}
