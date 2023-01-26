#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1.0);
int read() {
  int a = 0;
  int d = 1;
  char c;
  while (c = getchar(), c < '0' || c > '9')
    if (c == '-') d = -1;
  a = a * 10 + c - 48;
  while (c = getchar(), c >= '0' && c <= '9') a = a * 10 + c - 48;
  a *= d;
  return a;
}
int n, m;
int ffa[N];
int cnt[N];
int lg[N] = {-1};
int fa[N][30];
int dep[N];
vector<vector<int> > edge(N);
vector<pair<int, int> > ask;
void init() {
  for (int i = 1; i <= n; i++) {
    ffa[i] = i;
    lg[i] = lg[i >> 1] + 1;
  }
}
int findset(int x) {
  if (x == ffa[x])
    return x;
  else
    return ffa[x] = findset(ffa[x]);
}
void unionset(int x, int y) { ffa[findset(x)] = findset(y); }
void dfs(int u, int from) {
  fa[u][0] = from;
  dep[u] = dep[from] + 1;
  for (int i = 1; i <= lg[dep[u]]; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
  for (int i = 0; i < edge[u].size(); i++) {
    int v = edge[u][i];
    if (v != from) dfs(v, u);
  }
}
int lca(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  while (dep[x] > dep[y]) x = fa[x][lg[dep[x] - dep[y]]];
  if (x == y) return x;
  for (int i = lg[dep[x] - 1]; i >= 0; i--)
    if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
  return fa[x][0];
}
signed main() {
  n = read();
  m = read();
  init();
  for (int i = 1; i <= m; i++) {
    int x = read();
    int y = read();
    if (findset(x) == findset(y)) continue;
    edge[x].push_back(y);
    edge[y].push_back(x);
    unionset(x, y);
  }
  int q = read();
  while (q--) {
    int x = read();
    int y = read();
    cnt[x]++;
    cnt[y]++;
    ask.push_back(make_pair(x, y));
  }
  int tot = 0;
  for (int i = 1; i <= n; i++)
    if (cnt[i] & 1) tot++;
  if (tot) {
    puts("NO");
    printf("%d\n", tot >> 1);
  } else {
    puts("YES");
    dfs(1, 0);
    for (int i = 0; i < ask.size(); i++) {
      int x = ask[i].first;
      int y = ask[i].second;
      int lc = lca(x, y);
      printf("%d\n", dep[x] + dep[y] - dep[lc] * 2 + 1);
      int now = x;
      while (now != lc) {
        printf("%d ", now);
        now = fa[now][0];
      }
      printf("%d ", lc);
      stack<int> st;
      now = y;
      while (now != lc) {
        st.push(now);
        now = fa[now][0];
      }
      while (!st.empty()) {
        printf("%d ", st.top());
        st.pop();
      }
      printf("\n");
    }
  }
  return 0;
}
