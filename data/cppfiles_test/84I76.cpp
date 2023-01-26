#include <bits/stdc++.h>
using namespace std;
int b[500010], pr[500010], phi[500010], sz;
long long sp[500010];
void init() {
  phi[1] = 1;
  for (int i = 2; i <= 100000; i++) {
    if (!b[i]) {
      phi[i] = i - 1;
      pr[++sz] = i;
    }
    for (int j = 1; j <= sz && pr[j] * i <= 100000; j++) {
      b[pr[j] * i] = 1;
      phi[pr[j] * i] = phi[pr[j]] * phi[i];
      if (i % pr[j] == 0) {
        int tmp = i, c = pr[j];
        while (tmp % pr[j] == 0) {
          tmp /= pr[j];
          c *= pr[j];
        }
        phi[i * pr[j]] = phi[tmp] * (c - c / pr[j]);
        break;
      }
    }
  }
  for (int i = 1; i <= 100000; i++) sp[i] = sp[i - 1] + 1ll * phi[i];
}
int dp[21][500010];
void work(int fl, int l, int r, int al, int ar) {
  if (al > ar) return;
  int mid = (al + ar) >> 1, p = l, lim = min(mid, r);
  long long val = 0;
  for (int i = l, j; i <= mid; i = j + 1) {
    j = mid / (mid / i);
    val += 1ll * (j - i + 1) * sp[mid / i];
  }
  dp[fl][mid] = dp[fl - 1][l - 1] + val;
  for (int i = l; i <= lim; i++) {
    val = val - sp[mid / i];
    int now = dp[fl - 1][i] + val;
    if (now <= dp[fl][mid]) {
      dp[fl][mid] = now;
      p = i;
    }
  }
  work(fl, l, p, al, mid - 1);
  work(fl, p, r, mid + 1, ar);
}
int inf = 1e9;
void init_dp() {
  init();
  int n = 100000;
  for (int fl = 1; fl < 20; fl++)
    for (int i = 1; i <= n; i++) dp[fl][i] = inf;
  for (int i = 1; i <= n; i++) dp[1][i] = 1ll * i * (i + 1) / 2;
  for (int fl = 2; fl < 20; fl++) work(fl, 1, n, fl, n);
}
int main() {
  int T, n, k;
  init_dp();
  scanf("%d", &T);
  while (T--) {
    long long ans = 0;
    scanf("%d%d", &n, &k);
    if (k >= 20) {
      printf("%d\n", n);
      continue;
    }
    printf("%lld\n", dp[k][n]);
  }
}
