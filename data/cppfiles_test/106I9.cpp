#include <bits/stdc++.h>
using namespace std;
const int N = 1000050;
int n, k, m;
int a[N], b[N][20], bb[N], vis[N], f[N], bitlen[N];
int visx[N], visy[N];
struct Node {
  int x, y, val;
  bool operator<(const Node &b) const { return val < b.val; }
} val[N];
int find(int x) { return f[x] == x ? x : (f[x] = find(f[x])); }
void unite(int x, int y) { f[find(x)] = find(y); }
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  m = 1 << n;
  for (int i = 0; i < m; ++i) cin >> a[i], f[i] = i;
  for (int i = 1; i < m; ++i) bitlen[i] = bitlen[i >> 1] ^ (i & 1);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) b[i][j] = i ^ (1 << j);
    sort(b[i], b[i] + n,
         [&](const int &a, const int &b) { return ::a[a] > ::a[b]; });
  }
  multiset<Node> ms;
  for (int i = 0; i < m; ++i)
    if (!bitlen[i]) ms.insert((Node){i, b[i][0], a[i] + a[b[i][0]]});
  int ans = 0;
  for (int _ = 1; _ <= min(m / 2, k); ++_) {
    Node maxans;
    auto it = --ms.end();
    while (vis[it->x] || vis[it->y]) ms.erase(it), it = --ms.end();
    maxans = *it;
    for (int i = 1, x; i <= visx[0]; ++i) {
      x = visx[i];
      while (bb[x] < n && vis[b[x][bb[x]]]) ++bb[x];
      if (bb[x] < n) val[find(x)] = (Node){-1, b[x][bb[x]], a[b[x][bb[x]]]};
    }
    for (int i = 1, y, y2; i <= visy[0]; ++i) {
      y = visy[i];
      y2 = find(y);
      for (int j = 0; j < n; ++j)
        if (!vis[b[y][j]] && val[y2].val < a[val[y2].y] + a[b[y][j]]) {
          val[y2] = (Node){b[y][j], val[y2].y, a[val[y2].y] + a[b[y][j]]};
          if (maxans < val[y2]) maxans = val[y2];
        }
    }
    vis[maxans.x] = vis[maxans.y] = true;
    visx[++visx[0]] = maxans.x;
    visy[++visy[0]] = maxans.y;
    ans += maxans.val;
    int y = maxans.y;
    for (int j = 0; j < n; ++j) {
      int x = b[y][j];
      if (vis[x])
        unite(x, y);
      else if (vis[b[x][bb[x]]]) {
        while (bb[x] < n && vis[b[x][bb[x]]]) ++bb[x];
        if (bb[x] < n) ms.insert((Node){x, b[x][bb[x]], a[x] + a[b[x][bb[x]]]});
      }
      x = maxans.x;
      if (vis[b[x][j]]) unite(x, b[x][j]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
