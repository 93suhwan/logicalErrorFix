#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, mod = 1e9 + 7;
int add(int x, int y) {
  x += y;
  return x >= mod ? x - mod : x;
}
int c[maxn << 1], dp[maxn];
struct node {
  int x, y, op;
} e[maxn];
bool cmp(node a, node b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}
void ins(int x, int k) {
  while (x) {
    c[x] = add(c[x], k);
    x -= x & (-x);
  }
}
int query(int x) {
  int res = 0;
  for (; x <= 400000; x += (x & (-x))) {
    res = add(res, c[x]);
  }
  return res;
}
int main() {
  int n, q, x;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &e[i].y, &e[i].x);
  }
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &x);
    e[x].op = 1;
  }
  sort(e + 1, e + 1 + n, cmp);
  ins(2 * n, 1);
  for (int i = 1; i <= n; i++) {
    dp[i] = query(e[i].y);
    ins(e[i].y, dp[i]);
  }
  int pv = 1, ans = 0;
  for (int i = n; i > 0; i--) {
    ins(e[i].y, (mod - dp[i]) % mod);
    if (e[i].op == 1 && e[i].y >= pv) {
      ans = add(ans, query(pv));
      pv = e[i].y;
    }
  }
  printf("%d\n", ans);
  return 0;
}
