#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 11, mod = 1e9 + 7;
int n, k, rt, mx[N], dep, tot;
bool vis[N];
int a[N], sz[N], ans;
int t[2][N], s[2][N], p[2][N], q[2][N];
vector<pair<int, int> > to[N];
void ins(int x, int y, int z) {
  ++x;
  for (; x <= min(tot, k) + 1; x += x & -x)
    s[z][x] = (s[z][x] + y) % mod, ++t[z][x];
}
int query(int x, int y, int z) {
  ++x;
  int res = 0;
  for (; x; x -= x & -x)
    res = (res + 1ll * s[z][x] + 1ll * t[z][x] * y % mod) % mod;
  return res;
}
void dfs1(int x, int fa) {
  sz[x] = 1;
  for (auto v : to[x]) {
    if (vis[v.first] || v.first == fa) continue;
    dfs1(v.first, x);
    sz[x] += sz[v.first];
  }
}
void dfs2(int x, int fa, int y) {
  mx[x] = 0;
  for (auto v : to[x]) {
    if (vis[v.first] || v.first == fa) continue;
    dfs2(v.first, x, y);
    mx[x] = max(mx[x], sz[v.first]);
  }
  mx[x] = max(mx[x], tot - sz[x]);
  if (rt == -1 || mx[rt] > mx[x]) rt = x;
}
void dfs3(int x, int fa, int y, int sum, int cnt, int las) {
  if (k < cnt) return;
  dep = max(dep, cnt);
  if (k >= cnt) ans = (0ll + ans + sum + query(k - cnt, sum, y)) % mod;
  if (k - 1 >= cnt) ans = (ans + query(k - 1 - cnt, sum, y ^ 1)) % mod;
  for (auto v : to[x]) {
    if (vis[v.first] || v.first == fa) continue;
    dfs3(v.first, x, y, (sum + a[v.first]) % mod, cnt + (las ^ v.second),
         v.second);
  }
}
void dfs4(int x, int fa, int y, int sum, int cnt, int las) {
  if (k < cnt) return;
  ins(cnt, sum, y);
  for (auto v : to[x]) {
    if (vis[v.first] || v.first == fa) continue;
    dfs4(v.first, x, y, (sum + a[v.first]) % mod, cnt + (las ^ v.second),
         v.second);
  }
}
void solve(int x) {
  rt = x;
  dfs1(x, x);
  tot = sz[x];
  rt = -1;
  dfs2(x, x, x);
  tot = sz[x];
  x = rt;
  vis[rt] = 1;
  int maxlen = 0;
  for (auto v : to[x]) {
    if (vis[v.first]) continue;
    dfs3(v.first, x, v.second, (a[x] + a[v.first]) % mod, 0, v.second);
    dfs4(v.first, x, v.second, a[v.first], 0, v.second);
  }
  for (int i = (0); i <= (min(tot, k) + 2); i++)
    for (int j = (0); j <= (1); j++) s[j][i] = t[j][i] = 0;
  for (auto v : to[x]) {
    if (vis[v.first]) continue;
    solve(v.first);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = (1); i <= (n); i++) {
    scanf("%d", a + i);
    ans = (ans + a[i]) % mod;
  }
  for (int i = (1); i <= (n - 1); i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    to[x].push_back(make_pair(y, z));
    to[y].push_back(make_pair(x, z));
  }
  solve(1);
  printf("%d\n", ans);
  return 0;
}
