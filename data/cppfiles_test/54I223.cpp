#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, m, vis[N], cnt[2];
vector<int> adj[N];
bool ok;
void dfs(int v, int c) {
  vis[v] = c;
  ++cnt[c - 1];
  for (const int x : adj[v]) {
    if (!vis[x]) {
      dfs(x, 3 - c);
    } else if (vis[x] == c) {
      ok = 0;
    }
  }
}
void solve() {
  cin >> n >> m;
  cnt[0] = cnt[1] = 0;
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
  for (int i = 0; i < (n); ++i) {
    if (!vis[i]) {
      dfs(i, 1);
    }
    if (!ok) {
      cout << "-1\n";
      return;
    }
  }
  cout << *max_element(begin(cnt), end(cnt)) << '\n';
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
