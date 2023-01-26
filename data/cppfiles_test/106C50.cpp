#include <bits/stdc++.h>
using namespace std;
const int N = 1 << 20 | 5;
int n, k, m;
int a[N], b[N][20], match[N], bitlen[N], pre[N], dis[N];
int visx[N];
struct Node {
  int x, y, val;
  bool operator>(const Node &b) const { return val > b.val; }
};
Node maxans;
void dfs(int x, int last, int d) {
  pre[x] = last;
  dis[x] = d;
  if (!bitlen[x]) {
    for (int i = 0; i < n; ++i)
      if (pre[b[x][i]] == -1) dfs(b[x][i], x, d);
  } else if (~match[x])
    dfs(match[x], x, d);
  else if ((Node){-1, x, dis[x] + a[x]} > maxans)
    maxans = (Node){-1, x, dis[x] + a[x]};
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  m = 1 << n;
  multiset<Node, greater<Node>> ms;
  for (int i = 0; i < m; ++i) cin >> a[i], match[i] = -1;
  for (int i = 1; i < m; ++i) bitlen[i] = bitlen[i >> 1] ^ (i & 1);
  for (int i = 0; i < m; ++i) {
    int id = -1;
    for (int j = 0; j < n; ++j) {
      b[i][j] = i ^ (1 << j);
      if (id == -1 || a[b[i][j]] > a[id]) id = b[i][j];
    }
    if (!bitlen[i]) ms.insert((Node){i, id, a[i] + a[id]});
  }
  int ans = 0;
  for (int _ = 1; _ <= min(m / 2, k); ++_) {
    auto it = ms.begin();
    while (ms.size() && (~match[it->x] || ~match[it->y]))
      ms.erase(it), it = ms.begin();
    maxans = ms.size() ? *it : (Node){-1, -1, -1};
    sort(visx + 1, visx + visx[0] + 1,
         [&](const int &a, const int &b) { return ::a[a] > ::a[b]; });
    visx[0] = unique(visx + 1, visx + visx[0] + 1) - visx - 1;
    for (int i = 1; i <= visx[0]; ++i) {
      pre[visx[i]] = -1;
      for (int j = 0; j < n; ++j) pre[b[visx[i]][j]] = -1;
    }
    for (int i = 1; i <= visx[0]; ++i)
      if (match[visx[i]] == -1 && pre[visx[i]] == -1)
        dfs(visx[i], m, a[visx[i]]);
    int x = maxans.x, y = maxans.y;
    for (int j = 0; j < n; ++j) visx[++visx[0]] = b[y][j];
    if (x == -1)
      while (y != m) {
        match[y] = x = pre[y];
        match[x] = y;
        y = pre[x];
      }
    else
      match[y] = x, match[x] = y;
    ans += maxans.val;
  }
  printf("%d\n", ans);
  return 0;
}
