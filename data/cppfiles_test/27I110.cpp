#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using PLL = pair<long long, long long>;
using VLL = vector<long long>;
using VI = vector<int>;
inline void fastio() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fL;
const int mod1 = 998244353;
const int mod2 = 1e9 + 7;
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k <= 1) {
    cout << "NO" << endl;
    return;
  }
  if (m < n - 1) {
    cout << "NO" << endl;
    return;
  }
  long long cnt = 1ll * n * (n - 1) / 2;
  if (k == 2 && n > 1) {
    cout << "NO" << endl;
    return;
  }
  if (k == 2 && n == 1) {
    cout << "YES" << endl;
    return;
  }
  if (k > 3) {
    cout << "YES" << endl;
    return;
  }
  if (m >= cnt) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
signed main() {
  fastio();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
