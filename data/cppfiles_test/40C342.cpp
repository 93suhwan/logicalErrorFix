#include <bits/stdc++.h>
using namespace std;
void solve() {
  int m;
  cin >> m;
  vector<vector<int>> vec(2, vector<int>(m, 0));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < m; j++) {
      cin >> vec[i][j];
    }
  }
  if (m == 1) {
    cout << 0 << endl;
    return;
  }
  vector<int> pre1(m);
  long long int sum1 = 0;
  for (int i = 0; i < m; i++) {
    sum1 += vec[0][i];
    pre1[i] = sum1;
  }
  long long int sum2 = 0;
  vector<int> pre2(m);
  for (int i = 0; i < m; i++) {
    sum2 += vec[1][i];
    pre2[i] = sum2;
  }
  int ans = INT_MAX;
  int alice = 0;
  for (int i = 0; i < m; i++) {
    int r1 = sum1 - pre1[i];
    int r2;
    if (i == 0) {
      r2 = 0;
    } else {
      r2 = pre2[i - 1];
    }
    ans = min(ans, max(r1, r2));
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
