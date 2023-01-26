#include <bits/stdc++.h>
using namespace std;
int test, n, tot, a[200001], f[6000001], ans, v[6000001], pre[6000001], p1, p2,
    u[6000001];
bool b[100001];
set<int> c[6000001];
map<int, int> idx;
inline void dfs(int x) {
  int Max1 = -1, Max2 = -1, P1 = 0, P2 = 0;
  if (f[x]) Max1 = 0, P1 = x;
  for (auto y : c[x]) {
    dfs(y);
    if (v[y] >= 0)
      if (v[y] + 1 > Max1)
        Max2 = Max1, P2 = P1, Max1 = v[y] + 1, P1 = pre[y];
      else if (v[y] + 1 > Max2)
        Max2 = v[y] + 1, P2 = pre[y];
  }
  if (Max2 >= 0 && Max1 + Max2 > ans) ans = Max1 + Max2, p1 = P1, p2 = P2;
  v[x] = Max1;
  pre[x] = P1;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (idx.find(x) == idx.end()) f[++tot] = 1, idx[x] = tot, u[tot] = i;
    for (; x;) {
      int y = 1;
      for (; y < x; y *= 2)
        ;
      int z = y - x;
      if (idx.find(z) == idx.end()) idx[z] = ++tot;
      c[idx[z]].insert(idx[x]);
      x = z;
    }
  }
  memset(v, 128, sizeof(v));
  dfs(idx[0]);
  printf("%d %d %d\n", u[p1], u[p2], ans);
}
