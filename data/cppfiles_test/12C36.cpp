#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int las[N], rk[N], rb[N], n, m, ans[N][N];
char mp[N][N];
double head[N];
void solve() {
  for (int j = 0; j <= m; j++) las[j] = -1;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++)
      if (mp[i][j] == '1') las[j] = i;
    int end = 0;
    for (int j = 0; j <= m; j++)
      if (~las[j]) {
        int b = j * j + (las[j] - i) * (las[j] - i), k = -2 * j;
        while (end && head[end] * k + b <= head[end] * rk[end] + rb[end]) --end;
        if (!end)
          head[++end] = 0, rk[end] = k, rb[end] = b;
        else {
          double x = 1.0 * (b - rb[end]) / (rk[end] - k);
          head[++end] = x, rk[end] = k, rb[end] = b;
        }
      }
    if (end)
      for (int j = 0, pos = 1; j <= m; j++) {
        while (pos < end && head[pos + 1] <= j) ++pos;
        ans[i][j] = min(ans[i][j], rk[pos] * j + rb[pos] + j * j);
      }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i <= n; i++) scanf("%s", mp[i]);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) ans[i][j] = 1e9;
  solve();
  for (int i = 0; i <= n / 2; i++)
    for (int j = 0; j <= m; j++)
      swap(mp[i][j], mp[n - i][j]), swap(ans[i][j], ans[n - i][j]);
  solve();
  long long A = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) A += ans[i][j];
  printf("%lld", A);
  return 0;
}
