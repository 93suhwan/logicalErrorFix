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
  int blo = (r - l + 1) / k, cnt = 0;
  for (int i = l; i <= r; i += blo, cnt++) {
    if (cnt + 1 == k) {
      solve(i, r, k, id + 1);
      for (int j = l; j < i; j++)
        for (int a = i; a <= r; a++) g[j][a] = id;
      break;
    } else {
      solve(i, i + blo - 1, k, id + 1);
      for (int j = l; j < i; j++)
        for (int a = i; a < i + blo; a++) g[j][a] = id;
    }
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
