#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int t, n, m, a[310 * 310], b[310 * 310];
int mp[310][310];
int c[310 * 310];
void init() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) mp[i][j] = 0;
}
inline int lowbit(int x) { return x & -x; }
void update(int *tr, int x) {
  for (int i = x; i <= m; i += lowbit(i)) ++tr[i];
}
int query(int *tr, int x) {
  int res = 0;
  for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
  return res;
}
struct Node {
  int x, y;
  Node(int x, int y) : x(x), y(y) {}
  bool operator<(const Node &rhs) const {
    return x > rhs.x || (x == rhs.x && y < rhs.y);
  }
};
priority_queue<Node> q[310 * 310];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= n * m; ++i) scanf("%d", &a[i]);
    iota(b + 1, b + n * m + 1, 1);
    sort(b + 1, b + n * m + 1,
         [](const int i, const int j) { return a[i] < a[j]; });
    int cnt = 0;
    for (int i = 1; i <= n * m; ++i) {
      if (a[b[i]] != a[b[i - 1]]) ++cnt;
      c[b[i]] = cnt;
      q[cnt].push(Node((i - 1) / m + 1, (i - 1) % m + 1));
    }
    long long res = 0;
    for (int i = 1; i <= n * m; ++i) {
      auto to = q[c[i]].top();
      q[c[i]].pop();
      res += query(mp[to.x], to.y);
      update(mp[to.x], to.y);
    }
    for (int i = 1; i <= cnt; ++i)
      while (!q[i].empty()) q[i].pop();
    printf("%lld\n", res);
  }
}
