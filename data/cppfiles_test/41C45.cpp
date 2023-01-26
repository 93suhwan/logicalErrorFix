#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
namespace ywy {
inline long long get() {
  long long n = 0;
  char c;
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9') break;
    if (c == '-') goto s;
  }
  n = c - '0';
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 + c - '0';
    else
      return (n);
  }
s:
  while ((c = getchar()) || 23333) {
    if (c >= '0' && c <= '9')
      n = n * 10 - c + '0';
    else
      return (n);
  }
}
int g[1100][1100], mx = 1;
void solve(int l, int r, int k, int id) {
  if (l != r) mx = max(mx, id);
  if (r - l + 1 <= k) {
    for (int i = l; i <= r; i++)
      for (int j = i + 1; j <= r; j++) g[i][j] = id;
    return;
  }
  int blo = (r - l + 1) / k, cnt = 0, cur = l;
  for (int i = 0; i < (r - l + 1) - blo * k; i++, cur += blo + 1) {
    solve(cur, cur + blo, k, id + 1);
    for (int a = l; a < cur; a++)
      for (int b = cur; b <= cur + blo; b++) g[a][b] = id;
  }
  for (; cur <= r; cur += blo) {
    solve(cur, cur + blo - 1, k, id + 1);
    for (int a = l; a < cur; a++)
      for (int b = cur; b <= cur + blo - 1; b++) g[a][b] = id;
  }
}
void ywymain() {
  int n = get(), k = get();
  solve(1, n, k, 1);
  printf("%d\n", mx);
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) printf("%d ", g[i][j]);
}
}  // namespace ywy
signed main() {
  ywy::ywymain();
  return 0;
}
