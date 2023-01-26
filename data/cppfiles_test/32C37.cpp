#include <bits/stdc++.h>
int *wwu[17 + 1], *wwv[17 + 1], vv[17 + 1];
int ff[100000 + 1], pp2[100000 + 1];
long long power(long long a, int k) {
  long long p = 1;
  while (k) {
    if (k & 1) p = p * a % 998244353;
    a = a * a % 998244353;
    k >>= 1;
  }
  return p;
}
void init() {
  int i, l, u, v;
  ff[0] = 1, pp2[0] = 1;
  for (i = 1; i <= 100000; i++) {
    ff[i] = (long long)ff[i - 1] * i % 998244353;
    pp2[i] = pp2[i - 1] * 2 % 998244353;
  }
  u = power(3, 998244353 - 1 >> 17), v = power(u, 998244353 - 2);
  for (l = 17; l > 0; l--) {
    int n = 1 << l, m = n >> 1, i;
    wwu[l] = (int *)malloc(m * sizeof *wwu[l]),
    wwv[l] = (int *)malloc(m * sizeof *wwv[l]);
    wwu[l][0] = wwv[l][0] = 1;
    for (i = 1; i < m; i++) {
      wwu[l][i] = (long long)wwu[l][i - 1] * u % 998244353;
      wwv[l][i] = (long long)wwv[l][i - 1] * v % 998244353;
    }
    u = (long long)u * u % 998244353, v = (long long)v * v % 998244353;
    vv[l] = power(1 << l, 998244353 - 2);
  }
}
void ntt_(int *aa, int l_, int inverse) {
  if (l_ > 0) {
    int n = 1 << l_, m = n >> 1, *ww = inverse ? wwv[l_] : wwu[l_], i, j;
    ntt_(aa, l_ - 1, inverse), ntt_(aa + m, l_ - 1, inverse);
    for (i = 0; (j = i + m) < n; i++) {
      int a = aa[i], b = (long long)aa[j] * ww[i] % 998244353;
      if ((aa[i] = a + b) >= 998244353) aa[i] -= 998244353;
      if ((aa[j] = a - b) < 0) aa[j] += 998244353;
    }
  }
}
void ntt(int *aa, int l_, int inverse) {
  int n_ = 1 << l_, i, j;
  for (i = 0, j = 1; j < n_; j++) {
    int b = n_ >> 1, tmp;
    while ((i ^= b) < b) b >>= 1;
    if (i < j) tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
  }
  ntt_(aa, l_, inverse);
}
int ***alloc(int n) {
  int ***dp = (int ***)malloc(2 * sizeof *dp);
  int e, f;
  for (e = 0; e < 2; e++) {
    dp[e] = (int **)malloc(2 * sizeof *dp[e]);
    for (f = 0; f < 2; f++) dp[e][f] = (int *)calloc(n, sizeof *dp[e][f]);
  }
  return dp;
}
char single[100000];
int aa[2][2][(1 << 17)], bb[2][2][(1 << 17)], cc[(1 << 17)];
int ***solve(int l, int r) {
  int ***dp = alloc(r - l + 3);
  if (l > r)
    dp[0][0][0] = dp[1][1][1] = 1;
  else {
    int m = (l + r) / 2, ***dpl = solve(l, m - 1), ***dpr = solve(m + 1, r), n_,
        l_, e, f, g, h, i;
    l_ = 0;
    while (1 << l_ < r - l + 3) l_++;
    n_ = 1 << l_;
    for (e = 0; e < 2; e++)
      for (f = 0; f < 2; f++) {
        memset(aa[e][f], 0, n_ * sizeof *aa[e][f]);
        memcpy(aa[e][f], dpl[e][f], (m - l + 2) * sizeof *dpl[e][f]);
        ntt(aa[e][f], l_, 0);
      }
    for (g = 0; g < 2; g++)
      for (h = 0; h < 2; h++) {
        memset(bb[g][h], 0, n_ * sizeof *bb[g][h]);
        memcpy(bb[g][h], dpr[g][h], (r - m + 2) * sizeof *dpr[g][h]);
        ntt(bb[g][h], l_, 0);
      }
    for (e = 0; e < 2; e++)
      for (h = 0; h < 2; h++) {
        memset(cc, 0, n_ * sizeof *cc);
        for (f = 0; f < 2; f++)
          for (g = 0; g < 2; g++)
            for (i = 0; i < n_; i++)
              cc[i] =
                  (cc[i] + (long long)aa[e][f][i] * bb[g][h][i] % 998244353 *
                               (single[m] && f && g ? 499122177 : 1)) %
                  998244353;
        ntt(cc, l_, 1);
        for (i = 0; i < n_; i++) cc[i] = (long long)cc[i] * vv[l_] % 998244353;
        memcpy(dp[e][h], cc, (r - l + 3) * sizeof *cc);
      }
  }
  return dp;
}
int main() {
  static int aa[100000], ***dp;
  int n, n_, h, i, j, k, ans;
  init();
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &aa[i]);
  n_ = 0, i = 0;
  for (i = 0; i < n; i += aa[i]) {
    j = i + aa[i];
    if (j > n) {
      printf("0\n");
      return 0;
    }
    for (h = i; h < j; h++)
      if (aa[h] != aa[i]) {
        printf("0\n");
        return 0;
      }
    single[n_++] = aa[i] == 1;
  }
  n = n_;
  dp = solve(0, n - 1);
  ans = 0;
  for (k = 1; k <= n; k++)
    ans = (ans + (long long)((n - k) % 2 == 0 ? 1 : 998244353 - 1) * ff[k] %
                     998244353 * pp2[k] % 998244353 * dp[1][1][k + 1]) %
          998244353;
  printf("%d\n", ans);
  return 0;
}
