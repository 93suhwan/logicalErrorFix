#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, a, b, c;
  cin >> n >> m;
  string s;
  cin >> s;
  vector<string> av = {"abc", "acb", "bac", "bca", "cab", "cba"};
  vector<vector<long long int>> ans;
  for (long long int i = 0; i < 6; i++) {
    vector<long long int> v(1, 0);
    ans.push_back(v);
  }
  for (long long int j = 0; j < n; j++) {
    for (long long int i = 0; i < 6; i++) {
      long long int x = ans[i][j];
      if (s[j] != av[i][j % 3]) x++;
      ans[i].push_back(x);
    }
  }
  for (long long int __ = 0; __ < m; __++) {
    cin >> a >> b;
    c = b - a + 1;
    for (long long int i = 0; i < 6; i++) {
      c = min(c, ans[i][b] - ans[i][a - 1]);
    }
    cout << c << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
