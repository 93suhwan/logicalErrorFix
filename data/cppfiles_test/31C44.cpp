#include <bits/stdc++.h>
using namespace std;
int cnt[(1 << 19)], mn[(1 << 19)], mx[(1 << 19)], ans[(1 << 19)];
void solve(int L, int R) {
  if (L + 1 == R) {
    ans[L] = 0x3f3f3f3f;
    mn[L] = cnt[L] ? 0 : 0x3f3f3f3f;
    mx[L] = cnt[L] ? 0 : -0x3f3f3f3f;
  } else {
    int M = (L + R) / 2, i, H = M - L;
    solve(L, M), solve(M, R);
    for (i = L; i < M; ++i) {
      int mn1 = mn[i], mx1 = mx[i], ans1 = ans[i], mn2 = mn[i + H],
          mx2 = mx[i + H], ans2 = ans[i + H];
      mn[i] = min(mn1, mn2 + H);
      mx[i] = max(mx1, mx2 + H);
      ans[i] = min({ans1, ans2, mn2 + H - mx1});
      mn[i + H] = min(mn2, mn1 + H);
      mx[i + H] = max(mx2, mx1 + H);
      ans[i + H] = min({ans1, ans2, mn1 + H - mx2});
    }
  }
}
int main() {
  int n, k, i;
  scanf("%d%d", &n, &k);
  while (n--) {
    scanf("%d", &i);
    ++cnt[i];
  }
  solve(0, 1 << k);
  for (i = 0; i < (1 << k); ++i) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
