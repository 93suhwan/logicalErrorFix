#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const int INF = 1000000007;
int T, n;
int d[maxn], in[maxn], vis[maxn];
int h[maxn], cnt = 0;
struct Node {
  int to, next;
} e[maxn];
void add(int u, int v) {
  e[++cnt].to = v;
  e[cnt].next = h[u];
  h[u] = cnt;
}
queue<int> q;
vector<int> sor;
void topo() {
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = h[u]; i != -1; i = e[i].next) {
      int v = e[i].to;
      --in[v];
      if (!in[v]) {
        d[v] = 1;
        sor.push_back(v);
        q.push(v);
      }
    }
  }
}
void dfs(int u) {
  vis[u] = 1;
  for (int i = h[u]; i != -1; i = e[i].next) {
    int v = e[i].to;
    if (v > u) {
      d[v] = d[u];
      dfs(v);
    } else {
      d[v] = d[u] + 1;
    }
  }
}
long long read() {
  long long s = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * f;
}
int main() {
  T = read();
  while (T--) {
    cnt = 0;
    while (!q.empty()) q.pop();
    sor.clear();
    n = read();
    for (int i = 1; i <= n; ++i) h[i] = -1, d[i] = 0, in[i] = 0, vis[i] = 0;
    cnt = 0;
    int k, a;
    for (int j = 1; j <= n; ++j) {
      k = read();
      for (int i = 1; i <= k; ++i) {
        a = read();
        add(a, j);
        ++in[j];
      }
    }
    for (int i = 1; i <= n; ++i)
      if (!in[i]) {
        sor.push_back(i);
        d[i] = 1;
        q.push(i);
      }
    topo();
    if (sor.size() < n) {
      printf("-1\n");
      continue;
    }
    for (int i = 0; i < sor.size(); ++i) {
      if (!vis[sor[i]]) dfs(sor[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, d[i]);
    printf("%d\n", ans);
  }
  return 0;
}
