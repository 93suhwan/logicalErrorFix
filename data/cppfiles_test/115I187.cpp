#include <bits/stdc++.h>
using namespace std;
const int N = 105;
long long a[105];
long long n, h;
bool judge(long long x) {
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] - a[i - 1] + 1 > x) {
      ans += x;
    } else {
      ans += (a[i] - a[i - 1]);
    }
    if (ans > h) break;
  }
  if (ans < h) return true;
  return false;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(a, 0, sizeof a);
    scanf("%lld%lld", &n, &h);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    a[n] = 1e18;
    long long l = 0, r = 1e18, mid, ans = 0;
    while (l < r) {
      mid = l + r + 1 >> 1;
      if (judge(mid)) {
        l = mid;
        ans = mid;
      } else
        r = mid - 1;
    }
    cout << ans + 1 << endl;
    ;
  }
  return 0;
}
