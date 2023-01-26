#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, vis[N];
vector<int> adj[N];
bool ok;
void dfs(int v, int c, int& cnt1, int& cnt2) {
  vis[v] = c;
  if (v != n) {
    if (c == 1) {
      ++cnt1;
    } else {
      ++cnt2;
    }
  }
  for (const int x : adj[v]) {
    if (!vis[x]) {
      dfs(x, 3 - c, cnt1, cnt2);
    } else if (vis[x] == c) {
      ok = 0;
    }
  }
}
void solve() {
  cin >> n >> m;
  for (int i = 0; i < (n + 1); ++i) {
    adj[i].clear();
    vis[i] = 0;
  }
  while (m--) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    --a, --b;
    if (s == "imposter") {
      adj[a].push_back(b);
      adj[b].push_back(a);
    } else {
      adj[a].push_back(n);
      adj[n].push_back(a);
      adj[b].push_back(n);
      adj[n].push_back(b);
    }
  }
  ok = 1;
  int ans = 0;
  for (int i = 0; i < (n + 1); ++i) {
    int cnt1 = 0, cnt2 = 0;
    if (!vis[i]) {
      dfs(i, 1, cnt1, cnt2);
      if (!ok) {
        cout << "-1\n";
        return;
      }
    }
    ans += max(cnt1, cnt2);
  }
  cout << ans << '\n';
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
