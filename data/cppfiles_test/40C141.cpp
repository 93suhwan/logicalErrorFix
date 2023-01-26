#include <bits/stdc++.h>
using namespace std;
long long int M = 1000000007;
void solve() {
  int m;
  cin >> m;
  vector<vector<int>> a(2, (vector<int>(m)));
  for (int i = 0; i <= 1; i++)
    for (int j = 0; j <= m - 1; j++) cin >> a[i][j];
  int sum1 = 0;
  for (int i = 0; i <= m - 1; i++) sum1 += a[0][i];
  int sum2 = 0;
  int ans = INT_MAX;
  for (int i = 0; i <= m - 1; i++) {
    sum1 -= a[0][i];
    ans = min(ans, max(sum1, sum2));
    sum2 += a[1][i];
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
