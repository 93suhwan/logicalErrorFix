#include <bits/stdc++.h>
using namespace std;
int n, ans, pos[200005];
pair<int, int> eat[200005];
struct Node {
  int a, b, m, id;
};
vector<Node> a[2000005];
inline int read() {
  int s = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    s = (s << 1) + (s << 3) + ch - '0';
    ch = getchar();
  }
  return s * f;
}
int main() {
  for (int t = read(); t; --t) {
    n = read(), ans = 0;
    for (int i = 1, x, y, z; i <= n; ++i)
      x = read(), y = read(), z = read(),
      a[x + y - z].push_back((Node){x, y, z, i}), pos[i] = x + y - z;
    for (int i = 1; i <= n; ++i) {
      if (a[pos[i]].size()) {
        sort(a[pos[i]].begin(), a[pos[i]].end(),
             [](const Node &A, const Node &B) { return A.a < B.a; });
        int pre = -1e9;
        for (Node x : a[pos[i]]) {
          if (x.b < pos[i] - pre) ++ans, pre = min(x.a, pos[i]);
          eat[x.id].first = x.a - pre;
          eat[x.id].second = x.m - eat[x.id].first;
        }
        a[pos[i]].clear();
      }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) printf("%d %d\n", eat[i].first, eat[i].second);
  }
  return 0;
}
