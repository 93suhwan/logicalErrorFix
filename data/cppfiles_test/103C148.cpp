#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 5;
int t, n, m, cnt, p[maxn], fa[maxn], in[maxn], vis[maxn], vis2[maxn], ansx,
    ansy, anss;
struct node {
  int v, next;
} e[maxn];
void insert(int u, int v) {
  fa[v] = u;
  in[u]++;
  cnt++;
  e[cnt].v = v;
  e[cnt].next = p[u];
  p[u] = cnt;
}
void topo() {
  queue<int> q;
  for (int i = 0; i < n * m; i++) {
    if (in[i] == 0) q.push(i);
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    if (fa[u] == n * m) continue;
    in[fa[u]]--;
    if (in[fa[u]] == 0) q.push(fa[u]);
  }
}
int getsiz(int u) {
  if (vis[u]) return 0;
  vis[u] = 1;
  for (int i = p[u]; i != -1; i = e[i].next) {
    int v = e[i].v;
    if (in[v] == 0) continue;
    return getsiz(v) + 1;
  }
}
void dfs(int u, int val) {
  val++;
  if (val > anss) {
    anss = val;
    ansx = u / m + 1;
    ansy = u % m + 1;
  }
  for (int i = p[u]; i != -1; i = e[i].next) {
    int v = e[i].v;
    if (in[v]) continue;
    dfs(v, val);
  }
}
void work(int u, int val) {
  vis2[u] = 1;
  if (val > anss) {
    anss = val;
    ansx = u / m + 1;
    ansy = u % m + 1;
  }
  for (int i = p[u]; i != -1; i = e[i].next) {
    int v = e[i].v;
    if (in[v] && !vis2[v]) work(v, val);
    if (!in[v]) dfs(v, val);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    string s;
    cnt = 0;
    anss = ansx = ansy = 0;
    cin >> n >> m;
    for (int i = 0; i <= n * m; i++)
      fa[i] = in[i] = vis[i] = vis2[i] = 0, p[i] = -1;
    for (int i = 0; i < n; i++) {
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == 'R') {
          if (j == m - 1)
            insert(n * m, i * m + j);
          else
            insert(i * m + j + 1, i * m + j);
        }
        if (s[j] == 'L') {
          if (j == 0)
            insert(n * m, i * m + j);
          else
            insert(i * m + j - 1, i * m + j);
        }
        if (s[j] == 'U') {
          if (i == 0)
            insert(n * m, i * m + j);
          else
            insert((i - 1) * m + j, i * m + j);
        }
        if (s[j] == 'D') {
          if (i == n - 1)
            insert(n * m, i * m + j);
          else
            insert((i + 1) * m + j, i * m + j);
        }
      }
    }
    topo();
    for (int i = 0; i < n * m; i++) {
      if (vis[i] == 0 && in[i] > 0) {
        int sz = getsiz(i);
        work(i, sz);
      }
    }
    work(n * m, 0);
    cout << ansx << " " << ansy << " " << anss << endl;
  }
  return 0;
}
