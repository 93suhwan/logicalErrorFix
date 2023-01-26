#include <bits/stdc++.h>
using namespace std;
const long long int inf = 10e+7;
const long long int mode = 998244353;
void solve() {
  long long int n, k;
  cin >> n >> k;
  long long int p = 1;
  long long int ans = 0;
  for (long long int i = 0; i < 31; i++) {
    if (k & (1 << i)) {
      ans = (ans + p) % inf;
    }
    p *= n;
    p %= inf;
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
