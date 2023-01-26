#include <bits/stdc++.h>
using namespace std;
int a[205000], b[200500];
long long int p[200500] = {}, q[200500] = {}, r[200500] = {}, sum[205000] = {},
              sumsq[200500] = {};
int main() {
  int tc;
  scanf("%d", &tc);
  for (int t = 1; t <= tc; t++) {
    long long int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
      p[i] = 0;
      q[i] = 0;
      r[i] = 0;
      sum[i] = 0;
      sumsq[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      scanf("%d %d", &a[i], &b[i]);
      p[a[i]]++;
      q[b[i]]++;
    }
    long long int ans = n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; i++) {
      ans -= (p[a[i]] - 1) * (q[b[i]] - 1);
    }
    printf("%lld\n", ans);
  }
}
