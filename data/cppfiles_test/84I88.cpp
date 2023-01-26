#include <bits/stdc++.h>
using namespace std;
void die(string S) {
  puts(S.c_str());
  exit(0);
}
const int bound = 1e5;
const int Sqrt = 320;
const int Log = 21;
bool isp[bound + 10];
int phi[bound + 10];
long long g[bound + 10];
long long dp[Log][bound + 10];
long long C;
inline long long h(int k, int l, int r) { return dp[k - 1][l - 1] + C; }
void dfs(int level, int l, int r, int optl, int optr) {
  if (l > r) return;
  int mid = (l + r) / 2;
  int opt = min(mid, optr);
  C = 0;
  if (optr < mid) {
    for (int l_ = optr + 1, rr; l_ <= mid; l_ = rr + 1) {
      rr = mid / (mid / l_);
      C += g[mid / l_] * (rr - l_ + 1);
    }
  }
  for (int i = opt; i >= optl; i--) {
    C += g[mid / i];
    if (h(level, i, mid) <= dp[level][mid]) {
      opt = i;
      dp[level][mid] = h(level, opt, mid);
    }
  }
  dfs(level, l, mid - 1, optl, opt);
  dfs(level, mid + 1, r, opt, optr);
  return;
}
void solve() {
  memset(isp, 1, sizeof(isp));
  isp[0] = isp[1] = 0;
  for (int i = 2; i <= Sqrt; i++)
    if (isp[i])
      for (int j = i * i; j <= bound; j += i) isp[j] = 0;
  for (int i = 2; i <= bound; i++) phi[i] = i;
  for (int i = 2; i <= bound; i++)
    if (isp[i])
      for (int j = i; j <= bound; j += i) phi[j] /= i, phi[j] *= (i - 1);
  for (int i = 2; i <= bound; i++) g[i] = g[i - 1] + phi[i];
  for (int i = 0; i < Log; i++)
    for (int j = 0; j < bound; j++) dp[i][j] = 1ll * 0x3f3f3f3f * 0x3f3f3f3f;
  dp[0][0] = 0;
  for (int i = 1; i < Log; i++) dfs(i, 1, bound, 1, bound);
  return;
}
int main() {
  solve();
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%lld\n", dp[k][n] + n);
  }
  return 0;
}
