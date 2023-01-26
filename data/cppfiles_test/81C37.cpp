#include <bits/stdc++.h>
using namespace std;
int const N = 500500;
struct Node {
  int s, a;
  friend bool operator<(Node x, Node y) {
    int u = max(x.s, x.a), v = max(y.s, y.a);
    if (u == v)
      return x.s < y.s;
    else
      return u < v;
  }
} p[N];
int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < (n); ++i) scanf("%d%d", &p[i].s, &p[i].a);
  sort(p, p + n);
  int ans = 0;
  for (int i = 0; i < (n); ++i) {
    if (p[i].s >= d) {
      ++ans;
      d = max(d, p[i].a);
    }
  }
  printf("%d\n", ans);
  return 0;
}
