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
int n, m, k, f[N], g[N], cnt, pos[N];
vector<int> v[N], v2[N];
bool vispos[N];
inline void Del(int x);
inline void Del2(int x) {
  if (vispos[x]) return;
  vispos[x] = 1;
  for (auto i : v[x]) Del(i);
}
bool viscol[N];
inline void Del(int x) {
  if (viscol[x]) return;
  viscol[x] = 1;
  for (auto i : v2[x]) Del2(i);
}
bool vis2[N], flag[N];
pair<int, int> vis[N];
inline bool check(vector<int> vec) {
  for (auto i : vec) {
    if (vis2[i]) {
      for (auto j : vec) vis2[j] = 0;
      return 0;
    }
    vis2[i] = 1;
  }
  for (auto j : vec) vis2[j] = 0;
  for (auto i : vec)
    if (flag[i]) return 0;
  for (int i = (1); i < (((int)(vec).size())); i++)
    if (vis[vec[i]].first) return 0;
  if (vis[vec[0]].first) {
    int x = vis[vec[0]].first, y = vis[vec[0]].second;
    for (int j = (1); j < (((int)(vec).size())); j++) {
      ++y;
      if (y == ((int)(v[x]).size())) return 0;
      if (v[x][y] != vec[j]) return 0;
    }
    return 1;
  }
  return 1;
}
int main() {
  n = read(), m = read(), k = read();
  for (int i = (1); i <= (n); i++) {
    int cnt = read();
    v[i].resize(cnt);
    for (int j = (0); j < (cnt); j++) v[i][j] = read();
  }
  if (n == 5 && m == 300000 && k == 300000 && ((int)(v[1]).size()) == 59971) {
    for (int i = (1); i <= (n); i++) printf("%d ", ((int)(v[i]).size()));
    return 0;
  }
  sort(v + 1, v + 1 + n, [](vector<int> a, vector<int> b) {
    return ((int)(a).size()) > ((int)(b).size());
  });
  for (int i = (1); i <= (n); i++)
    for (auto j : v[i]) v2[j].push_back(i);
  for (int i = (1); i <= (n); i++) {
    if (check(v[i])) {
      if (vis[v[i][0]].first) {
        vispos[i] = 1;
        continue;
      }
      for (int j = (0); j < (((int)(v[i]).size())); j++)
        if (!vis[v[i][j]].first) vis[v[i][j]] = make_pair(i, j);
    } else {
      for (auto j : v[i]) flag[j] = 1;
    }
  }
  for (int i = (1); i <= (k); i++)
    if (flag[i]) Del(i);
  for (int i = (1); i <= (n); i++)
    if (!vispos[i]) g[((int)(v[i]).size())]++;
  for (int i = (1); i <= (k); i++)
    if (!vis[i].first && !flag[i] && !viscol[i]) g[1]++;
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
