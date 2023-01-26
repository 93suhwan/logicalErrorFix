#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 3;
struct node {
  int a, b;
} q[maxn], t[maxn];
int cmp1(node x, node y) {
  if (x.a == y.a) return x.b < y.b;
  return x.a < y.a;
}
int n, tr[maxn], tot;
void add(int x, int y) {
  for (int i = x; i < 2e5 + 3; i += i & (-i)) {
    tr[i] = max(tr[i], y);
  }
}
int que(int x) {
  int res = 0;
  for (int i = x; i; i -= i & (-i)) {
    res = max(res, tr[i]);
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &q[i].a);
    q[i].b = i - q[i].a;
  }
  sort(q + 1, q + n + 1, cmp1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (q[i].a != q[i - 1].a) {
      for (int j = 1; j <= tot; ++j) add(t[j].a, t[j].b);
      tot = 0;
    }
    if (q[i].b < 0) continue;
    int res = que(q[i].b + 1);
    t[++tot].a = q[i].b + 1;
    t[tot].b = res + 1;
    ans = max(ans, res + 1);
  }
  cout << ans << endl;
  return 0;
}
