#include <bits/stdc++.h>
using namespace std;
bool debug = false;
vector<vector<pair<long long, long long>>> g;
vector<long long> used;
long long cnt1, cnt2;
bool dfs(long long u, long long c) {
  used[u] = c;
  if (c == 1) {
    ++cnt1;
  } else {
    ++cnt2;
  }
  for (auto qwe : g[u]) {
    long long v = qwe.first;
    long long w = qwe.second;
    if (used[v] == 0) {
      if (dfs(v, c * w)) {
        return true;
      }
    } else if (used[v] != w * c) {
      return true;
    }
  }
  return false;
}
inline void solve() {
  long long n, m;
  cin >> n >> m;
  g.resize(n);
  used.resize(n);
  for (int i = 0; i < m; ++i) {
    long long u, v;
    string s;
    cin >> u >> v >> s;
    g[u - 1].push_back({v - 1, ((s == "imposter") ? -1 : 1)});
    g[v - 1].push_back({u - 1, ((s == "imposter") ? -1 : 1)});
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (used[i] == 0) {
      cnt1 = 0;
      cnt2 = 0;
      if (dfs(i, 1)) {
        cout << "-1\n";
        return;
      }
      ans += max(cnt1, cnt2);
    }
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    solve();
    g.clear();
    used.clear();
  }
}
