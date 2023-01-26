#include <bits/stdc++.h>
using namespace std;
int n, m, s, l;
const int mo = 1e9 + 7;
int siz[1010101][2];
int fa[1010101];
int v[1010101];
char opt[10];
int fifa(int x) { return x == fa[x] ? x : fa[x] = fifa(fa[x]); }
void hb(int x, int y) {
  x = fifa(x);
  y = fifa(y);
  if (x == y) return;
  fa[y] = x;
  siz[x][0] += siz[y][0];
  siz[x][1] += siz[y][1];
}
void doing() {
  scanf("%d %d", &n, &m);
  for (register int i = 1; i <= n * 2; ++i) {
    v[i] = 0;
    fa[i] = i;
    siz[i][0] = i <= n;
    siz[i][1] = i > n;
  }
  int sf = 0;
  for (register int i = 1; i <= m; ++i) {
    scanf("%d %d %s", &s, &l, opt);
    if (opt[0] == 'c') {
      if (fifa(s) == fifa(l + n)) sf = 1;
      hb(s, l);
      hb(s + n, l + n);
    } else {
      if (fifa(s) == fifa(l)) sf = 1;
      hb(s, l + n);
      hb(s + n, l);
    }
  }
  if (sf) {
    printf("-1\n");
    return;
  }
  int ans = 0;
  for (register int i = 1; i <= n; ++i) {
    s = fifa(i);
    if (s != i) continue;
    ans += max(siz[s][0], siz[s][1]);
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    doing();
  }
  return 0;
}
