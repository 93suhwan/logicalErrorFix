#include <bits/stdc++.h>
using namespace std;
void solve() {
  int64_t q;
  cin >> q;
  int64_t t, x, y;
  vector<vector<int64_t> > ans(q);
  for (int64_t i = 0; i < q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> x;
      ans[i].push_back(x);
    } else {
      cin >> x >> y;
      ans[i].push_back(x);
      ans[i].push_back(y);
    }
  }
  ans.shrink_to_fit();
  map<int64_t, int64_t> m;
  stack<int64_t> s;
  for (int64_t i = q - 1; i >= 0; i--) {
    if (ans[i].size() == 2) {
      if (ans[i][0] != ans[i][1]) {
        if (m.count(ans[i][1])) {
          m[ans[i][0]] = m[ans[i][1]];
        } else {
          m[ans[i][0]] = ans[i][1];
        }
      }
    } else {
      int64_t p = ans[i][0];
      if (m.count(p)) {
        p = m[p];
      }
      s.push(p);
    }
  }
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t test = 1;
  while (test--) {
    solve();
  }
  return 0;
}
