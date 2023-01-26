#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5, inf = 0x3f3f3f3f;
long long b[maxn + 5] = {0};
long long ans[maxn + 5] = {0};
signed main() {
  long long t;
  cin >> t;
  long long n;
  while (t--) {
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; ++i) {
      cin >> b[i];
      sum += b[i];
    }
    long long m = 1ll * n * (n + 1) / 2;
    long long flag = 0;
    if (sum % m || sum / m < n) {
      flag = 1;
    }
    long long lone = (sum / m);
    for (long long i = 1; i <= n; ++i) {
      ans[i % n + 1] = (lone + b[i] - b[i % n + 1]) / n;
      if (ans[i % n + 1] < 1 || ans[i % n + 1] > 1000000000 ||
          (lone + b[i] - b[i % n + 1]) % n) {
        flag = 1;
      }
    }
    if (flag == 0) {
      cout << "YES" << endl;
      for (long long i = 1; i <= n; ++i) {
        printf("%lld%s", ans[i], i == n ? "\n" : " ");
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
