#include <bits/stdc++.h>
using namespace std;
const int N = 105;
long long a[105];
long long n, h;
bool judge(long long x) {
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    ans += min(x, a[i] - a[i - 1]);
  }
  ans += x;
  return ans < h;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    memset(a, 0, sizeof a);
    scanf("%lld%lld", &n, &h);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    long long l = 0, r = 1e18, mid, ans = 0;
    while (l <= r) {
      mid = l + r >> 1;
      if (judge(mid))
        l = mid + 1;
      else
        r = mid - 1;
    }
    cout << l << endl;
    ;
  }
  return 0;
}
