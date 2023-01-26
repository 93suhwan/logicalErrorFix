#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], vt, res, p, q, sum;
void xuly() {
  cin >> p >> q;
  res = p + q;
  vt = lower_bound(a + 1, a + n + 1, p) - a;
  if (vt < n + 1) res = min(res, max(q - sum + a[vt], 0LL));
  if (vt > 1) res = min(res, p - a[vt - 1] + max(q - sum + a[vt - 1], 0LL));
  cout << res << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int sl;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + n + 1);
  cin >> sl;
  while (sl--) xuly();
}
