#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long num = 1;
    long long ans = 0;
    while (num < n) {
      if (num >= k) {
        ans += (n - num) / k;
        if ((n - num) % k) ans++;
        break;
      }
      ans++;
      num += num;
    }
    cout << ans << endl;
  }
}
