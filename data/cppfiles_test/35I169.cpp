#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  for (int k = 30; k >= 0; k--) {
    if (n > m) break;
    int nbit = ((n >> k) & 1);
    int mbit = ((m >> k) & 1);
    if (nbit == 0) {
      if (mbit == 1) {
        ans ^= (1 << k);
        m ^= (1 << k);
      }
    } else {
      if (mbit == 1) {
        n ^= (1 << k);
        m ^= (1 << k);
      } else {
        cerr << n << ' ' << m << endl;
        assert(false);
      }
    }
  }
  if (n == 0 && m == 0) ans++;
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
