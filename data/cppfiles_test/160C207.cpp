#include <bits/stdc++.h>
using namespace std;
const long long int mod1 = 1e9 + 7, inf = 9e18, mod2 = 998244353;
const long double pi = 2 * acos(0.0), eps = 1e-12;
long long int tc, n, m, rb, cb, rd, cd;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  for (; tc--;) {
    cin >> n >> m >> rb >> cb >> rd >> cd;
    long long int ans;
    ans = (rb > rd ? n - rd + n - rb : rd - rb);
    ans = min(ans, (cb > cd ? m - cb + m - cd : cd - cb));
    cout << ans << "\n";
  }
  return 0;
}
