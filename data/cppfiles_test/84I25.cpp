#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, T, p[N], pcnt, f[N];
long long phi[N], dp[20][N];
inline void init(int n) {
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!f[i]) p[++pcnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= pcnt && i * p[j] <= n; ++j) {
      int num = i * p[j];
      f[num] = 1;
      if (i % p[j])
        phi[num] = phi[i] * phi[p[j]];
      else {
        phi[num] = phi[i] * p[j];
        break;
      }
    }
  }
  for (int i = 2; i <= n; ++i) phi[i] += phi[i - 1];
}
inline long long calc(int l, int r) {
  long long ret = 0;
  for (int x = l, y = 0; x <= r; x = y + 1) {
    y = r / (r / x);
    ret += phi[r / x] * (y - x + 1);
  }
  return ret;
}
inline void solve(int x, int l, int r, int ql, int qr) {
  if (l > r) return;
  int mid = (l + r) >> 1, now = calc(min(qr + 1, mid), mid), pos = ql;
  dp[x][mid] = 1e15;
  for (int i = min(qr, mid - 1); i >= ql; --i) {
    if (dp[x - 1][i] + now < dp[x][mid])
      dp[x][mid] = dp[x - 1][i] + now, pos = i;
    now += phi[mid / i];
  }
  solve(x, l, mid - 1, ql, pos);
  solve(x, mid + 1, r, pos, qr);
}
int main() {
  n = 100000;
  init(n);
  for (int i = 1; i <= n; ++i) dp[1][i] = 1ll * i * (i + 1) / 2;
  for (int i = 2; (1 << i) <= n; ++i) solve(i, i, n, 1, n);
  scanf("%d", &T);
  while (T--) {
    int k;
    scanf("%d%d", &n, &k);
    if (k >= 20 || (1 << k) > n) {
      printf("%d\n", n);
      continue;
    } else
      printf("%d\n", dp[k][n]);
  }
  return 0;
}
