#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 5;
long long k, T, t, n, m, ans, cnt;
long long a[N], stk[N], tt;
bool vis[N];
priority_queue<long long, vector<long long>, greater<long long> > q;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> T;
  while (T--) {
    cin >> n;
    tt = 0;
    for (long long i = 1; i <= n; i++) cin >> a[i];
    if (n % 2 == 0)
      cout << "YES" << '\n';
    else {
      bool flag = false;
      for (long long i = 2; i <= n; i++) {
        if (a[i] <= a[i - 1]) {
          flag = true;
          break;
        }
      }
      if (flag)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
