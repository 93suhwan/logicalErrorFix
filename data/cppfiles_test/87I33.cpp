#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 998244353;
long long t, n, m, k, tmp;
long long a[N];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    long long mx = 0, m_id = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] > mx) {
        mx = a[i];
        m_id = i;
      }
    }
    bool flag = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] > i) flag = 1;
    if (flag)
      cout << mx - m_id << "\n";
    else
      cout << 0 << "\n";
  }
  return 0;
}
