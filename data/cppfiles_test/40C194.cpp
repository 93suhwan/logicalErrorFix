#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1E9 + 7;
const long long int MOD = 998244353;
const long long int N = 1E6 + 5;
void solve() {
  string s;
  long long int n;
  cin >> n;
  vector<vector<long long int>> v(2, vector<long long int>(n, 0));
  for (long long int i = 0; i < 2; i++) {
    for (long long int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }
  if (n == 1) {
    cout << 0 << endl;
    return;
  }
  vector<long long int> above(n, 0), below(n, 0);
  above[n - 1] = v[0][n - 1];
  below[0] = v[1][0];
  for (long long int i = 1; i < n; i++) {
    below[i] = v[1][i] + below[i - 1];
  }
  for (long long int i = n - 2; i >= 0; i--) {
    above[i] = v[0][i] + above[i + 1];
  }
  long long int ans = 0;
  for (long long int i = 1, j = 0; i < n, j < n - 1; i++, j++) {
    ans = max(ans, min(above[i], below[j]));
  }
  cout << ans << endl;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
