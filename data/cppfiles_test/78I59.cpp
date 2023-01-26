#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6, mo = 1e9 + 7;
int cnt[34], n;
inline int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }
inline void work() {
  memset(cnt, 0, sizeof cnt);
  scanf("%d", &n);
  for (register int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    for (register int j = 1; j <= 30; ++j) {
      if (x >> (j - 1) & 1) {
        cnt[j]++;
      }
    }
  }
  int gg = 0;
  for (register int i = 1, flag = 0; i <= 30; ++i) {
    if (cnt[i] && !flag) {
      gg = cnt[i];
      flag = 1;
      continue;
    }
    if (cnt[i] && flag) {
      gg = gcd(gg, cnt[i]);
    }
  }
  for (register int i = 1; i <= gg; ++i) {
    if (gg % i == 0) {
      printf("%d ", i);
    }
  }
  puts("");
}
signed main() {
  int T;
  scanf("%d", &T);
  while (T--) work();
  return 0;
}
