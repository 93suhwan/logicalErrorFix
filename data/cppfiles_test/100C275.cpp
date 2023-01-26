#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long a[200005];
int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ti++) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    if (a[n] == a[n - 1]) {
      long long res = 1;
      for (int i = 1; i <= n; i++) {
        res *= i;
        res %= mod;
      }
      printf("%lld\n", res);
    } else {
      if (a[n] == (a[n - 1] + 1)) {
        long long ans = 1;
        int res = 1;
        for (int j = (n - 1); j >= 1; j--) {
          if (a[j] == a[n - 1]) {
            res++;
          } else {
            break;
          }
        }
        for (int i = 1; i <= n; i++) {
          if (i == res) {
            ans *= (i - 1);
            ans %= mod;
            continue;
          }
          ans *= i;
          ans %= mod;
        }
        printf("%lld\n", ans);
      } else {
        printf("0\n");
      }
    }
  }
  return 0;
}
