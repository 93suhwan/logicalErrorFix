#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-8;
const long long INF = 0x3f3f3f3f3f3f3f3f;
inline long long readll() {
  long long x(0), op(1);
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') op = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * op;
}
const int sz = 6e5 + 99;
int n, m;
vector<int> g1[sz];
vector<int> g2[sz];
bool vis[sz];
int occ[sz];
vector<pair<int, int> > qs;
void dfs1(int u, int fa) {
  for (auto t : g1[u]) {
    if (t == fa || vis[t]) continue;
    g2[u].push_back(t);
    g2[t].push_back(u);
    vis[t] = true;
    dfs1(t, u);
  }
}
vector<int> path;
void output_path() {
  printf("%d\n", int(path.size()));
  for (int i = 0; i < path.size(); ++i) {
    printf("%d%c", path[i], " \n"[i == path.size() - 1]);
  }
}
void dfs2(int u, int fa, int dest) {
  path.push_back(u);
  if (u == dest) {
    output_path();
  }
  for (auto t : g2[u]) {
    if (t == fa) continue;
    dfs2(t, u, dest);
  }
  path.pop_back();
}
void solve() {
  for (int i = 0; i < qs.size(); ++i) {
    int a = qs[i].first, b = qs[i].second;
    dfs2(a, 0, b);
    path.clear();
  }
}
void pre() {
  vis[1] = true;
  dfs1(1, 0);
}
int main() {
  n = readll(), m = readll();
  for (int i = 0; i < m; ++i) {
    int a = readll(), b = readll();
    g1[a].push_back(b);
    g1[b].push_back(a);
  }
  pre();
  int _ = readll();
  while (_--) {
    int a = readll();
    int b = readll();
    qs.push_back({a, b});
    occ[a]++, occ[b]++;
  }
  int ans = 0;
  for (int i = 0; i < n + 1; ++i) {
    if (occ[i] % 2) ans++;
  }
  if (ans == 0) {
    printf("YES\n");
    solve();
  } else {
    printf("NO\n%d\n", ans / 2);
  }
  return 0;
}
