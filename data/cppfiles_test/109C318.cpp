#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 998244353;
long long t, n, m, k, q, tmp;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    ans += s[n - 1] - '0';
    for (int i = n - 2; i >= 0; i--) {
      if (s[i] - '0' > 0) ans += s[i] - '0' + 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
