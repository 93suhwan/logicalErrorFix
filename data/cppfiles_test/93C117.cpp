#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const long long inf = 0x3f3f3f3f3f3f3f3fLL;
const long long N = 2e5 + 10;
const long long MOD = 1e9 + 7;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t, n, k;
  cin >> t;
  vector<long long> p2(61);
  p2[0] = 1;
  for (long long i = 1; i <= 60; i++) p2[i] = 2 * p2[i - 1];
  while (t--) {
    cin >> n >> k;
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    long long ans = 0;
    for (long long i = 1; i <= 60; i++) {
      if (p2[i] > k || p2[i] > n - p2[i]) {
        long long x = n - p2[i];
        ans = i + (x + k - 1) / k;
        break;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
