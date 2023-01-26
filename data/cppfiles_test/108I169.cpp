#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[2 * (int)(1e5 + 51)], b[2 * (int)(1e5 + 51)];
bool visited[2 * (int)(1e5 + 51)];
vector<int> g[2 * (int)(1e5 + 51)];
void dfs(int x) {
  visited[x] = 1;
  for (auto v : g[x]) {
    if (!visited[v]) dfs(v);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      a[i] = {x, i};
    }
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      b[i] = {x, i};
    }
    sort(a + 1, a + 1 + n);
    reverse(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    reverse(b + 1, b + 1 + n);
    for (int i = 1; i < n; i++) g[a[i + 1].second].push_back({a[i].second});
    for (int i = 1; i < n; i++)
      if ((int)g[b[i + 1].second].size() &&
          g[b[i + 1].second][0] != b[i].second)
        g[b[i + 1].second].push_back({b[i].second});
    dfs(b[1].second);
    dfs(a[1].second);
    string ans = "";
    for (int i = 1; i <= n; i++) {
      if (visited[i])
        ans += '1';
      else
        ans += '0';
    }
    cout << ans << '\n';
  }
}
