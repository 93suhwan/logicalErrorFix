#include <bits/stdc++.h>
using namespace std;
void main0();
int main() {
  clock_t start, end;
  ios::sync_with_stdio(false);
  cin.tie(0);
  main0();
  return 0;
}
const int dx[8] = {0, 1, -1, 0, 1, 1, -1, -1};
const int dy[8] = {1, 0, 0, -1, 1, -1, -1, 1};
const int N = 2e5 + 5;
const int M = 1e5;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const double eps = 1e-6;
const double Pi = acos(-1.0);
mt19937 rnd(
    (unsigned int)chrono::steady_clock::now().time_since_epoch().count());
int n, q;
int fa[N], w[N];
int cyc[N];
int getfa(int u) {
  if (fa[u] != u) {
    int t = fa[u];
    fa[u] = getfa(fa[u]);
    w[u] ^= w[t];
  }
  return fa[u];
}
void merge(int u, int v, int curw) {
  int fu = getfa(u);
  int fv = getfa(v);
  fa[fu] = fv;
  w[fu] = w[u] ^ w[v] ^ curw;
}
vector<int> e[N];
int s[N], p = 0;
int in[N];
void dfs(int u, int fa) {
  if (in[u]) {
    cyc[u] = 1;
    int cur = p;
    while (s[cur] != u) {
      cyc[s[cur]] = 1;
      cur--;
    }
    return;
  }
  s[++p] = u;
  in[u] = 1;
  for (int v : e[u])
    if (v != fa) {
      dfs(v, u);
    }
  s[p--] = 0;
  in[u] = 0;
}
void main0() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
    w[i] = 0;
  }
  for (int i = 1; i <= q; ++i) {
    int u, v, curw, succ, dfsflag = 0;
    cin >> u >> v >> curw;
    if (getfa(u) != getfa(v)) {
      succ = 1;
      merge(u, v, curw);
    } else {
      if ((cyc[u] == 0) && (cyc[v] == 0)) {
        if (w[u] ^ w[v] ^ curw) {
          succ = 1;
          dfsflag = 1;
        } else {
          succ = 0;
        }
      } else {
        succ = 0;
      }
    }
    cout << ((succ) ? "Yes" : "No") << endl;
    if (succ) {
      e[u].push_back(v);
      e[v].push_back(u);
      if (dfsflag) dfs(u, -1);
    }
  }
}
