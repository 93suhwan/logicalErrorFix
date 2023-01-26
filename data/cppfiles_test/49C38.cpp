#include <bits/stdc++.h>
using namespace std;
int tac, n, q;
int a[1000010], seg[1000010];
vector<int> v[1000010];
set<int> rep[1000010];
vector<pair<pair<int, int>, int> > que[1000010];
int cnt[1000010], ans[1000010];
inline void add(int x, int y) {
  x++;
  while (x < n + 5) seg[x] += y, x += x & (-x);
}
inline int sum(int x) {
  x++;
  int r = 0;
  while (x > 0) r += seg[x], x -= x & (-x);
  return r;
}
void dfs(int x, int par) {
  rep[cnt[a[x]]].erase(a[x]), add(cnt[a[x]], -1);
  cnt[a[x]]++;
  add(cnt[a[x]], 1), rep[cnt[a[x]]].insert(a[x]);
  for (int i = 0; i < que[x].size(); i++) {
    int al = sum(que[x][i].first.first) + que[x][i].first.second;
    if (sum(n) < al) {
      ans[que[x][i].second] = -1;
      continue;
    }
    int l = 0, r = n, mid;
    while (l < r) {
      mid = (l + r) >> 1;
      if (sum(mid) < al)
        l = mid + 1;
      else
        r = mid;
    }
    ans[que[x][i].second] = (*rep[l].begin()) + 1;
  }
  for (int i = 0; i < v[x].size(); i++) {
    int xi = v[x][i];
    if (xi != par) dfs(xi, x);
  }
  rep[cnt[a[x]]].erase(a[x]), add(cnt[a[x]], -1);
  cnt[a[x]]--;
  add(cnt[a[x]], 1), rep[cnt[a[x]]].insert(a[x]);
}
int main() {
  scanf("%d", &tac);
  while (tac--) {
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) v[i].clear(), que[i].clear();
    for (int i = 0; i <= n; i++) rep[i].clear();
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]--;
    for (int i = 1; i < n; i++) {
      int x;
      scanf("%d", &x), x--;
      v[x].push_back(i);
    }
    for (int i = 0; i < q; i++) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z), x--;
      que[x].push_back(make_pair(make_pair(y - 1, z), i));
    }
    fill(seg, seg + n + 7, 0), fill(cnt, cnt + n + 7, 0);
    dfs(0, -1);
    for (int i = 0; i < q; i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
