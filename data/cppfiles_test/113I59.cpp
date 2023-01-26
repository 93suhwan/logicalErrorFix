#include <bits/stdc++.h>
using namespace std;
long long T, n, m, a[200005];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  long long sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i];
  cin >> m;
  while (m--) {
    long long x, y;
    cin >> x >> y;
    int q = lower_bound(a + 1, a + 1 + n, x) - a, p = max(1, q - 1);
    int u = lower_bound(a + 1, a + 1 + n, y) - a, v = max(1, u - 1);
    long long ans = min(max(0ll, x - a[q]) + max(0ll, y - sum + a[q]),
                        max(0ll, x - a[p]) + max(0ll, y - sum + a[p]));
    ans = min(ans, min(max(0ll, x - a[u]) + max(0ll, y - sum + a[u]),
                       max(0ll, x - a[v]) + max(0ll, y - sum + a[v])));
    cout << ans << endl;
  }
}
