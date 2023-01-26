#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i;
  cin >> n;
  vector<long long> v(n);
  for (i = (0); i < (n); i++) cin >> v[i];
  long long ans = 0;
  vector<long long> open(n + 1, 0);
  vector<long long> closed(n + 1, 0);
  for (i = (0); i < (n); i++) {
    if (v[i] == 0) {
      ans = (ans + 1) % 998244353LL;
      ans = (ans + open[0]) % 998244353LL;
      open[0] = ((open[0] + 1) % 998244353LL + open[0]) % 998244353LL;
    } else if (v[i] == 1) {
      ans = (ans + closed[1]) % 998244353LL;
      ans = (ans + 1) % 998244353LL;
      ans = (ans + open[1]) % 998244353LL;
      ans = (ans + open[0]) % 998244353LL;
      open[1] = ((2 * open[1]) % 998244353LL + open[0]) % 998244353LL;
      closed[1] = ((2 * closed[1]) % 998244353LL + 1) % 998244353LL;
    } else {
      ans = (ans + closed[v[i]]) % 998244353LL;
      ans = (ans + open[v[i]]) % 998244353LL;
      ans = (ans + open[v[i] - 1]) % 998244353LL;
      ans = (ans + open[v[i] - 2]) % 998244353LL;
      open[v[i]] = ((open[v[i]] + open[v[i] - 1]) % 998244353LL + open[v[i]]) %
                   998244353LL;
      closed[v[i]] =
          ((2 * closed[v[i]]) % 998244353LL + open[v[i] - 2]) % 998244353LL;
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
