#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int T, n, arr[maxn];
long long k, sum, ans;
int main() {
  scanf("%d", &T);
  while (T--) {
    sum = 0;
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
      sum += arr[i];
    }
    if (sum <= k) {
      printf("0\n");
      continue;
    }
    if (n == 1) {
      printf("%lld\n", arr[0] - k);
      continue;
    }
    sort(arr, arr + n, greater<int>());
    for (int i = 0; i < n; i++) arr[i] -= arr[n - 1];
    ans = 1ll << 60;
    for (int i = 0; i < n - 1; i++) {
      sum -= arr[i];
      if (sum <= k) {
        ans = min(ans, i + 1ll);
      }
      ans = min(ans, i + 1 + (sum - k + i + 1) / (i + 2));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
