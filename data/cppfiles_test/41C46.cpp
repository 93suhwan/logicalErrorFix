#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int s[1005][1005];
void color(int l, int r, int now) {
  if (l >= r) return;
  ans = max(ans, now);
  int Size = (r - l + 1) / k;
  if ((r - l + 1) % k != 0) {
    Size++;
  }
  for (int i = l; i <= r; i += Size) {
    for (int j = i; j <= min(r, i + Size - 1); ++j) {
      for (int k = min(r, i + Size - 1); k <= r; ++k) {
        s[j][k] = now;
      }
    }
    color(i, min(r, i + Size - 1), now + 1);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  color(1, n, 1);
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      printf("%d ", s[i][j]);
    }
  }
  return 0;
}
