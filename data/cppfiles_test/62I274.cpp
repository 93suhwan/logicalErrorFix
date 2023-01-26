#include <bits/stdc++.h>
using namespace std;
map<long long, long long> vis;
vector<long long> ans;
map<long long, vector<long long>> g;
void dfs(long long u) {
  vis[u]++;
  ans.push_back(u);
  for (auto x : g[u]) {
    if (vis[x] == 0) {
      dfs(x);
    }
  }
}
void solve() {
  long long n;
  cin >> n;
  g.clear();
  vector<long long> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    g[i].push_back(i + 1);
  }
  for (auto x : arr) {
    if (x == 0) {
      g[x + 1].push_back(n + 1);
    } else {
      g[n + 1].push_back(x + 1);
    }
  }
  long long start = 1;
  for (int i = 1; i <= n + 1; i++) {
    if (g[i].size() == 0) {
      start = i;
      break;
    }
  }
  ans.clear();
  vis.clear();
  dfs(start);
  if (ans.size() == 0) {
    cout << -1 << '\n';
  } else {
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
