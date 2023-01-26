#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7;
inline int read() {
  int x = 0, w = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    w |= ch == '-';
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return w ? -x : x;
}
int n, k, a[400005], ta[400005], b[400005], tb[400005], flag[400005],
    tf[400005], id[400005];
inline int cmp(int x, int y) { return a[x] < a[y]; }
int t[400005];
inline void add(int x, int data) {
  for (; x <= 2 * n; x += (x & (-x))) t[x] = (t[x] + data) % mo;
}
inline int que(int x) {
  int res = 0;
  for (; x; x -= (x & (-x))) res = (res + t[x]) % mo;
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
  scanf("%d", &k);
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    flag[x] = 1;
  }
  for (int i = 1; i <= n; i++) id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  for (int i = 1; i <= n; i++) ta[i] = a[i], tb[i] = b[i], tf[i] = flag[i];
  for (int i = 1; i <= n; i++)
    a[i] = ta[id[i]], b[i] = tb[id[i]], flag[i] = tf[id[i]];
  int mx = 0;
  for (int i = n; i >= 1; i--) {
    if (flag[i]) mx = max(mx, b[i]);
    if (mx > b[i]) flag[i] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    flag[i] = (flag[i] + que(2 * n) - que(b[i]) + mo) % mo;
    add(b[i], flag[i]);
    ans = (ans + flag[i]) % mo;
  }
  printf("%d\n", ans);
  return 0;
}
