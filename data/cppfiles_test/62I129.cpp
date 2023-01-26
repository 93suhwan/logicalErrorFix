#include <bits/stdc++.h>
using namespace std;
int vis[10005];
vector<int> a[10005];
void dfs(int s) {
  vis[s] = 1;
  cout << s << " ";
  for (int i = 1; i < a[s].size(); ++i) {
    if (!vis[a[s][i]]) dfs(a[s][i]);
  }
}
void solve() {
  int n, x;
  cin >> n;
  for (int i = 1; i < n + 2; i++) a[i].clear(), vis[i] = 0;
  for (int i = 1; i < n + 1; i++) a[i].push_back(i + 1);
  for (int i = 1; i < n + 1; ++i) {
    cin >> x;
    if (x)
      a[n + 1].push_back(i);
    else
      a[i].push_back(n + 1);
  }
  for (int i = 1; i < n + 2; ++i)
    if (!vis[i]) dfs(i);
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
    cout << endl;
  }
  return 0;
}
