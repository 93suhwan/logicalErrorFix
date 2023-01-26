#include <bits/stdc++.h>
int n = 1e5, k, cnt, p[100010], np[100010], sq[100010];
long long phi[100010], f[20][100010], s1[100010][320], s2[100010][320];
long long c(int l, int r) {
  if (l > r) return 1e16;
  if (r / l <= sq[r])
    return s1[r][r / l] - phi[r / l] * (l - 1 - r / (r / l + 1));
  else
    return s2[r][l];
}
void solve(long long *g, long long *f, int l, int r, int pl, int pr) {
  if (l > r) return;
  int p = 0, mid = (l + r) >> 1;
  f[mid] = 1e16;
  for (int i = pl; i <= pr; i++)
    if (g[i] + c(i + 1, mid) < f[mid]) p = i, f[mid] = g[i] + c(i + 1, mid);
  solve(g, f, l, mid - 1, pl, p), solve(g, f, mid + 1, r, p, pr);
}
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  phi[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) p[++cnt] = i, phi[i] = i - 1;
    for (int j = 1; j <= cnt && i * p[j] <= n; j++) {
      np[i * p[j]] = 1;
      if (i % p[j] == 0) {
        phi[i * p[j]] = phi[i] * p[j];
        break;
      }
      phi[i * p[j]] = phi[i] * phi[p[j]];
    }
  }
  for (int i = 1; i <= n; i++) phi[i] += phi[i - 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j <= i; j++) {
      s1[i][j] = s1[i][j - 1] + phi[j] * (i / j - i / (j + 1));
      sq[i] = j;
    }
    s2[i][i / (sq[i] + 1) + 1] = s1[i][sq[i]];
    for (int j = i / (sq[i] + 1); j; j--) {
      s2[i][j] = s2[i][j + 1] + phi[i / j];
    }
  }
  for (int i = 1; i <= n; i++) f[1][i] = c(1, i);
  for (int i = 2; i <= 17; i++) solve(f[i - 1], f[i], 1, n, 1, n);
  int T;
  std::cin >> T;
  while (T--) {
    scanf("%d%d", &n, &k);
    if (k > 17)
      printf("%d\n", n);
    else
      printf("%lld\n", f[k][n]);
  }
  return 0;
}
