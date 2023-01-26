#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, x, y, k, i, j, ans = 0, c = 0, sum = 0;
  string s;
  cin >> n >> k;
  vector<long long int> v(n + 1);
  std::vector<long long int> vv(n + 1);
  for (i = 1; i <= n; i++) {
    cin >> v[i];
    vv[i] = v[i];
  }
  ans = LLONG_MIN;
  for (i = max(1ll, n - 4 * k); i <= n; i++) {
    for (j = i + 1; j <= n; j++) {
      long long int more = k * (v[i] | v[j]);
      long long int idx = i * j;
      ans = max(ans, idx - more);
    }
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
