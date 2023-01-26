#include <bits/stdc++.h>
using namespace std;
int T;
int n, m;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    if (m < n) {
      printf("0\n");
    } else if (n == 0) {
      printf("%d\n", m + 1);
    } else {
      long long ans = (1ll << 32) - 1;
      for (int i = 31; i >= 0; --i) {
        if ((n & (1ll << i)) == 0 && (ans - (1ll << i)) > m) ans -= (1ll << i);
      }
      printf("%lld\n", n ^ ans);
    }
  }
  return 0;
}
