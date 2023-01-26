#include <bits/stdc++.h>
const int N = 4e3 + 3;
int n, m, q[N], lst[N];
char a[N][N];
long long f[N][N];
void solve() {
  memset(lst, 0, sizeof lst);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (a[i][j] == '1') lst[j] = i;
    int l = 1, r = 0;
    for (int j = 1; j <= m; j++) {
      if (lst[j]) {
        while (l < r &&
               (((long long)(q[r]) * (q[r]) +
                 (long long)(lst[q[r]] - i) * (lst[q[r]] - i)) -
                ((long long)(q[r - 1]) * (q[r - 1]) +
                 (long long)(lst[q[r - 1]] - i) * (lst[q[r - 1]] - i))) *
                       ((long long)(j) - (long long)(q[r])) >=
                   (((long long)(j) * (j) +
                     (long long)(lst[j] - i) * (lst[j] - i)) -
                    ((long long)(q[r]) * (q[r]) +
                     (long long)(lst[q[r]] - i) * (lst[q[r]] - i))) *
                       ((long long)(q[r]) - (long long)(q[r - 1])))
          r--;
        q[++r] = j;
      }
      while (l < r && (((long long)(q[l + 1]) * (q[l + 1]) +
                        (long long)(lst[q[l + 1]] - i) * (lst[q[l + 1]] - i)) -
                       ((long long)(q[l]) * (q[l]) +
                        (long long)(lst[q[l]] - i) * (lst[q[l]] - i))) <=
                          ((long long)(q[l + 1]) - (long long)(q[l])) *
                              ((long long)(j)*2))
        l++;
      if (l <= r)
        f[i][j] = std::min(f[i][j],
                           (long long)j * j +
                               ((long long)(q[l]) * (q[l]) +
                                (long long)(lst[q[l]] - i) * (lst[q[l]] - i)) -
                               ((long long)(j)*2) * (long long)(q[l]));
    }
  }
}
int main() {
  scanf("%d%d", &n, &m), n++, m++;
  for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
  memset(f, 0x3f, sizeof f);
  solve();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m / 2; j++)
      std::swap(f[i][j], f[i][m - j + 1]), std::swap(a[i][j], a[i][m - j + 1]);
  solve();
  for (int i = 1; i <= n / 2; i++)
    for (int j = 1; j <= m; j++)
      std::swap(f[i][j], f[n - i + 1][j]), std::swap(a[i][j], a[n - i + 1][j]);
  solve();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m / 2; j++)
      std::swap(f[i][j], f[i][m - j + 1]), std::swap(a[i][j], a[i][m - j + 1]);
  solve();
  long long sum = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) sum += f[i][j];
  printf("%lld\n", sum);
  return 0;
}
