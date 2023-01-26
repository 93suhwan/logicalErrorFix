#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int e[1015][1015];
void solve(int s, int en, int d) {
  ans = max(ans, d);
  if (en - s + 1 <= k) {
    for (int i = s; i <= en; ++i) {
      for (int j = i + 1; j <= en; ++j) {
        e[i][j] = d;
      }
    }
    return;
  }
  int l = (en - s + 1) / k + !!((en - s + 1) % k);
  for (int i = s; i <= en; i += l) {
    solve(i, min(en, i + l - 1), d + 1);
    for (int j = i + l; j <= en; ++j) {
      for (int k = i; k < i + l; ++k) {
        e[k][j] = d;
      }
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  solve(1, n, 1);
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      printf("%d ", e[i][j]);
    }
  }
  return 0;
}
