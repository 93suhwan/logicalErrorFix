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
int T, n;
int head[200050];
int nex[400050];
int ver[400050];
int tot;
int t1, t2;
int type[200050];
void init() {
  tot = 0;
  t1 = t2 = 0;
  memset(head, 0, sizeof(head));
  memset(type, 0, sizeof(type));
}
void add(int x, int y) {
  ++tot;
  nex[tot] = head[x];
  head[x] = tot;
  ver[tot] = y;
}
void dfs(int u, int fa) {
  type[u] = 1;
  for (int i = head[u]; i; i = nex[i]) {
    int v = ver[i];
    if (v == fa) continue;
    dfs(v, u);
    if (type[v] == 1) type[u] = 2;
  }
  if (type[u] == 1)
    t1++;
  else
    t2++;
}
int main() {
  T = read();
  while (T--) {
    n = read();
    init();
    for (int i = 1; i < n; ++i) {
      int x = read();
      int y = read();
      add(x, y);
      add(y, x);
    }
    dfs(1, 0);
    if (type[1] == 2)
      printf("%d\n", t1 - (t2 - 1));
    else
      printf("%d\n", t1 - (t2 - 1) - 1);
  }
  return 0;
}
