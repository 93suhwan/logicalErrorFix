#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
bool comp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}
int main() {
  fast();
  int t, m, n, i, j, res1, res2, mn, mx, ans;
  string s;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    mx = 1000000007;
    vector<vector<int>> v(m, vector<int>(n));
    vector<vector<pair<int, int>>> vv(n);
    set<int> st;
    for (i = 0; i < m; i++) {
      for (j = 0; j < n; j++) cin >> v[i][j];
    }
    ans = 0;
    for (i = 0; i < m; i++) {
      vector<int> vvv = v[i];
      sort(vvv.begin(), vvv.end(), greater<int>());
      ans = max(ans, vvv[1]);
    }
    for (i = 0; i < n; i++) {
      mx = 0;
      for (j = 0; j < m; j++) {
        mx = max(mx, v[j][i]);
      }
      ans = min(mx, ans);
    }
    cout << ans << '\n';
  }
}
