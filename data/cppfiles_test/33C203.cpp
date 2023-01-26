#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x, tmp = 0;
    long long ans = -1LL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &x);
      if (i) ans = max(ans, (long long)x * tmp);
      tmp = x;
    }
    printf("%lld\n", ans);
  }
}
