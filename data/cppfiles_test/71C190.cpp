#include <bits/stdc++.h>
using namespace std;
const int MAXN = 11;
int n, kkk;
char s[MAXN];
long long mini[MAXN][MAXN];
int lowerb[(1 << 10) + 1][MAXN];
int upperb[(1 << 10) + 1][MAXN];
inline void init() {
  int num[MAXN];
  for (int mask = 0; mask < (1 << 10); mask++) {
    int sz = 0;
    for (int i = 0; i <= 9; i++)
      if ((mask >> i) & 1) num[sz++] = i;
    for (int i = 0; i <= 9; i++) {
      lowerb[mask][i] = lower_bound(num, num + sz, i) - num;
      upperb[mask][i] = upper_bound(num, num + sz, i) - num;
    }
  }
  for (int i = 0; i <= 9; i++)
    for (int j = 1, base = 1; j <= 9; j++, base *= 10)
      mini[i][j] = mini[i][j - 1] + (long long)i * base;
}
map<int, map<int, long long> > mmp;
inline void solve() {
  scanf("%s%d", s + 1, &kkk);
  n = strlen(s + 1);
  reverse(s + 1, s + n + 1);
  int val = 0;
  for (int i = 1, base = 1; i <= n; i++, base *= 10) val += (s[i] - '0') * base;
  if (mmp[val][kkk]) {
    printf("%lld\n", mmp[val][kkk]);
    return;
  }
  long long ans = 1e18;
  int num[MAXN];
  for (int mask = 0; mask < (1 << 10); mask++) {
    int sz = 0;
    for (int i = 0; i <= 9; i++)
      if ((mask >> i) & 1) num[sz++] = i;
    if (sz == 0 || sz > kkk) continue;
    if (num[sz - 1] < s[n] - '0') continue;
    bool fg = false;
    long long cur = 0;
    for (int i = 1, base = 1; i <= n; i++, base *= 10) {
      int x = s[i] - '0';
      int pos = lowerb[mask][x];
      if (pos == sz) {
        fg = true;
        continue;
      }
      if (!fg) {
        if (num[pos] == x)
          cur += (long long)num[pos] * base;
        else
          cur = mini[num[0]][i - 1] + (long long)num[pos] * base;
      } else {
        if (num[pos] == x) {
          pos = upperb[mask][x];
          if (pos == sz) continue;
        }
        cur = mini[num[0]][i - 1] + (long long)num[pos] * base, fg = false;
      }
    }
    if (!fg) ans = min(ans, cur);
    if (ans == val) break;
  }
  printf("%lld\n", mmp[val][kkk] = ans);
}
int main() {
  init();
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
