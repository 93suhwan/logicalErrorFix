#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int t, n;
long long a[maxn + 10];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int i = 0;
    long long add = a[1], ans = a[1];
    for (i = 2; i <= n; ++i) {
      if ((a[i] - add) > ans) {
        ans = a[i] - add;
      }
      add = a[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
