#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
using namespace std;
void solve() {
  int n, m;
  cin >> m >> n;
  vector<vector<int>> v;
  for (int i = 0; i < m; i += 1) {
    for (int j = 0; j < n; j += 1) {
      vector<int> vv(3);
      cin >> vv[0];
      vv[0] *= -1;
      vv[1] = i;
      vv[2] = j;
      v.push_back(vv);
    }
  }
  sort(v.begin(), v.end());
  vector<bool> shop(m, false), item(n, false);
  int cnt = 0, shopflag = 0;
  for (int i = 0; i < v.size(); i += 1) {
    if (shop[v[i][1]]) {
      shopflag = 1;
    }
    if (!item[v[i][2]]) {
      cnt += 1;
    }
    if (cnt == n && shopflag) {
      cout << -v[i][0] << "\n";
      return;
    }
    shop[v[i][1]] = true;
    item[v[i][2]] = true;
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
