#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 10;
void solve() {
  int m;
  cin >> m;
  vector<vector<int>> mx(2, vector<int>(m));
  for (int j = 0; j < 2; ++j)
    for (int i = 0; i < m; ++i) cin >> mx[j][i];
  int ans = INF;
  int sum1 = 0, sum2 = 0;
  for (int i = 0; i < int(m); i++) sum1 += mx[0][i];
  for (int i = 0; i < int(m); i++) {
    sum1 -= mx[0][i];
    ans = min(ans, max(sum1, sum2));
    sum2 += mx[1][i];
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
