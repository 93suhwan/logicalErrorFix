#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int a[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n);
    long long ans = a[1];
    long long cnt = 0;
    for (int i = 2; i <= n; i++) ans = max(ans, (long long)a[i] - a[i - 1]);
    printf("%lld\n", ans);
  }
  return 0;
}
