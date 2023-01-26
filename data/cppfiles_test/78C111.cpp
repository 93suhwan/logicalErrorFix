#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int p, f[50], flag, ans, ys[N];
int T, n, m, a[N];
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    flag = 1;
    memset(f, 0, sizeof f);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
      if (a[i] != 0) flag = 0;
      int t = 1;
      while (a[i]) {
        if (a[i] & 1) f[t]++;
        a[i] >>= 1;
        t++;
      }
    }
    if (flag) {
      for (int i = 1; i <= n; i++) printf("%d ", i);
      printf("\n");
    } else {
      ans = f[1];
      for (int i = 2; i < 50; i++) ans = gcd(ans, f[i]);
      for (int i = 1; i <= ans; i++)
        if (ans % i == 0) printf("%d ", i);
      printf("\n");
    }
  }
}
