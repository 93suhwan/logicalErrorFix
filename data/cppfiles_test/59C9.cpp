#include <bits/stdc++.h>
using namespace std;
const int N = 4007, inf = 1e9 + 5;
int n, m, a[N], b[N], lst[N];
vector<int> adj[N];
long long dis[N];
bool rns[N];
bool SPFA(long long &w) {
  queue<int> q;
  for (int i = (1); i <= (n); ++i)
    if (rns[i])
      q.push(i), dis[i] = w, lst[i] = -1;
    else
      dis[i] = -1, lst[i] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u])
      if (a[v] < dis[u] && !(rns[u] && rns[v]) && lst[u] != v) {
        if (dis[v] == -1)
          dis[v] = dis[u] + b[v], lst[v] = u, q.push(v);
        else {
          for (int x = u; !rns[x]; x = lst[x]) w += b[x], rns[x] = true;
          for (int x = v; !rns[x]; x = lst[x]) w += b[x], rns[x] = true;
          return true;
        }
      }
  }
  return false;
}
bool check(long long x) {
  for (int i = (1); i <= (n); ++i) rns[i] = i == 1;
  while (SPFA(x))
    ;
  for (int i = (1); i <= (n); ++i)
    if (!rns[i]) return false;
  return true;
}
void Main() {
  cin >> n >> m;
  for (int i = (2); i <= (n); ++i) cin >> a[i];
  for (int i = (2); i <= (n); ++i) cin >> b[i];
  for (int i = (1); i <= (m); ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v), adj[v].push_back(u);
  }
  int l = 0, r = 1e9 + 3, ns = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ns = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ns << "\n";
  for (int i = (1); i <= (n); ++i) adj[i].clear();
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) Main();
  return 0;
}
