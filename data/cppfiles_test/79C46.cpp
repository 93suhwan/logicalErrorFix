#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
int T, n;
int a[500010], b[500010], per[500010], dis[500010], vis[500010], c[500010];
vector<pair<int, int>> e[500010];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  int now = n - 1;
  queue<pair<int, int>> que;
  dis[n] = 0;
  que.push({n, n});
  c[n] = n;
  set<int> se;
  for (int i = 0; i < n; ++i) {
    se.insert(i);
  }
  while (!que.empty()) {
    int u = que.front().first, uu = que.front().second;
    que.pop();
    vis[u] = 1;
    while (1) {
      auto it = se.lower_bound(u - a[u]);
      if (it != se.end() && (*it) <= u) {
        int v = (*it) + b[(*it)];
        if (!vis[v]) {
          dis[v] = dis[u] + 1;
          vis[v] = 1;
          per[v] = u;
          c[v] = (*it);
          que.push({v, *it});
        }
        se.erase(it);
      } else
        break;
    }
  }
  if (dis[0] == 0) {
    printf("-1\n");
  } else {
    printf("%d\n", dis[0]);
    vector<int> ans;
    int tmp = 0;
    while (1) {
      if (tmp == n) break;
      ans.push_back(c[tmp]);
      tmp = per[tmp];
    }
    reverse(ans.begin(), ans.end());
    for (int item : ans) {
      printf("%d ", item);
    }
  }
  return 0;
}
