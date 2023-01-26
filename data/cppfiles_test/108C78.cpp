#include <bits/stdc++.h>
using namespace std;
int read() {
  int a = 0;
  int f = 0;
  char p = getchar();
  while (!isdigit(p)) {
    f |= p == '-';
    p = getchar();
  }
  while (isdigit(p)) {
    a = (a << 3) + (a << 1) + (p ^ 48);
    p = getchar();
  }
  return f ? -a : a;
}
const int INF = 998244353;
int T;
int n;
int val[100050];
int pos[100050];
bool vis[1000050];
bool cmp(int a, int b) { return val[a] < val[b]; }
int head[100050];
int nex[1000050];
int ver[1000050];
int tot;
int sx, sy;
void add(int x, int y) {
  ++tot;
  nex[tot] = head[x];
  head[x] = tot;
  ver[tot] = y;
}
void solve() {
  queue<int> q;
  q.push(sx);
  q.push(sy);
  vis[sx] = vis[sy] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = nex[i]) {
      int v = ver[i];
      if (vis[v]) continue;
      vis[v] = true;
      q.push(v);
    }
  }
}
int main() {
  T = read();
  while (T--) {
    n = read();
    tot = 0;
    for (int i = 1; i <= n; ++i) head[i] = vis[i] = 0;
    for (int i = 1; i <= n; ++i) val[i] = read();
    for (int i = 1; i <= n; ++i) pos[i] = i;
    sort(pos + 1, pos + n + 1, cmp);
    sx = pos[n];
    for (int i = 1; i < n; ++i) add(pos[i], pos[i + 1]);
    for (int i = 1; i <= n; ++i) val[i] = read();
    for (int i = 1; i <= n; ++i) pos[i] = i;
    sort(pos + 1, pos + n + 1, cmp);
    sy = pos[n];
    for (int i = 1; i < n; ++i) add(pos[i], pos[i + 1]);
    solve();
    for (int i = 1; i <= n; ++i) printf("%d", vis[i]);
    puts("");
  }
  return 0;
}
