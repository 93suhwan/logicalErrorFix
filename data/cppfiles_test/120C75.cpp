#include <bits/stdc++.h>
using namespace std;
int mi[30];
int ans, l, r, T;
int get(int x, int t) {
  int ans;
  t = mi[t];
  ans = (x / t / 2) * t;
  x = x % (t * 2);
  if (x >= t) ans += x - t + 1;
  return ans;
}
int main() {
  mi[0] = 1;
  for (int i = 1; i <= 20; i++) mi[i] = mi[i - 1] * 2;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; tt++) {
    ans = 0;
    scanf("%d%d", &l, &r);
    for (int i = 0; i <= 19; i++) {
      ans = max(ans, get(r, i) - get(l - 1, i));
    }
    printf("%d\n", r - l + 1 - ans);
  }
}
