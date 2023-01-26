#include <bits/stdc++.h>
using namespace std;
const long long int mod = 998244353;
long long int trk[500010];
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long int i, j, k, a, b, c, x, y, z, n, m, ans, t;
  cin >> t;
  while (t--) {
    cin >> n;
    ans = 0;
    for (i = 0; i < n + 1; i++) trk[i] = 0;
    for (i = 0; i < n; i++) {
      cin >> x;
      ans += trk[x];
      trk[x] *= 2;
      ans %= mod;
      trk[x] %= mod;
      if (x - 1 < 0) {
        trk[x]++;
        ans++;
      } else {
        trk[x] += trk[x - 1];
        ans += trk[x - 1];
      }
      trk[x] %= mod;
      ans %= mod;
      if (x == 1)
        ans++;
      else if (x > 1)
        ans += trk[x - 2];
      ans %= mod;
    }
    cout << ans << "\n";
  }
}
