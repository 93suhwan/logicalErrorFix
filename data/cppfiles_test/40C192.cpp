#include <bits/stdc++.h>
using namespace std;
void solve() {
  int m;
  cin >> m;
  vector<vector<long long>> v(2, vector<long long>(m, 0));
  long long tot = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < m; j++) {
      cin >> v[i][j];
      tot += v[i][j];
    }
  }
  vector<long long> l(m, 0), r(m, 0), r0(m, 0), l1(m, 0);
  l[0] = v[0][0];
  r[m - 1] = v[1][m - 1];
  r0[m - 1] = v[0][m - 1];
  l1[0] = v[1][0];
  for (int i = 1; i < m; i++) {
    l[i] = l[i - 1] + v[0][i];
    l1[i] = l1[i - 1] + v[1][i];
  }
  for (int i = m - 2; i >= 0; i--) {
    r[i] = r[i + 1] + v[1][i];
    r0[i] = r0[i + 1] + v[0][i];
  }
  long long ans = INT_MAX;
  for (int i = 0; i < m; i++) {
    long long res = (i == m - 1 ? 0 : r0[i + 1]);
    long long res2 = (i == 0) ? 0 : l1[i - 1];
    res = max(res, res2);
    ans = min(ans, res);
  }
  cout << ans << '\n';
}
int main() {
  std ::ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
