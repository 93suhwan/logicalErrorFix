#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long k, T, t, n, m, ans, cnt;
long long a[N], res[N];
bool vis[N];
priority_queue<long long, vector<long long>, greater<long long> > q;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
      cout << a[1] << '\n';
      continue;
    }
    if (n % 2 == 0) {
      for (long long i = n; i >= 1; i--) {
        if (i % 2)
          cout << -a[i] << " ";
        else
          cout << a[i] << " ";
      }
      cout << '\n';
    } else {
      for (long long i = n, j = 4; i >= 4; j++, i--) {
        if (i % 2)
          res[i] = a[j];
        else
          res[i] = -a[j];
      }
      res[1] = res[2] = -a[3];
      res[3] = a[1] + a[2];
      for (long long i = 1; i <= n; i++) cout << res[i] << " ";
      cout << '\n';
    }
  }
  return 0;
}
