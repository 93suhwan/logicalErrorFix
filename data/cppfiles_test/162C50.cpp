#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using ld = long double;
const long long N = 2e5 + 10, mod = 1e9 + 7;
const LL INF = 1e16;
long long dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
long long n;
long long a[N], b[N], c[N];
bool check(long long x) {
  for (long long i = 1; i <= n; i++) b[i] = 0, c[i] = a[i];
  for (long long i = n; i >= 3; i--) {
    if (c[i] + b[i] < x) return 0;
    long long l = min((c[i] + b[i] - x) / 3, c[i] / 3);
    c[i] -= 3 * l;
    b[i - 1] += l;
    b[i - 2] += 2 * l;
  }
  long long ans = INF;
  for (long long i = 1; i <= n; i++) {
    ans = min(ans, b[i] + c[i]);
  }
  return ans >= x;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    long long l = 1, r = 1e16;
    while (l < r) {
      long long mid = l + r + 1 >> 1;
      if (check(mid))
        l = mid;
      else
        r = mid - 1;
    }
    cout << l << '\n';
  }
}
