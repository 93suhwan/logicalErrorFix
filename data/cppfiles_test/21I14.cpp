#include <bits/stdc++.h>
using namespace std;
int n, m, k, mo, f[105][105][105], c[105][105], mi[105], d[105];
int calc(int o, int p) {
  int yu = 0, d = 0;
  while (o > 1) {
    yu += o;
    d++;
    o = (o + 1) / 2;
  }
  return yu + p - d;
}
int dfs(int n1, int deep, int sum) {
  if (deep > 0) {
    if (sum == 0) {
      if ((mi[deep - 1] - 1) < n1) return 0;
    } else {
      if ((mi[deep - 1] < sum) || (calc(sum, deep) > n1)) return 0;
    }
    if (n1 <= 1) return 1;
    if (f[n1][deep][sum]) return f[n1][deep][sum];
  } else {
    if (sum > 0) return 0;
    return d[n1];
  }
  int yu = 0, sum1 = sum;
  if (deep == 1) sum--;
  for (int i = 0; i < n1; i++)
    for (int j = 0; j <= sum; j++)
      yu =
          (yu + 1ll * dfs(i, deep - 1, j) * dfs(n1 - i - 1, deep - 1, sum - j) %
                    mo * c[n1 - 1][i] % mo) %
          mo;
  if (deep > 0) f[n1][deep][sum1] = yu;
  return yu;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &mo);
  mi[0] = 1;
  for (int i = 1; i <= 100; i++) mi[i] = mi[i - 1] * 2 % mo;
  for (int i = 0; i <= 100; i++) c[i][0] = 1;
  for (int i = 1; i <= 100; i++)
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mo;
  d[1] = d[0] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 0; j < i; j++)
      d[i] = (d[i] + 1ll * d[j] * d[i - j - 1] % mo * c[i - 1][j] % mo) % mo;
  printf("%d\n", dfs(n, m, k));
  return 0;
}
