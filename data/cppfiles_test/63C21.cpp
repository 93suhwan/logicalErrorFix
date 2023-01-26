#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 4e5 + 7;
char s[MAXN];
int g[20][MAXN], w[20], mn[20], f[1 << 20], W[1 << 20], ans;
int main() {
  memset(f, -0x3f, sizeof(f));
  f[0] = 0;
  scanf("%d", &n);
  for (int t = 0; t < n; ++t) {
    scanf("%s", s + 1);
    int cnt = 0, m = strlen(s + 1);
    for (int j = 1; j <= m; ++j) {
      if (s[j] == '(')
        ++cnt;
      else
        --cnt;
      if (cnt <= mn[t]) g[t][-cnt]++, mn[t] = cnt;
    }
    w[t] = cnt;
  }
  for (int s = 0; s < (1 << n); ++s) {
    if (f[s] < 0) continue;
    for (int i = 0; i < n; ++i) {
      if (s >> i & 1) continue;
      int t = s ^ (1 << i);
      ans = max(ans, f[s] + g[i][W[s]]);
      if (W[s] + mn[i] >= 0) {
        W[t] = W[s] + w[i];
        f[t] = max(f[t], f[s] + g[i][W[s]]);
      }
    }
  }
  printf("%d\n", ans);
}
