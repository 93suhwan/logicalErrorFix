#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1E6 + 100;
const long long MOD = 998244353;
long long bin(long long x, long long n) {
  long long ret = 1;
  for (; n; n >>= 1, x = x * x % MOD)
    if (n & 1) ret = ret * x % MOD;
  return ret;
}
long long n, m, k;
long long cntX, confX, x[MAX_N][2];
long long cntY, confY, y[MAX_N][2];
long long tt[2];
map<long long, long long> G[MAX_N];
long long cal() {
  long long ans = 0;
  if (!confX) ans = (ans + bin(2, n - cntX)) % MOD;
  if (!confY) ans = (ans + bin(2, m - cntY)) % MOD;
  ans = (ans - !tt[0] - !tt[1] + MOD) % MOD;
  return ans;
}
void del(long long xx, long long yy, long long tp) {
  G[xx][yy] = 0;
  tp -= 1;
  if (x[xx][0] && x[xx][1]) confX -= 1;
  x[xx][(yy + tp) & 1] -= 1;
  if (x[xx][0] && x[xx][1]) confX += 1;
  if (!(x[xx][0] + x[xx][1])) cntX -= 1;
  if (y[yy][0] && y[yy][1]) confY -= 1;
  y[yy][(xx + tp) & 1] -= 1;
  if (y[yy][0] && y[yy][1]) confY += 1;
  if (!(y[yy][0] + y[yy][1])) cntY -= 1;
  tt[(xx + yy + tp) & 1] -= 1;
}
void add(long long xx, long long yy, long long tp) {
  G[xx][yy] = tp;
  tp -= 1;
  if (!(x[xx][0] + x[xx][1])) cntX += 1;
  if (x[xx][0] && x[xx][1]) confX -= 1;
  x[xx][(yy + tp) & 1] += 1;
  if (x[xx][0] && x[xx][1]) confX += 1;
  if (!(y[yy][0] + y[yy][1])) cntY += 1;
  if (y[yy][0] && y[yy][1]) confY -= 1;
  y[yy][(xx + tp) & 1] += 1;
  if (y[yy][0] && y[yy][1]) confY += 1;
  tt[(xx + yy + tp) & 1] += 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (long long i = 0; i < k; ++i) {
    long long opt, xx, yy;
    cin >> xx >> yy >> opt;
    long long tp = G[xx][yy];
    if (tp) del(xx, yy, tp);
    if (opt >= 0) add(xx, yy, opt + 1);
    cout << cal() << '\n';
  }
  return 0;
}
