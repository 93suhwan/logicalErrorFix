#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
const double PI = 3.14159265359;
using namespace std;
const long long N = 2e5 + 10;
long long a[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    if (k == 1) {
      sort(a + 1, a + 1 + n);
      for (long long i = 1; i < n; i++) {
        ans += abs(a[i]) * 2;
      }
      ans += a[n];
    } else {
      sort(a + 1, a + 1 + n);
      long long temp = 0;
      long long val = 0;
      long long judge = 0;
      long long sum1 = 0, sum2 = 0;
      long long flag = lower_bound(a + 1, a + 1 + n, 0) - a;
      for (long long i = 1; i < flag; i++) {
        if (temp == 0) val = a[i];
        temp++;
        if (temp == k || i == flag - 1) {
          if (judge == 0) {
            ans += abs(val) * 2;
            sum1 = abs(val);
            judge = 1;
          } else
            ans += abs(val) * 2;
          temp = 0;
        }
      }
      temp = 0;
      val = 0;
      judge = 0;
      for (long long i = n; i >= flag; i--) {
        if (temp == 0) val = a[i];
        temp++;
        if (temp == k || i == flag) {
          if (judge == 0) {
            sum2 = abs(val);
            judge = 1;
            ans += abs(val) * 2;
          } else
            ans += abs(val) * 2;
          temp = 0;
        }
      }
      ans -= max(sum1, sum2);
    }
    cout << ans << "\n";
  }
}
