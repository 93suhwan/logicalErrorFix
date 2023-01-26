#include <bits/stdc++.h>
using namespace std;
void dfs(int v, vector<int> &edge, vector<bool> &used, int sdvig, int n) {
  used[v] = 1;
  if (!used[(edge[v] + sdvig) % n])
    dfs((edge[v] + sdvig) % n, edge, used, sdvig, n);
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n), pos(n);
  vector<int> edge(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    edge[i] = p[i];
    cnt[(i - p[i] + n) % n]++;
  }
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int left = (n - cnt[i]);
    if (n - (cnt[i] + left / 2) <= m) {
      vector<bool> used(n);
      int ans = n;
      for (int j = 0; j < n; j++) {
        if (!used[j]) dfs(j, edge, used, i, n), ans--;
      }
      if (ans <= m) a.push_back(i);
    }
  }
  cout << a.size() << ' ';
  for (auto i : a) cout << i << ' ';
  cout << endl;
}
signed main() {
  int t;
  cin >> t;
  while (t--) solve();
}
