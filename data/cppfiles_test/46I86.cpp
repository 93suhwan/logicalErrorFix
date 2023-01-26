#include <bits/stdc++.h>
using namespace std;
int n;
int a[100086];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  long long ans = 0;
  for (int i = 1; i < n; i += 2) {
    long long sum = 0, mn = 1e18;
    for (int j = i + 1; j <= n; j += 2) {
      int ans1 = ans;
      ans += max(0ll, min(1ll * a[i], a[j] - sum) - max(-mn, 1 - sum) + 1);
      mn = min(mn, sum - a[j]);
      sum += -a[j] + a[j + 1];
      if (ans - ans1) cout << i - 1 << " " << j - 1 << " " << ans << endl;
    }
  }
  printf("%lld", ans);
}
