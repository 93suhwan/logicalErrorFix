#include <bits/stdc++.h>
using namespace std;
const long long vy[4] = {-1, 0, 1, 0}, vx[4] = {0, 1, 0, -1}, inf = 1e18;
const string ky = "URDL";
long long n, m, cy, cx, yk[26], a[2069][2069], dp[2069][2069], dh[2069][2069];
bitset<2069> vtd[2069], vtd2[2069];
bool bad;
void dfs(long long y, long long x) {
  long long yy, xx;
  vtd[y][x] = 1;
  vtd2[y][x] = 1;
  yy = min(max(y + vy[a[y][x]], 1ll), n);
  xx = min(max(x + vx[a[y][x]], 1ll), m);
  if (!vtd[yy][xx]) {
    dh[yy][xx] = dh[y][x] + 1;
    dfs(yy, xx);
  }
  if (!vtd2[yy][xx]) {
    dp[y][x] = dp[yy][xx] + !bad;
    bad &= y != cy || x != cx;
  } else {
    dp[y][x] = dh[y][x] - dh[yy][xx] + 1;
    cy = yy;
    cx = xx;
    bad = 1;
  }
  vtd2[y][x] = 0;
}
int main() {
  long long t, rr, i, j;
  pair<long long, pair<long long, long long>> mxe;
  char ch;
  for (i = 0; i < 4; i++) {
    yk[ky[i] - 'A'] = i;
  }
  scanf("%lld", &t);
  for (rr = 0; rr < t; rr++) {
    scanf("%lld%lld", &n, &m);
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        scanf(" %c", &ch);
        a[i][j] = yk[ch - 'A'];
        vtd[i][j] = 0;
      }
    }
    mxe = {-inf, {-1, -1}};
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) {
        if (!vtd[i][j]) {
          dfs(i, j);
        }
        mxe = max(mxe, {dp[i][j], {i, j}});
      }
    }
    printf("%lld %lld %lld\n", mxe.second.first, mxe.second.second, mxe.first);
  }
}
