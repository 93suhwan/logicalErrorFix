#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int ret = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9'; ch = getchar()) ret = ret * 10 + ch - '0';
  return ret * f;
}
const int INF = 1 << 30;
const int maxn = 200000 + 10;
const int maxm = 200000 + 10;
int first[maxn], nxt[maxm], ecnt;
int dis[maxn], d[maxn];
struct Edge {
  int u, v;
  Edge(int u = 0, int v = 0) : u(u), v(v) {}
} e[maxm];
void add_edge(int u, int v) {
  nxt[ecnt] = first[u];
  first[u] = ecnt;
  e[ecnt++] = Edge(u, v);
}
queue<int> q;
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    first[i] = -1;
    dis[i] = 0;
    d[i] = 0;
  }
  queue<int> q;
  ecnt = 0;
  int t, x;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t);
    while (t--) {
      scanf("%d", &x);
      add_edge(x, i);
      ++d[i];
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i)
    if (d[i] == 0) {
      q.push(i);
      ++cnt;
      dis[i] = 1;
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = first[u]; i != -1; i = nxt[i]) {
      int v = e[i].v;
      int extra = v > u ? 0 : 1;
      if (dis[v] < dis[u] + extra) {
        dis[v] = dis[u] + extra;
      }
      if (--d[v] == 0) {
        q.push(v);
        ++cnt;
      }
    }
  }
  if (cnt < n) {
    puts("-1");
    return;
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans = max(ans, dis[i]);
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
