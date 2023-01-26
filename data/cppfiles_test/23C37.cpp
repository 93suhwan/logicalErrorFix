#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char c;
  int f = 1;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  x = (c & 15);
  while (isdigit(c = getchar())) x = (x << 1) + (x << 3) + (c & 15);
  x *= f;
}
int n, m, i, j, a[4005], sz[4005];
int stk[4005], tp, lc[4005], rc[4005];
long long f[4005][4005], g[4005];
vector<int> bi[4005];
void dfs(int x, int fa) {
  memset(f[x], -0x3f, sizeof(f[x]));
  f[x][0] = 0;
  f[x][1] = 1ll * (m - 1) * a[x];
  sz[x] = 1;
  for (__typeof((bi[x]).begin()) it = (bi[x]).begin(); it != (bi[x]).end();
       ++it) {
    dfs(*it, x);
    memset(g, -0x3f, sizeof(g));
    int i, j;
    for ((i) = 0; (i) <= (sz[x]); (i)++)
      for ((j) = 0; (j) <= (sz[*it]); (j)++) {
        g[i + j] = max(g[i + j], f[x][i] + f[*it][j] - 2ll * i * j * a[x]);
      }
    memcpy(f[x], g, sizeof(f[x]));
    sz[x] += sz[*it];
  }
}
int main() {
  read(n);
  read(m);
  for ((i) = 1; (i) <= (n); (i)++) read(a[i]);
  for ((i) = 1; (i) <= (n); (i)++) {
    int lst = 0;
    while (tp && a[stk[tp]] >= a[i]) {
      lst = stk[tp--];
    }
    lc[i] = lst;
    if (tp) rc[stk[tp]] = i;
    stk[++tp] = i;
  }
  int rt = stk[1];
  for ((i) = 1; (i) <= (n); (i)++) {
    if (lc[i]) bi[i].push_back(lc[i]);
    if (rc[i]) bi[i].push_back(rc[i]);
  }
  dfs(rt, 0);
  cout << f[rt][m] << endl;
  return 0;
}
