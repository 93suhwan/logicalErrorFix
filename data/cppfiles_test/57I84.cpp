#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long s, n, k, m;
    scanf("%lld%lld%lld", &s, &n, &k);
    if (k > s) {
      printf("NO\n");
      continue;
    }
    s++;
    long long t = s / k;
    if (t % 2 == 0)
      m = t / 2 * k + s % k;
    else
      m = (t + 1) / 2 * k;
    m--;
    if (m >= n)
      printf("NO\n");
    else
      printf("YES\n");
  }
}
