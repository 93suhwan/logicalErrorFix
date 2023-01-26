#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T, n;
int a[N], b[N];
int numa[N], numb[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    memset(numa, 0, sizeof(int) * (n + 2));
    memset(numb, 0, sizeof(int) * (n + 2));
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      numa[a[i]]++;
      scanf("%d", &b[i]);
      numb[b[i]]++;
    }
    long long ans = (long long)n * (n - 1) * (n - 2) / 6;
    for (int i = 1; i <= n; ++i) {
      ans -= (long long)(numa[a[i]] - 1) * (numb[b[i]] - 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
