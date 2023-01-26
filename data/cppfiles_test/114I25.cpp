#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 50;
const long long M = 1e6 + 50;
long long a[N];
long long vis[M];
signed main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T;
  cin >> T;
  while (T--) {
    memset(vis, 0, sizeof(vis));
    long long n;
    cin >> n;
    long long p = INT_MAX;
    for (long long i = 1; i <= n; i++)
      cin >> a[i], vis[a[i]] = 1, p = min(p, a[i]);
    long long cnt = 0;
    for (long long i = p + 1; i <= 1e6; i++) {
      if (vis[i]) {
        cout << p << " " << i << endl;
        cnt++;
      }
      if (cnt == n / 2) break;
    }
  }
  return 0;
}
