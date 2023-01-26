#include <bits/stdc++.h>
using namespace std;
long long n;
const long long maxn = 2e5 + 5;
long long a[maxn];
double ave;
void solve() {
  cin >> n;
  long long sum = 0;
  for (long long i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
    a[i] *= n;
  }
  sort(a + 1, a + 1 + n);
  long long res = 0;
  for (long long i = 1; i <= n; ++i) {
    auto p1 = lower_bound(a + i + 1, a + 1 + n, 2 * sum - a[i]);
    auto p2 = upper_bound(a + i + 1, a + 1 + n, 2 * sum - a[i]);
    res += p2 - p1;
  }
  cout << res << '\n';
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
