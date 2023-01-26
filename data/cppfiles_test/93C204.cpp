#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    long long cur = 1, now = 1, ans = 0;
    while (now <= k && cur < n) {
      cur += now;
      now <<= 1;
      ans++;
    }
    if (cur < n) {
      ans += (n - cur + k - 1) / k;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
