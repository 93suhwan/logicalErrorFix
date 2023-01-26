#include <bits/stdc++.h>
using namespace std;
int T;
long long n, m, k;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld%d", &n, &m, &k);
    k -= 2;
    long long limit = n * (n - 1) / 2;
    if (k <= 0) {
      printf("NO\n");
      continue;
    }
    if (k == 1) {
      if (m < limit)
        printf("NO\n");
      else
        printf("YES\n");
    } else {
      if (m >= n - 1)
        printf("YES\n");
      else
        printf("NO\n");
    }
  }
}
