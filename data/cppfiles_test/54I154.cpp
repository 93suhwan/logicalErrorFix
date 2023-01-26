#include <bits/stdc++.h>
using namespace std;
int fa[400005], tot[400005], pe[400005];
bool cl[400005];
int find(int x) { return x == fa[x] ? x : find(fa[x]); }
void unnion(int x, int y) {
  fa[y] = x;
  pe[x] += pe[y];
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(cl, 0, sizeof cl);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * 2; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) pe[i] = 1;
    for (int i = n + 1; i <= n * 2; i++) pe[i] = 0;
    for (int i = 1; i <= m; i++) {
      int x, y;
      string s;
      scanf("%d%d", &x, &y);
      cin >> s;
      if (s[0] == 'i') {
        int xx = find(x), xxx = find(x + n), yy = find(y), yyy = find(y + n);
        if (xx != yyy) unnion(xx, yyy);
        if (yy != xxx) unnion(yy, xxx);
      } else {
        int xx = find(x), xxx = find(x + n), yy = find(y), yyy = find(y + n);
        if (xx != yy) unnion(xx, yy);
        if (yyy != xxx) unnion(yyy, xxx);
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int x = find(i), xx = find(i + n);
      if (x == xx) {
        ans = -1;
        break;
      }
      if (x == i) {
        if (!cl[x]) {
          cl[x] = cl[xx] = 1;
          ans += max(pe[x], pe[xx]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
