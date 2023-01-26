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
    for (long long i = 1; i <= n; i++) cin >> a[i], vis[a[i]] = 1;
    sort(a + 1, a + n + 1);
    long long cnt = 0;
    for (long long i = 1; i < n; i++) {
      long long next = i + 1;
      while (a[i] != a[next] && vis[a[next] % a[i]] == 0 && next + 1 <= n)
        next++;
      cout << a[next] << " " << a[i] << endl;
      cnt++;
      if (cnt == n / 2) break;
    }
  }
  return 0;
}
