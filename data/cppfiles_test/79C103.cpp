#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  queue<pair<int, int>> q;
  vector<int> dist0(n + 1, -1), dist1(n + 1, -1);
  dist0[n] = 0;
  set<int> unvis;
  for (int i = 0; i < n; i++) {
    unvis.insert(i);
  }
  q.push({n, 0});
  vector<vector<int>> preds(n + 1, vector<int>(2, -1));
  while (q.size()) {
    auto cur = q.front();
    q.pop();
    int x = cur.first, y = cur.second;
    if (y) {
      if (preds[x + b[x]][0] == -1) {
        preds[x + b[x]][0] = x;
        q.push({x + b[x], 0});
        dist0[x + b[x]] = dist1[x];
      }
    } else {
      auto it = unvis.lower_bound(x - a[x]);
      while (it != unvis.end() && *it <= x) {
        auto it2 = it;
        it2++;
        q.push({*it, 1});
        dist1[*it] = dist0[x] + 1;
        preds[*it][1] = x;
        unvis.erase(it);
        it = it2;
      }
    }
  }
  cout << dist1[0] << '\n';
  if (dist1[0] != -1) {
    vector<int> ans;
    int cur = 0;
    int bo = 0;
    while (cur < n) {
      if (bo) ans.push_back(cur);
      cur = preds[cur][bo];
      bo = !bo;
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) cout << i << ' ';
  }
  return 0;
}
