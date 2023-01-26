#include <bits/stdc++.h>
const int N = 500005, inf = 0x3f3f3f3f;
using namespace std;
int n, f[1 << 20], sm[1 << 20], a[25][N], b[25][N], c[25][N], ans, len[25];
char s[25][N];
void init() {
  for (register int i = 1; i <= n; i++) {
    for (register int j = 1; j <= len[i]; j++) {
      a[i][j] = a[i][j - 1] + (s[i][j] == '(' ? 1 : -1);
      b[i][j] = b[i][j - 1], c[i][j] = c[i][j - 1];
      if (a[i][j] < b[i][j])
        b[i][j] = a[i][j], c[i][j] = 1;
      else if (a[i][j] == b[i][j])
        c[i][j]++;
    }
  }
}
int get(int i, int mn) {
  int l = 0, r = len[i], res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (b[i][mid] >= mn)
      res = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return res;
}
void solve() {
  memset(f, -inf, sizeof f), f[0] = 0;
  for (register int s = 1; s <= (1 << n) - 1; s++) {
    for (register int i = 1; i <= n; i++) {
      if (!((s >> (i - 1)) & 1)) continue;
      int t = s ^ (1 << (i - 1));
      if (f[t] == -inf) continue;
      int mn = sm[t] + b[i][len[i]];
      if (mn >= 0) {
        if (f[s] < f[t] + (mn ? 0 : c[i][len[i]])) {
          f[s] = f[t] + (mn ? 0 : c[i][len[i]]);
          sm[s] = sm[t] + a[i][len[i]];
        }
      }
      mn = -sm[t];
      int p = get(i, mn);
      ans = max(ans, f[t] + (b[i][p] == mn ? c[i][p] : 0));
    }
  }
}
signed main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%s", s[i] + 1), len[i] = strlen(s[i] + 1);
  }
  init();
  solve();
  printf("%d\n", ans);
  return 0;
}
