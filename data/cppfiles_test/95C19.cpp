#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 100;
int t, n, m, rk[N], ans[N], pre[N];
vector<int> tmp[N], a[N];
struct node {
  int MAX, MIN, id;
};
bool operator<(node a, node b) { return a.MAX > b.MAX; }
vector<node> f[N];
inline void ckmin(int &a, int b) { a = ((a < b) ? a : b); }
inline void ckmax(int &a, int b) { a = ((a > b) ? a : b); }
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
signed main() {
  t = read();
  while (t--) {
    n = read();
    m = read();
    for (int i = 0; i < n; i++) tmp[i].resize(m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) tmp[i][j] = read();
    for (int i = 0; i < m; i++) a[i].resize(n), f[i].resize(n);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) a[j][i] = tmp[i][j];
    swap(n, m);
    f[n].resize(m);
    for (int i = 0; i < m; i++) f[n][i] = (node){-0x3f3f3f3f, 0x3f3f3f3f, i};
    for (int i = n - 1; i >= 0; i--) {
      f[i] = f[i + 1];
      for (int j = 0; j < m; j++) {
        int id = f[i][j].id;
        ckmax(f[i][j].MAX, a[i][id]);
        ckmin(f[i][j].MIN, a[i][id]);
      }
      sort(f[i].begin(), f[i].end());
    }
    vector<node> g;
    g.resize(m);
    for (int i = 0; i < m; i++) g[i] = (node){-0x3f3f3f3f, 0x3f3f3f3f, i};
    bool bl = 1;
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        int id = g[j].id;
        ckmax(g[j].MAX, a[i][id]);
        ckmin(g[j].MIN, a[i][id]);
      }
      sort(g.begin(), g.end());
      for (int j = 0; j < m; j++) rk[f[i + 1][j].id] = j;
      pre[0] = f[i + 1][0].MIN;
      for (int j = 1; j < m; j++) pre[j] = min(pre[j - 1], f[i + 1][j].MIN);
      int MIN = 0x3f3f3f3f, pos = 0x3f3f3f3f;
      for (int j = 0; j < m - 1; j++) {
        ckmin(MIN, g[j].MIN);
        ckmin(pos, rk[g[j].id]);
        if (MIN > g[j + 1].MAX && m - 1 - pos == j &&
            f[i + 1][pos].MAX < pre[pos - 1]) {
          printf("YES\n");
          for (int k = 0; k <= j; k++) ans[g[k].id] = 1;
          for (int k = j + 1; k < m; k++) ans[g[k].id] = 0;
          for (int k = 0; k < m; k++) {
            if (ans[k])
              printf("R");
            else
              printf("B");
          }
          printf(" %d\n", i + 1);
          bl = 0;
          break;
        }
      }
      if (!bl) break;
    }
    if (bl) printf("NO\n");
  }
}
