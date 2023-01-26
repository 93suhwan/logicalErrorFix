#include <bits/stdc++.h>
using namespace std;
using lint = long long;
constexpr long long maxn = 2e5 + 5;
constexpr long long inf = 1e9;
constexpr long long mod = 1e9 + 7;
long long t, n, m, k;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    k -= 2;
    string ans;
    if (k < 0)
      ans = "NO";
    else if (m < n - 1 || m > n * (n - 1) / 2)
      ans = "NO";
    else if (k == 0 && n > 1)
      ans = "NO";
    else if (k == 1 && m < n * (n - 1) / 2 && n > 2)
      ans = "NO";
    else
      ans = "YES";
    cout << ans << '\n';
  }
}
