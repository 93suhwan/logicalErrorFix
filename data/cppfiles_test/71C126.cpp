#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long st[10][1 << 10];
void solve() {
  int n, kkk;
  scanf("%d%d", &n, &kkk);
  int x = n, len = 0;
  while (x) x /= 10, len++;
  if (kkk == 1) {
    for (int num = 1; num <= 9; num++) {
      long long sum = 0, cur = 1;
      for (int i = 1; i <= len; i++) sum += num * cur, cur *= 10;
      if (sum >= n) {
        printf("%lld\n", sum);
        return;
      }
    }
  } else {
    long long ans = 1e18;
    for (int num1 = 0; num1 <= 9; num1++)
      for (int num2 = num1; num2 <= 9; num2++)
        for (int s = 0; s < (1 << len); s++) {
          long long sum = st[num1][s] + st[num2][(~s) & ((1 << len) - 1)];
          if (sum >= n) ans = min(ans, sum);
        }
    printf("%lld\n", ans);
  }
}
int main() {
  for (int num = 0; num <= 9; num++)
    for (int s = 0; s < (1 << 10); s++) {
      long long sum = 0, cur = 1;
      for (int i = 1; i <= 10; i++)
        sum += ((s & (1 << (i - 1))) ? num : 0) * cur, cur *= 10;
      st[num][s] = sum;
    }
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}
