#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int modp = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const double pi = acos(-1.0);
const double e = 2.718281828459045;
vector<int> mp[N];
bool vis[N], flag;
vector<int> res;
int n;
int dfs(int x) {
  if (res.size() == n + 1) {
    flag = 1;
    return 0;
  }
  for (auto &v : mp[x]) {
    if (!vis[v]) {
      vis[v] = 1;
      res.push_back(v);
      dfs(v);
      if (flag) return 0;
      vis[v] = 0;
      res.pop_back();
    }
  }
  return 0;
}
int solve() {
  cin >> n;
  int a;
  for (int i = 1; i <= n; i++) {
    mp[i].clear();
    if (i != n) {
      mp[i].push_back(i + 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a)
      mp[n + 1].push_back(i);
    else
      mp[i].push_back(n + 1);
  }
  for (auto &v : mp[n + 1]) {
    if (v == 1) {
      cout << n + 1 << ' ';
      for (int i = 1; i <= n; i++) cout << i << ' ';
      return 0;
    }
  }
  memset(vis, 0, sizeof(vis));
  res.clear();
  res.push_back(1);
  flag = 0;
  dfs(1);
  if (flag) {
    for (auto &v : res) cout << v << ' ';
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
