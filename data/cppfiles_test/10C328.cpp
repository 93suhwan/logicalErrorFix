#include <bits/stdc++.h>
using namespace std;
int h[200010];
struct node {
  int x, id;
} a[200010];
int ans[200010];
template <typename _T>
void rd(_T &x) {
  int f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9')
    x = (x << 3) + (x << 1) + (s - '0'), s = getchar();
  x *= f;
}
inline bool cmp(const node &x, const node &y) { return x.x < y.x; }
int main() {
  int _;
  for (rd(_); _; _--) {
    int n, k;
    rd(n), rd(k);
    for (int i = 1; i <= n; i++) h[i] = ans[i] = 0;
    int maxn = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      rd(a[i].x);
      h[a[i].x]++;
      sum++;
      maxn = max(maxn, h[a[i].x]);
      if (h[a[i].x] > k) h[a[i].x]--, a[i].x = 200010, sum--;
      a[i].id = i;
    }
    maxn = k;
    int mod = sum / maxn;
    int t = 0;
    sort(a + 1, a + 1 + n, cmp);
    int col = 1;
    for (int i = 1; i <= n; i++) {
      if (a[i].x == 200010) break;
      if (t == mod) break;
      ans[a[i].id] = col;
      col++;
      if (col == maxn + 1) col = 1, t++;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
