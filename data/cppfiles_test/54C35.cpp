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
int n, m;
int head[1000050];
int nex[1000050];
int ver[1000050];
int tot;
int dfn[1000050];
int low[1000050];
int cnt, sum;
int t[1000050], top;
bool vis[1000050];
int col[1000050];
vector<int> q[1000050];
int tim[1000050];
bool flag;
int fa[1000050];
int ans;
void init() {
  ans = 0;
  flag = false;
  for (int i = 1 * 2; i <= n * 2 + 1; ++i) tim[i] = 0;
  for (int i = 1 * 2; i <= n * 2 + 1; ++i) fa[i] = i;
  for (int i = 1 * 2; i <= n * 2 + 1; ++i) q[i].clear();
}
int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }
void add(int x, int y) {
  x = find(x);
  y = find(y);
  fa[y] = x;
}
int main() {
  T = read();
  while (T--) {
    n = read();
    m = read();
    init();
    for (int i = 1; i <= m; ++i) {
      int x = read();
      int y = read();
      char ch = getchar();
      int op;
      if (ch == 'i')
        op = 1;
      else
        op = 0;
      add(x * 2, y * 2 + op);
      add(x * 2 + 1, y * 2 + (1 ^ op));
    }
    for (int i = 1 * 2; i <= n * 2 + 1; ++i) q[find(i)].push_back(i);
    for (int i = 1 * 2; i <= n * 2 + 1; ++i)
      if (find(i) == i) {
        int a = 0;
        int b = 0;
        for (int k = 0; k < q[i].size(); ++k) {
          int u = q[i][k];
          tim[u] = i;
          if (tim[u ^ 1] == i) flag = true;
          if (u & 1)
            b++;
          else
            a++;
        }
        ans += max(a, b);
      }
    if (flag)
      puts("-1");
    else
      printf("%d\n", ans / 2);
  }
  return 0;
}
