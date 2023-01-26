#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n], sum = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    long long x = n * (n + 1) / 2;
    if (sum % x != 0) {
      cout << "NO" << endl;
      continue;
    }
    sum = sum / x;
    long long ans[n], flag = 0;
    for (long long i = 0; i < n; i++) {
      if (i == 0) {
        ans[i] = sum - a[i] + a[n - 1];
      } else
        ans[i] = sum - a[i] + a[i - 1];
      ans[i] /= n;
      if (ans[i] <= 0) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (long long i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
