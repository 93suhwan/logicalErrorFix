#include <bits/stdc++.h>
using namespace std;
long long inf = 1000000000000000000;
void solve() {
  long long n, m;
  cin >> n >> m;
  if (n > m) {
    cout << 0 << "\n";
    return;
  }
  long long ans = 0;
  for (int k = 0; pow(2, k) <= m; k++) {
    if ((m & (1 << k)) && !(n & (1 << k))) {
      ans += pow(2, k);
    }
  }
  if ((ans ^ n) == m) {
    ans++;
  }
  while (1) {
    long long rmsb = ans & (-ans);
    long long after_rem = ans - rmsb;
    if ((n ^ after_rem) > m) {
      ans -= rmsb;
    } else {
      break;
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
