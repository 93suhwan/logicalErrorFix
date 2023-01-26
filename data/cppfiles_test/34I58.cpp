#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkMax(T &x, T y) {
  if (y > x) x = y;
}
template <typename T>
void chkMin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
void inline read(T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
  x *= f;
}
const int N = 8200, INF = 0x3f3f3f3f;
int n, a[N], f[N], g[N];
vector<int> p[N];
int main() {
  read(n);
  for (int i = 1, x; i <= n; i++) read(x), p[x].push_back(i);
  memset(f, 0x3f, sizeof f);
  memset(g, 0x3f, sizeof g);
  f[0] = g[0] = 0;
  for (int x = 1; x <= 5000; x++) {
    if (!p[x].size()) continue;
    for (int i = 0; i < N; i++) {
      if (f[i] == INF) continue;
      if (f[i ^ x] == INF && g[i] < p[x].back()) {
        f[i ^ x] = x;
        int pt = lower_bound(p[x].begin(), p[x].end(), g[i]) - p[x].begin();
        g[i ^ x] = p[x][pt];
      }
    }
  }
  int c = 0;
  for (int i = 0; i < N; i++)
    if (f[i] != INF) c++;
  printf("%d\n", c);
  for (int i = 0; i < N; i++)
    if (f[i] != INF) printf("%d ", i);
  return 0;
}
