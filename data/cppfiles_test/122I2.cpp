#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, m;
int stp, comps, top;
int dfn[N], low[N], comp[N], stk[N];
vector<int> E[N];
void add(int x, int a, int y, int b) { E[x << 1 | a].push_back(y << 1 | b); }
void tarjan(int x) {
  dfn[x] = low[x] = ++stp;
  stk[top++] = x;
  for (int y : E[x]) {
    if (!dfn[y]) {
      tarjan(y), low[x] = min(low[x], low[y]);
    } else if (!comp[y]) {
      low[x] = min(low[x], dfn[y]);
    }
  }
  if (low[x] == dfn[x]) {
    comps++;
    do {
      int y = stk[--top];
      comp[y] = comps;
    } while (stk[top] != x);
  }
}
int ans[N];
bool solve() {
  int cnt = n + n + 1;
  stp = top = comps = 0;
  fill(dfn, dfn + cnt, 0);
  fill(comp, comp + cnt, 0);
  for (int i = 0; i < cnt; i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 0; i < n; i++) {
    if (comp[i << 1] == comp[i << 1 | 1]) return false;
    ans[i] = (comp[i << 1 | 1] < comp[i << 1]);
  }
  return true;
}
struct edge {
  int v, val;
};
vector<edge> e[N];
int X[N], Y[N], V[N];
int s[N];
void dfs(int x, int fa) {
  for (auto y : e[x]) {
    if (y.v == fa) continue;
    if (y.val != -1) {
      s[y.v] = s[x] ^ y.val;
      if (y.val & 1)
        add(x, 1, y.v, 0), add(x, 0, y.v, 1), add(y.v, 1, x, 0),
            add(y.v, 0, x, 1);
      else
        add(x, 1, y.v, 1), add(x, 0, y.v, 0), add(y.v, 1, x, 1),
            add(y.v, 0, x, 0);
    } else
      s[y.v] = s[x];
    dfs(y.v, x);
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1, x, y, v; i < n; i++) {
      cin >> x >> y >> v;
      X[i] = x, Y[i] = y, V[i] = v;
      e[x].push_back({y, v}), e[y].push_back({x, v});
    }
    s[1] = 0, dfs(1, 1);
    for (int i = 1, a, b, p; i <= m; i++) {
      cin >> a >> b >> p;
      int sa = s[a] ^ (s[a] & 1);
      int sb = s[b] ^ (s[b] & 1);
      int val = sa ^ sb;
      int pc = __builtin_popcount(val) & 1;
      int q = p ^ pc;
      if (q)
        add(a, 1, b, 0), add(a, 0, b, 1), add(b, 0, a, 1), add(b, 1, a, 0);
      else
        add(a, 0, b, 0), add(a, 1, b, 1), add(b, 1, a, 1), add(b, 0, a, 0);
    }
    if (solve()) {
      cout << "YES" << endl;
      for (int i = 1; i < n; i++) {
        if (V[i] != -1)
          cout << X[i] << ' ' << Y[i] << ' ' << V[i] << endl;
        else
          cout << X[i] << ' ' << Y[i] << ' ' << (ans[X[i]] ^ ans[Y[i]]) << endl;
      }
    } else
      cout << "NO" << endl;
    for (int i = 1; i <= n * 2 + 1; i++) e[i].clear(), E[i].clear();
  }
}
