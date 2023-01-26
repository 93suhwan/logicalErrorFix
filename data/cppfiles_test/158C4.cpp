#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int MAXN = 11;
const int MAXM = 1e4 + 5;
int n, m, ex[MAXN];
int cnt[30];
char w[MAXN][MAXM];
void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &ex[i]);
  for (int i = 0; i < n; i++) scanf("%s", w[i]);
  LL ans = 0;
  int pos;
  for (int i = 0; i < (1 << n); i++) {
    for (int j = 0; j <= 20; j++) cnt[j] = 0;
    for (int j = 0; j < m; j++) {
      int x[2] = {0, 0};
      for (int k = 0; k < n; k++)
        if (w[k][j] == '1') x[((1 << k) & i) != 0]++;
      cnt[x[1] - x[0] + 10]++;
    }
    int mm = m;
    LL sum = 0;
    for (int j = 0; j < n; j++)
      if (((1 << j) & i) == 0)
        sum += ex[j];
      else
        sum -= ex[j];
    for (int j = 20; j >= 0; j--) {
      sum += 1ll * (j - 10) * (2 * mm - cnt[j] + 1) * cnt[j] / 2;
      mm -= cnt[j];
    }
    if (sum >= ans) ans = sum, pos = i;
  }
  {
    for (int j = 0; j <= 20; j++) cnt[j] = 0;
    for (int j = 0; j < m; j++) {
      int x[2] = {0, 0};
      for (int k = 0; k < n; k++)
        if (w[k][j] == '1') x[((1 << k) & pos) != 0]++;
      cnt[x[1] - x[0] + 10]++;
    }
    for (int j = 1; j <= 20; j++) cnt[j] += cnt[j - 1];
    for (int j = 0; j < m; j++) {
      int x[2] = {0, 0};
      for (int k = 0; k < n; k++)
        if (w[k][j] == '1') x[((1 << k) & pos) != 0]++;
      printf("%d ", cnt[x[1] - x[0] + 10]);
      cnt[x[1] - x[0] + 10]--;
    }
    printf("\n");
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    solve();
  }
  return 0;
}
