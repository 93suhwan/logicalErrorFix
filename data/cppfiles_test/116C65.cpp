#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
const int N = 3e5 + 10, mod = 998244353;
int n, m, k, f[N], g[N], cnt, pos[N], tot[N][3];
vector<int> v[N];
int fa[N], d[N], cnt0[N], cnt1[N];
bool flag[N];
inline int Find(int x) { return fa[x] == x ? x : fa[x] = Find(fa[x]); }
map<pair<int, int>, int> vis;
inline void Merge(int x, int y) {
  if (vis.count(make_pair(x, y))) return;
  vis[make_pair(x, y)] = 1;
  ++cnt0[x], ++cnt1[y], ++d[x], ++d[y];
  if (Find(x) == Find(y)) return flag[Find(x)] = 1, void(0);
  int rtx = Find(x), rty = Find(y);
  fa[rtx] = rty, flag[rty] |= flag[rtx];
  if (cnt0[x] >= 2 || cnt1[y] >= 2) flag[rty] = 1;
}
int main() {
  n = read(), m = read(), k = read();
  for (int i = (1); i <= (k); i++) fa[i] = i;
  for (int i = (1); i <= (n); i++) {
    int cnt = read();
    v[i].resize(cnt);
    for (int j = (0); j < (cnt); j++) v[i][j] = read();
    for (int j = (1); j < (cnt); j++) Merge(v[i][j - 1], v[i][j]);
  }
  for (int i = (1); i <= (k); i++) {
    if (d[i] > 2)
      tot[Find(i)][1] += 3;
    else
      tot[Find(i)][d[i]]++;
  }
  for (int i = (1); i <= (k); i++)
    if (Find(i) == i && !flag[i]) {
      if (tot[i][0] == 1)
        g[1]++;
      else if (tot[i][1] == 2)
        g[tot[i][1] + tot[i][2]]++;
    }
  for (int i = (1); i <= (m); i++)
    if (g[i]) pos[++cnt] = i;
  f[0] = 1;
  for (int i = (1); i <= (m); i++)
    for (int j = (1); j <= (cnt); j++) {
      if (pos[j] > i) break;
      f[i] = (f[i] + 1ll * f[i - pos[j]] * g[pos[j]]) % mod;
    }
  printf("%d\n", f[m]);
}
