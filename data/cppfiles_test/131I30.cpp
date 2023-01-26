#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 10;
int n, x;
unordered_map<int, int> mp;
int o = 0;
inline int find(int x) {
  for (int i = 0; i <= 30; i++) {
    if ((1 << i) >= x) return 1 << i;
  }
}
int a[maxn];
int head[maxn], to[maxn << 1], nex[maxn << 1], tot = 0;
int f[maxn], idx[maxn], back[maxn], ansu, ansv, ans;
inline void add(int u, int v) {
  to[++tot] = v;
  nex[tot] = head[u];
  head[u] = tot;
  to[++tot] = u;
  nex[tot] = head[v];
  head[v] = tot;
}
void dfs(int u, int fa) {
  f[u] = 0;
  idx[u] = u;
  for (int i = head[u]; i; i = nex[i]) {
    int v = to[i];
    if (v == fa) continue;
    dfs(v, u);
    if (f[v] + 1 + f[u] > ans)
      ans = f[u] + f[v] + 1, ansu = idx[u], ansv = idx[v];
    if (f[v] + 1 > f[u]) f[u] = f[v] + 1, idx[u] = idx[v];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  mp[0] = ++o;
  for (int i = 1; i <= n; i++) {
    int x = a[i];
    if (!mp.count(a[i]))
      mp[x] = ++o;
    else {
      back[mp[x]] = i;
      continue;
    }
    back[mp[x]] = i;
    while (x) {
      int y = find(x) - x;
      if (!mp.count(x)) mp[x] = ++o;
      if (!mp.count(y))
        mp[y] = ++o;
      else {
        add(mp[x], mp[y]);
        break;
      }
      add(mp[x], mp[y]);
      x = y;
    }
  }
  dfs(1, 0);
  sort(a + 1, a + n + 1);
  int x = a[n], j = n, dist = 0, cnt = 0;
  while (x) {
    while (a[j] == x && j) j--, cnt++;
    if (cnt == n) break;
    dist++;
    x = find(x) - x;
  }
  if (cnt == n) {
    int mi = 1, mx = 1;
    for (int i = 2; i <= n; i++) {
      if (a[i] > a[mx]) mx = i;
      if (a[i] < a[mi]) mi = i;
    }
    cout << mi << " " << mx << " " << dist << endl;
  } else
    cout << back[ansu] << " " << back[ansv] << " " << ans << endl;
  return 0;
}
