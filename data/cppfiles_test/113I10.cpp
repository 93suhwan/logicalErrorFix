#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, m;
long long a[N];
int main() {
  cin >> n;
  long long maxv = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) maxv += a[i];
  sort(a, a + n + 1);
  cin >> m;
  while (m--) {
    long long ans = 0x3f3f3f3f;
    long long x, y;
    cin >> x >> y;
    if (a[n] < x) {
      ans = min(ans, x - a[n] + max((long long)0, y + a[n] - maxv));
      cout << ans << endl;
    } else {
      long long *t1 = lower_bound(a + 1, a + n, x);
      long long *t2 = lower_bound(a + 1, a + n, x) - 1;
      if (maxv - *t1 - y > 0) {
        cout << 0 << endl;
        continue;
      }
      ans = min(ans, x - *t2 + max((long long)0, y + *t2 - maxv));
      cout << ans << endl;
    }
  }
  return 0;
}
