#include <bits/stdc++.h>
using namespace std;
int t, n;
long long a[200005], ans;
int main() {
  scanf("%d", &t);
  while (t--) {
    ans = -1000000000000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    if (n == 1) {
      printf("%lld\n", a[0]);
      continue;
    }
    sort(a, a + n);
    long long temp = 0;
    for (int i = 0; i < n; i++) {
      ans = max(a[i] - temp, ans);
      temp += (a[i] - temp);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
