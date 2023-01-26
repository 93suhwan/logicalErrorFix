#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int q;
  cin >> q;
  vector<pair<int, int>> queries;
  map<pair<int, int>, int> qs;
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b) swap(a, b);
    queries.push_back({a, b});
    qs[{a, b}] = i;
  }
  auto find_path = [&](int u, int v) {
    queue<int> qu;
    vector<bool> vis(n, 0);
    vector<int> p(n, 0);
    qu.push(u);
    vis[u] = 1;
    while (!qu.empty()) {
      int x = qu.front();
      qu.pop();
      for (int y : g[x]) {
        if (!vis[y]) {
          vis[y] = 1;
          qu.push(y);
          p[y] = x;
        }
      }
    }
    vector<int> ans;
    for (int x = v; x != u; x = p[x]) {
      ans.push_back(x);
    }
    ans.push_back(u);
    reverse(ans.begin(), ans.end());
    return ans;
  };
  vector<bool> matched(q, 0);
  vector<tuple<int, int, int>> matches;
  vector<vector<int>> ans(q);
  for (int i = 0; i < q; i++) {
    if (matched[i]) continue;
    auto [a, b] = queries[i];
    for (int c = 0; c < n; c++) {
      if (c == a || c == b) continue;
      pair<int, int> p1 = {min(a, c), max(a, c)};
      pair<int, int> p2 = {min(b, c), max(a, c)};
      if (p1 == p2) continue;
      if (qs.find(p1) != qs.end() && qs.find(p2) != qs.end()) {
        matched[i] = 1;
        matched[qs[p1]] = 1;
        matched[qs[p2]] = 1;
        ans[i] = find_path(a, b);
        ans[qs[p1]] = find_path(a, c);
        ans[qs[p2]] = find_path(b, c);
        break;
      }
    }
  }
  int cnt_match = 0;
  for (int i = 0; i < q; i++) cnt_match += matched[i];
  1313;
  if (cnt_match == q) {
    cout << "YES\n";
    for (auto v : ans) {
      cout << v.size() << '\n';
      for (auto x : v) cout << x + 1 << ' ';
      cout << '\n';
    }
  } else {
    cout << "NO\n";
    int unmatched = q - cnt_match;
    int asd = unmatched / 2;
    if (unmatched % 2 != 0) asd += 2;
    cout << asd << '\n';
  }
  return 0;
}
