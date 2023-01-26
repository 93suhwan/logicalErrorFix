#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long q, phi[100010], s1[100010][400], s2[100010][400], root[100010],
    dp[100010][30];
long long getPhi(long long i) {
  long long ret = i;
  for (long long j = 2; j * j <= i; ++j)
    if (i % j == 0) {
      ret = ret / j * (j - 1);
      while (i % j == 0) i /= j;
    }
  if (i > 1) ret = ret / i * (i - 1);
  return ret;
}
long long getC(long long lb, long long ub) {
  if (lb > ub) return 1e18;
  if (ub / lb <= root[ub])
    return s1[ub][ub / lb] - phi[ub / lb] * (lb - 1 - ub / (ub / lb + 1));
  return s2[ub][lb];
}
bool ss = false;
void solve(long long lb, long long ub, long long tlb, long long tub,
           long long lev) {
  if (lb > ub) return;
  tlb = max(tlb, 1LL);
  long long mid = (lb + ub) / 2, opt = -1, val = 1e18;
  for (int i = tlb; i < min(mid, tub + 1); ++i) {
    long long tr = dp[i][lev - 1] + getC(i + 1, mid);
    if (tr < val) val = tr, opt = i;
  }
  if (opt > -1) dp[mid][lev] = val;
  solve(lb, mid - 1, tlb, opt, lev);
  solve(mid + 1, ub, opt, tub, lev);
}
int main() {
  for (int i = 1; i <= 100000; ++i) phi[i] = getPhi(i);
  for (int i = 1; i <= 99999; ++i) phi[i + 1] += phi[i];
  for (int i = 1; i <= 100005; ++i) {
    for (int j = 1; j * j <= i; ++j) {
      s1[i][j] = s1[i][j - 1] + phi[j] * (i / j - i / (j + 1));
      root[i] = j;
    }
    s2[i][i / (root[i] + 1) + 1] = s1[i][root[i]];
    for (int j = i / (root[i] + 1); j > 0; --j)
      s2[i][j] = s2[i][j + 1] + phi[i / j];
  }
  for (int i = 0; i < 100005; ++i)
    for (int j = 0; j < 25; ++j) dp[i][j] = 1e18;
  for (int i = 1; i <= 100003; ++i) dp[i][1] = getC(1, i);
  for (int i = 2; i <= 17; ++i) solve(1, 100000, 1, 100000, i);
  cin >> q;
  long long x, y;
  for (int qn = 0; qn < q; ++qn) {
    scanf("%lld%lld", &x, &y);
    if (y > 17)
      puts("0");
    else
      printf("%lld\n", dp[x][y]);
  }
  return 0;
}
