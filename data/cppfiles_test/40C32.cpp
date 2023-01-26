#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 3e5 + 10;
const double eps = 1e-5;
vector<int> np[N];
bool vis[N];
vector<int> tr[N];
void build(int p, int fa) {
  vis[p] = 1;
  for (int nt : np[p]) {
    if (vis[nt]) continue;
    build(nt, p);
    tr[p].push_back(nt);
    tr[nt].push_back(p);
  }
}
vector<int> path;
bool dfs(int p, int fa, int tar) {
  path.push_back(p);
  if (p == tar) return true;
  for (int nt : tr[p]) {
    if (nt == fa) continue;
    if (dfs(nt, p, tar)) return true;
  }
  path.pop_back();
  return false;
}
void printpath(int a, int b) {
  path.clear();
  dfs(a, 0, b);
  cout << path.size() << '\n';
  for (int p : path) cout << p << " ";
  cout << '\n';
}
vector<pair<int, int> > que;
int deg[N];
int main() {
  std::ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    np[u].push_back(v);
    np[v].push_back(u);
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; i++) {
    int u, v;
    cin >> u >> v;
    que.push_back({u, v});
    deg[u]++;
    deg[v]++;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] % 2) cnt++;
  }
  if (cnt) {
    cout << "NO" << '\n';
    cout << cnt / 2 << '\n';
  } else {
    build(1, 0);
    cout << "YES" << '\n';
    for (int i = 0; i < q; i++) {
      int u = que[i].first, v = que[i].second;
      printpath(u, v);
    }
  }
}
