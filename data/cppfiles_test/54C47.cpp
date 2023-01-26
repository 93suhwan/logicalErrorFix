#include <bits/stdc++.h>
using namespace std;
struct UF {
  vector<int> e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};
int n, m;
bool ok;
vector<int> seen;
void dfs(int v, vector<vector<int> >& adj, vector<int>& vis, int c) {
  seen.push_back(v);
  vis[v] = c;
  for (const int x : adj[v]) {
    if (!vis[x]) {
      dfs(x, adj, vis, 3 - c);
    } else if (vis[x] == c) {
      ok = 0;
    }
  }
}
void solve() {
  cin >> n >> m;
  UF uf(n);
  vector<pair<int, int> > ve;
  vector<vector<int> > adj(n);
  vector<int> vis(n), a(n);
  while (m--) {
    int i, j;
    string s;
    cin >> i >> j >> s;
    --i, --j;
    if (s == "crewmate") {
      uf.join(i, j);
    } else {
      ve.push_back({i, j});
    }
  }
  for (int i = 0; i < (n); ++i) {
    ++a[uf.find(i)];
  }
  for (const auto& p : ve) {
    int a = p.first, b = p.second;
    a = uf.find(a), b = uf.find(b);
    if (uf.sameSet(a, b)) {
      cout << "-1\n";
      return;
    }
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int ans = 0;
  ok = 1;
  for (int i = 0; i < (n); ++i) {
    int v = uf.find(i);
    if (v != i || vis[v]) {
      continue;
    }
    seen.clear();
    dfs(v, adj, vis, 1);
    if (!ok) {
      cout << "-1\n";
      return;
    }
    int cnt1 = 0, cnt2 = 0;
    for (const int x : seen) {
      if (vis[x] == 1) {
        cnt1 += a[x];
      } else {
        cnt2 += a[x];
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
