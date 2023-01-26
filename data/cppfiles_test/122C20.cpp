#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m;
vector<pair<int, int> > g[N];
bool vis[N];
int dsu[N], val[N];
int A[N], B[N], C[N], sz = 0;
int Find(int u) {
  if (u == dsu[u]) return u;
  Find(dsu[u]);
  val[u] ^= val[dsu[u]];
  return dsu[u] = dsu[dsu[u]];
}
void DFS(int node, int prnt) {
  int x, y;
  for (int i = 0; i < (int)g[node].size(); i++) {
    if (g[node][i].first == prnt) continue;
    A[sz] = node;
    B[sz] = g[node][i].first;
    if (g[node][i].second == -1) {
      x = Find(node);
      y = Find(g[node][i].first);
      if (x == y) {
        C[sz] = val[node] ^ val[g[node][i].first];
      } else {
        dsu[x] = y;
        val[x] = val[node] ^ val[g[node][i].first];
        C[sz] = 0;
      }
    } else
      C[sz] = g[node][i].second;
    sz++;
    DFS(g[node][i].first, node);
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  sz = 0;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    dsu[i] = i;
    val[i] = 0;
  }
  bool bad = false;
  for (int a, b, x, y, v, p, i = 0; i < n - 1; i++) {
    scanf("%d%d%d", &x, &y, &v);
    g[x].push_back(make_pair(y, v));
    g[y].push_back(make_pair(x, v));
    if (v == -1) continue;
    p = 0;
    while (v > 0) {
      p++;
      v ^= (v & (-v));
    }
    p &= 1;
    a = Find(x);
    b = Find(y);
    if (a == b) {
      if (val[x] ^ val[y] != p) {
        bad = true;
      }
    } else {
      dsu[a] = b;
      val[a] = p ^ val[x] ^ val[y];
    }
  }
  for (int x, y, a, b, p, i = 0; i < m; i++) {
    scanf("%d%d%d", &x, &y, &p);
    a = Find(x);
    b = Find(y);
    if (a == b) {
      if (val[x] ^ val[y] != p) {
        bad = true;
      }
    } else {
      dsu[a] = b;
      val[a] = p ^ val[x] ^ val[y];
    }
  }
  if (bad) {
    puts("NO");
    return;
  }
  puts("YES");
  DFS(1, -1);
  assert(sz == n - 1);
  for (int i = 0; i < sz; i++) {
    printf("%d %d %d\n", A[i], B[i], C[i]);
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
