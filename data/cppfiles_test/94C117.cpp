#include <bits/stdc++.h>
using namespace std;
long long n, k;
signed main() {
  cin.tie(0);
  cout.tie(0);
  long long _;
  cin >> _;
  while (_--) {
    cin >> n >> k;
    k += 1;
    long long a[n + 2];
    for (long long i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    bool flag = false;
    for (long long i = 1; i < n; i++) {
      if (k < pow(10, a[i + 1] - a[i])) {
        ans += k * pow(10, a[i]);
        cout << ans << "\n";
        flag = true;
        break;
      }
      ans += pow(10, a[i + 1]) - pow(10, a[i]);
      k -= pow(10, a[i + 1] - a[i]) - 1;
    }
    if (flag) {
      continue;
    } else {
      cout << ans + (long long)pow(10, a[n]) * k << "\n";
    }
  }
}
