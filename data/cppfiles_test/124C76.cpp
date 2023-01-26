#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, mod = 1000000007;
const double pi = 3.1415926535897932, eps = 1e-6;
void chmax(int &x, int y) {
  if (x < y) x = y;
}
void chmin(int &x, int y) {
  if (x > y) x = y;
}
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)ret * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return ret;
}
int n, T;
char s[2005], t[2005];
int dp[2005][2005], sum[2005][2005], sumd[2005][2005], sums[2005][2005];
int pres[2005], pret[2005];
int getsumd(int l1, int r1, int l2, int r2) {
  return ((long long)sumd[l2][r2] - (l1 ? sumd[l1 - 1][r2] : 0) -
          (r1 ? sumd[l2][r1 - 1] : 0) +
          ((l1 && r1) ? sumd[l1 - 1][r1 - 1] : 0) + mod + mod) %
         mod;
}
int getsums(int l1, int r1, int l2, int r2) {
  return ((long long)sums[l2][r2] - (l1 ? sums[l1 - 1][r2] : 0) -
          (r1 ? sums[l2][r1 - 1] : 0) +
          ((l1 && r1) ? sums[l1 - 1][r1 - 1] : 0) + mod + mod) %
         mod;
}
void solve() {
  for (int(i) = (0); (i) <= (n); (i)++)
    for (int(j) = (0); (j) <= (n); (j)++)
      dp[i][j] = sum[i][j] = sumd[i][j] = sums[i][j] = 0;
  scanf("%d%s%s", &n, s + 1, t + 1);
  for (int(i) = (1); (i) <= (n); (i)++)
    if (i % 2 == 0) {
      if (isdigit(s[i])) s[i] = 97 - s[i];
      if (isdigit(t[i])) t[i] = 97 - t[i];
    }
  for (int(i) = (1); (i) <= (n + 1); (i)++) {
    pres[i] = pres[i - 1];
    if (s[i - 1] == '1') pres[i] = i - 1;
    pret[i] = pret[i - 1];
    if (t[i - 1] == '1') pret[i] = i - 1;
  }
  dp[0][0] = 1;
  for (int(i) = (0); (i) <= (n); (i)++) sumd[i][0] = sumd[0][i] = 1;
  for (int(i) = (1); (i) <= (n); (i)++)
    for (int(j) = (1); (j) <= (n); (j)++) {
      int k = i - 1;
      if (s[i] != '0' && t[j] != '0') {
        dp[i][j] = getsumd(pres[i], pret[j], i - 1, j - 1);
        sum[i][j] = getsums(pres[i], pret[j], i - 1, j - 1);
        sum[i][j] += (long long)dp[i][j] * abs(i - j) % mod;
        if (sum[i][j] >= mod) sum[i][j] -= mod;
      }
      sumd[i][j] = ((long long)sumd[i - 1][j] + sumd[i][j - 1] -
                    sumd[i - 1][j - 1] + mod + dp[i][j]) %
                   mod;
      sums[i][j] = ((long long)sums[i - 1][j] + sums[i][j - 1] -
                    sums[i - 1][j - 1] + mod + sum[i][j]) %
                   mod;
    }
  int ans = getsums(pres[n + 1], pret[n + 1], n, n);
  printf("%d\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
