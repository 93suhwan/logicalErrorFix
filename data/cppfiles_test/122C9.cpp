#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> E[200005], Es;
int color[200005], par[200005];
inline int count(int x) {
  int set = 0;
  for (int i = 0; i <= 30; i++)
    if (x & (1 << i)) set++;
  return set % 2;
}
bool draw(int v, int c) {
  if (color[v] >= 0) return color[v] == c;
  color[v] = c;
  bool ret = true;
  for (vector<int> e : E[v]) ret = ret && draw(e[0], e[1] ? !c : c);
  return ret;
}
int main() {
  int t, m, n;
  cin >> t;
  while (t--) {
    scanf("%d%d", &n, &m);
    Es.clear();
    for (int i = 0; i <= n; i++) {
      E[i].clear();
      par[i] = 0;
      color[i] = -1;
    }
    for (int i = 1; i < n; i++) {
      int a, b, v;
      scanf("%d%d%d", &a, &b, &v);
      Es.push_back({a, b, v});
      if (v >= 0) {
        E[a].push_back({b, count(v)});
        E[b].push_back({a, count(v)});
      }
    }
    for (int i = 0; i < m; i++) {
      int a, b, v;
      scanf("%d%d%d", &a, &b, &v);
      E[a].push_back({b, v});
      E[b].push_back({a, v});
    }
    bool can = 1;
    for (int i = 1; can && (i <= n); i++) {
      if (color[i] < 0) {
        can = draw(i, 0);
      }
    }
    printf("%s\n", can ? "YES" : "NO");
    if (can) {
      for (vector<int> e : Es) {
        int v = e[2] >= 0 ? e[2] : color[e[0]] ^ color[e[1]];
        printf("%d %d %d\n", e[0], e[1], v);
      }
    }
  }
}
