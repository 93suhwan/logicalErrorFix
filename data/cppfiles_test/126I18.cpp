#include <bits/stdc++.h>
using namespace std;
const int N = 1005, M = 1e4 + 5, inf = 1e9;
int n, m, s, t, a[N];
int to[M], nxt[M], ff[M], w[M], cur[N], hd[N], tot = 1;
void add(int u, int v, int f, int ww) {
  to[++tot] = v, ff[tot] = f, w[tot] = ww, nxt[tot] = hd[u], hd[u] = tot;
  to[++tot] = u, ff[tot] = 0, w[tot] = -ww, nxt[tot] = hd[v], hd[v] = tot;
}
int fl[N], l[N], le[N], sw[N];
bool inq[N];
int maxw;
int Spfa() {
  memset(fl, 0, sizeof(fl));
  memset(l, 0, sizeof(l));
  memset(le, 0, sizeof(le));
  memset(inq, 0, sizeof(inq));
  memset(sw, 0xcf, sizeof(sw));
  queue<int> q;
  fl[s] = inf, sw[s] = 0, inq[s] = true, q.push(s);
  while (!q.empty()) {
    int u = q.front();
    inq[u] = false, q.pop();
    for (int i = hd[u]; i; i = nxt[i]) {
      int v = to[i];
      if (!ff[i]) continue;
      if (sw[u] + w[i] > sw[v]) {
        sw[v] = sw[u] + w[i];
        fl[v] = min(fl[u], ff[i]);
        l[v] = u, le[v] = i;
        if (!inq[v]) inq[v] = true, q.push(v);
      }
    }
  }
  return fl[t];
}
void solve() {
  while (int flow = Spfa()) {
    if (sw[t] < 0) break;
    maxw += flow * sw[t];
    int k = t;
    while (k != s) {
      ff[le[k]] -= flow;
      ff[le[k] ^ 1] += flow;
      k = l[k];
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  s = n + 1, t = n + 2;
  for (int i = 1; i <= n; i++) add(s, i, 1, 0), add(i, t, 1, 0);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v, inf, a[u] - a[v]);
  }
  solve();
  printf("%d\n", maxw);
  for (int i = 1; i <= n; i++) {
    if (ff[4 * i - 2] == 0 && ff[4 * i] == 0) ff[4 * i - 2] = ff[4 * i] = 1;
  }
  Spfa();
  for (int i = 1; i <= n; i++) printf("%d ", a[i] + sw[i]);
  puts("");
  return 0;
}
