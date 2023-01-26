#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
long long a[N], SUM[N];
void solve() {
  int n, m;
  long long sum = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), sum += a[i];
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; ++i) SUM[i] = SUM[i - 1] + a[i];
  scanf("%d", &m);
  while (m--) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    int res = lower_bound(SUM + 1, SUM + 1 + n, y) - SUM;
    long long ans1 = sum - SUM[res];
    long long ans2 = y - SUM[res - 1];
    ans2 += x - (SUM[res] - SUM[res - 1]);
    ans1 = x - ans1;
    if (ans1 <= 0) ans1 = 0;
    if (ans2 <= 0) ans2 = 0;
    printf("%lld\n", min(ans1, ans2));
  }
}
int main() {
  solve();
  return 0;
}
