#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[200005];
int res[200005];
bool ok = 1;
int cnt = 0;
void dfs(int n) {
  for (auto i : adj[n]) {
    if (res[n] == 0) continue;
    int val = res[n] * i.second;
    if (res[i.first] == 0) {
      res[i.first] = val;
      if (val == -1) {
        cnt++;
      }
      dfs(i.first);
    } else {
      if (res[i.first] != val) {
        ok = 0;
        return;
      }
    }
  }
}
void clear(int n) {
  for (auto i : adj[n]) {
    if (res[i.first] == 0) continue;
    res[i.first] = 0;
    clear(i.first);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int z = 1; z <= t; z++) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
      int u, v, c;
      cin >> u >> v;
      string s;
      cin >> s;
      if (s == "imposter")
        c = -1;
      else
        c = 1;
      adj[u].push_back({v, c});
    }
    for (int i = 1; i <= n; i++) {
      res[i] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (res[i] == 0) {
        cnt = 0;
        ok = 1;
        res[i] = 1;
        dfs(i);
        clear(i);
        int cnt1 = cnt;
        if (!ok) cnt1 = -1;
        cnt = 1;
        ok = 1;
        res[i] = -1;
        dfs(i);
        clear(i);
        int cnt2 = cnt;
        if (!ok) cnt2 = -1;
        if (max(cnt1, cnt2) == -1) {
          ans = -1;
          break;
        } else {
          ans += max(cnt1, cnt2);
          if (cnt1 > cnt2) {
            res[i] = 1;
            dfs(i);
          } else {
            res[i] = -1;
            dfs(i);
          }
        }
      }
    }
    cout << ans << "\n";
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      res[i] = 0;
    }
  }
  return 0;
}
