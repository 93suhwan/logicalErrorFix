#include <bits/stdc++.h>
using namespace std;
int n, k, c[10010];
struct node {
  int l, r, c;
};
vector<int> p[110];
vector<node> v[110];
pair<int, int> ans[110];
bool vis[110];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n * k; i++) {
    scanf("%d", &c[i]);
    p[c[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < k; j++) v[j].push_back({p[i][j - 1], p[i][j], i});
  int m = (n + k - 2) / (k - 1), idx = 0;
  for (int i = 1; i < k; i++) {
    sort(v[i].begin(), v[i].end(), [](node x, node y) { return x.r < y.r; });
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (vis[v[i][j].c]) continue;
      vis[v[i][j].c] = 1;
      cnt++;
      ans[idx++] = {v[i][j].l, v[i][j].r};
      if (cnt == m) break;
    }
  }
  for (int i = 0; i < n; i++) printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
