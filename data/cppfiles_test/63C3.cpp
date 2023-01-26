#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 22, MAXM = 4e5 + 10, INF = 1e16;
int n, len[MAXN], sum[MAXN][MAXM], pre[MAXN][MAXM];
long long f[(1 << 20) + 5], ans;
char s[MAXN][MAXM];
vector<int> occ[MAXN][MAXM];
void update(int i, int s, int j) {
  int L = 1, R = len[j], pos = 1e9, ret = 0;
  while (L <= R) {
    int mid = (L + R) >> 1;
    if (pre[j][mid] < -s) {
      pos = mid;
      R = mid - 1;
    } else {
      L = mid + 1;
    }
  }
  ret =
      lower_bound(occ[j][s].begin(), occ[j][s].end(), pos) - occ[j][s].begin();
  ans = max(ans, f[i] + ret);
  if (pos == 1e9)
    f[i | (1 << (j - 1))] = max(f[i | (1 << (j - 1))], f[i] + ret);
}
void dp() {
  for (int i = (0); i <= ((1 << n) - 1); i++) {
    int s = 0;
    for (int j = (0); j <= (n - 1); j++)
      if ((i >> j) & 1) s += sum[j + 1][len[j + 1]];
    if (s < 0) continue;
    for (int j = (0); j <= (n - 1); j++)
      if (!((i >> j) & 1)) update(i, s, j + 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) {
    scanf("%s", s[i] + 1);
    len[i] = strlen(s[i] + 1);
  }
  for (int i = (1); i <= (n); i++) {
    pre[i][0] = 1e9;
    for (int j = (1); j <= (len[i]); j++) {
      sum[i][j] = sum[i][j - 1];
      if (s[i][j] == '(')
        sum[i][j]++;
      else
        sum[i][j]--;
      pre[i][j] = min(pre[i][j - 1], sum[i][j]);
    }
    for (int j = (1); j <= (len[i]); j++) {
      if (sum[i][j] <= 0) occ[i][-sum[i][j]].push_back(j);
    }
  }
  for (int i = (1); i <= ((1 << n) - 1); i++) f[i] = -INF;
  ans = 0;
  dp();
  for (int i = (1); i <= ((1 << n) - 1); i++) ans = max(ans, f[i]);
  printf("%lld", ans);
  return 0;
}
