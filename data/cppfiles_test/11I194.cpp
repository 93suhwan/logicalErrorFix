#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> lines(n);
    vector<vector<int>> cou(n, vector<int>(5, 0));
    vector<int> sz(n), r(n);
    for (int i = 0; i < n; i++) {
      cin >> lines[i];
      for (char c : lines[i]) ++cou[i][c - 'a'];
      sz[i] = lines[i].size();
      r[i] = i;
    }
    int mx = 0, cur;
    long long sum, dom;
    for (int k = 0; k < 5; k++) {
      sort(r.begin(), r.end(), [&](int a, int b) {
        if (a < 0 || a >= n || b < 0 || b >= n) {
          cout << "shit happens" << '\n';
          return false;
        }
        return sz[a] <= sz[b];
      });
      cur = 0;
      sum = 0, dom = 0;
      vector<int> used(n);
      for (int i = 0; i < n; i++) {
        if (dom + cou[r[i]][k] >= (sum + sz[r[i]]) / 2 + 1) {
          sum += sz[r[i]];
          dom += cou[r[i]][k];
          ++cur;
          used[r[i]] = 1;
        }
      }
      for (int i = 0; i < n; i++) {
        if (used[r[i]]) continue;
        if (dom + cou[r[i]][k] >= (sum + sz[r[i]]) / 2 + 1) {
          sum += sz[r[i]];
          dom += cou[r[i]][k];
          ++cur;
        }
      }
      mx = max(mx, cur);
    }
    cout << mx << '\n';
  }
  return 0;
}
