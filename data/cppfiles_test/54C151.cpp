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
const int N = 2e5 + 5;
int n, m, vis[N], a[N];
vector<int> adj[N];
bool ok;
void dfs(int v, int c, int& cnt1, int& cnt2) {
  vis[v] = c;
  if (c == 1) {
    cnt1 += a[v];
  } else {
    cnt2 += a[v];
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
  for (int i = 0; i < (n); ++i) {
    adj[i].clear();
    vis[i] = a[i] = 0;
  }
  UF uf(n);
  vector<pair<int, int> > e;
  while (m--) {
    int a, b;
    string s;
    cin >> a >> b >> s;
    --a, --b;
    if (s == "crewmate") {
      uf.join(a, b);
    } else {
      e.push_back({a, b});
    }
  }
  for (int i = 0; i < (n); ++i) {
    ++a[uf.find(i)];
  }
  for (const auto& p : e) {
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
    if (uf.find(i) == i && !vis[i]) {
      int cnt1 = 0, cnt2 = 0;
      dfs(i, 1, cnt1, cnt2);
      ans += max(cnt1, cnt2);
    }
  }
  cout << (ok ? ans : -1) << '\n';
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
