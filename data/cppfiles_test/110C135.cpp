#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n;
    set<int> adj[n + 1];
    set<pair<int, int>> s;
    int i, j, v;
    vector<int> vec[n + 1];
    for (i = 1; i <= n; i++) {
      cin >> k;
      for (j = 1; j <= k; j++) {
        cin >> v;
        vec[v].push_back(i);
        adj[i].insert(v);
      }
      s.insert(make_pair(k, i));
    }
    int ans = 0, pre;
    pair<int, int> p, p2;
    for (i = 1; i <= n; i++) {
      p = *s.begin();
      ans++;
      if (p.first > 0) break;
      while (!s.empty()) {
        if (s.lower_bound(p) == s.end()) break;
        p = *s.lower_bound(p);
        if (p.first > 0) break;
        for (auto x : vec[p.second]) {
          s.erase(make_pair(adj[x].size(), x));
          adj[x].erase(p.second);
          s.insert(make_pair(adj[x].size(), x));
        }
        s.erase(p);
      }
      if (s.empty()) break;
    }
    if (s.empty())
      cout << ans << "\n";
    else
      cout << "-1\n";
  }
  return 0;
}
