#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, c, m, minn, maxn, midn;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &m);
    if (a + b + c - 3 >= m) {
      maxn = max(a, max(b, c));
      if (maxn - m * 2ll < 0 || a + b + c - maxn >= m + maxn - m * 2ll + 1)
        printf("YES\n");
      else
        printf("NO\n");
    } else
      printf("NO\n");
  }
  return 0;
}
