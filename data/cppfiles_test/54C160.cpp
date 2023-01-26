#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &x) {
  x = 0;
  int f = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    f |= (ch == '-');
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x = f ? -x : x;
  return;
}
const long long mod = 1e9 + 7;
int T;
int n, m, ans, r1, r2, r;
int vis[200050];
vector<pair<int, int> > Edg[200050];
int dfs(int cur, int md, int fa) {
  if (vis[cur] != -1 && vis[cur] != md) {
    return -1;
  } else if (vis[cur] != -1)
    return 0;
  vis[cur] = md;
  int ret = md;
  for (auto key : Edg[cur]) {
    if (key.first == fa) continue;
    int temp;
    if (md)
      temp = !key.second;
    else
      temp = key.second;
    int t = dfs(key.first, temp, cur);
    if (t == -1) {
      ret = t;
      break;
    }
    ret += t;
  }
  if (ret == -1) vis[cur] = ret;
  return ret;
}
void init_dfs(int cur) {
  if (vis[cur] == -1) return;
  vis[cur] = -1;
  for (auto key : Edg[cur]) init_dfs(key.first);
}
int main() {
  read(T);
  for (int t = 1; t <= T; t++) {
    read(n);
    read(m);
    ans = 0;
    for (int i = 1; i <= n; i++) {
      vis[i] = -1;
      Edg[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      int u, v;
      string c;
      read(u);
      read(v);
      cin >> c;
      if (c[0] == 'c') {
        Edg[u].push_back({v, 0});
        Edg[v].push_back({u, 0});
      } else {
        Edg[u].push_back({v, 1});
        Edg[v].push_back({u, 1});
      }
    }
    for (int i = 1; i <= n; i++) {
      if (vis[i] != -1) continue;
      r1 = dfs(i, 1, -1);
      init_dfs(i);
      r2 = dfs(i, 0, -1);
      r = max(r1, r2);
      if (r1 == r) {
        init_dfs(i);
        dfs(i, 1, -1);
      }
      if (r == -1) {
        ans = -1;
        break;
      }
      ans += r;
    }
    cout << ans << '\n';
  }
  return 0;
}
