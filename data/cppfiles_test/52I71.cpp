#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<long long> sum(32, 0), pn(32, 0);
    sum[0] = 1, pn[0] = 1;
    for (int i = 1; i < 31; i++) {
      pn[i] = (pn[i - 1] * n) % mod;
      sum[i] = ((1ll << i) * pn[i] % mod + sum[i - 1]) % mod;
    }
    vector<long long> rank(32, 1);
    rank[0] = 1;
    for (int i = 1; i < 31; i++) {
      rank[i] = (1ll << i) + rank[i - 1];
    }
    if (k == 1) {
      cout << 1 << "\n";
      continue;
    }
    while (k > 0) {
      int p = 0;
      for (int i = 0; i < 31; i++) {
        if (rank[i] > k) {
          p = i;
          break;
        }
      }
      ans = (ans + pn[p]) % mod;
      k = k - rank[p - 1] - 1;
    }
    cout << ans << '\n';
  }
  return 0;
}
