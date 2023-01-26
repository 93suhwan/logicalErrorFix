#include <bits/stdc++.h>
constexpr int maxn = 15;
constexpr int inf = 1e9;
constexpr int mod = 1e9 + 7;
using namespace std;
using lint = long long;
using pii = pair<int, int>;
int t, n, a[maxn];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < (1 << n); i++)
      for (int j = i;; j = (j - 1) & i) {
        int sum = 0;
        for (int k = 0; k < n; k++) {
          if (!(i & (1 << k))) continue;
          sum += ((j & (1 << k)) ? -1 : 1) * a[k];
        }
        if (sum == 0) goto label;
        if (j == 0) break;
      }
    cout << "NO" << '\n';
    continue;
  label:
    cout << "YES" << '\n';
  }
}
