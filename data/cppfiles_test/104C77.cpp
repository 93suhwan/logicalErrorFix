#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 10;
long long aa[maxn], bb[maxn], xx[maxn], yy[maxn];
void solve() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  long long a = 0, b = 0;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld", &aa[i], &bb[i]);
    long long tmp = min(aa[i], m);
    xx[i] = tmp;
    yy[i] = m - tmp;
    a += (aa[i] - xx[i]);
    b += (bb[i] - yy[i]);
  }
  for (long long i = 1; i <= n && (b - a) >= 2; i++) {
    long long tmp = min((b - a) / 2, (long long)min(xx[i], bb[i] - yy[i]));
    xx[i] -= tmp;
    yy[i] += tmp;
    a += tmp;
    b -= tmp;
  }
  cout << abs(b - a) << endl;
  for (long long i = 1; i <= n; i++) printf("%lld %lld\n", xx[i], yy[i]);
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
