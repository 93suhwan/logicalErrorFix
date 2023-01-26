#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long T = 1;
  while (T--) {
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    char a[3] = {'a', 'b', 'c'};
    long long cost[6][n + 1];
    memset(cost, 0, sizeof(cost));
    long long k = 0;
    do {
      for (long long i = 0; i < n; i++) {
        if (s[i] != a[i % 3]) {
          cost[k][i + 1]++;
        }
        cost[k][i + 1] += cost[k][i];
      }
      k++;
    } while (next_permutation(a, a + 3));
    while (m--) {
      long long l, r;
      cin >> l >> r;
      long long ans = 1e9;
      for (long long i = 0; i < k; i++) {
        ans = min(ans, cost[i][r] - cost[i][l - 1]);
      }
      cout << ans << '\n';
    }
  }
  return 0;
}
