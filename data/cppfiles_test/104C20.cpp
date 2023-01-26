#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int T, n, m;
int a[N], b[N], l[N], r[N], ans[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> n >> m;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
      sum += a[i] - b[i] + m;
      l[i] = max(0, m - b[i]);
      r[i] = min(a[i], m);
      sum -= 2 * l[i];
      ans[i] = l[i];
    }
    for (int i = 1; i <= n; i++) {
      if (sum > 0) {
        long long t = min(sum / 2, (long long)r[i] - l[i]);
        sum -= t * 2;
        ans[i] += t;
      }
    }
    cout << (long long)abs(sum) << '\n';
    for (int i = 1; i <= n; i++) cout << ans[i] << " " << m - ans[i] << '\n';
  }
  return 0;
}
