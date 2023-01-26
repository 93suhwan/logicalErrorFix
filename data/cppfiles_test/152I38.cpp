#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    long long x = -1e10, y = -1e9, flag = 1;
    for (long long i = 1; i <= n; i++) {
      if (-a[i] > y)
        y = -a[i], a[i] = -a[i];
      else if (-a[i] > x)
        x = -a[i], a[i] = -a[i];
      else if (a[i] > y)
        y = a[i];
      else if (a[i] > x)
        x = a[i];
      else
        flag = 0;
    }
    if (flag) {
      cout << "YES\n";
      for (long long i = 1; i <= n; i++) cout << a[i] << " ";
      cout << "\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
