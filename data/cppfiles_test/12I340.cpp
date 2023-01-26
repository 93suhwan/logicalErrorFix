#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, m, k;
  cin >> n >> m >> k;
  auto check = [&]() {
    if (n & 1) {
      for (long long int j = 1; j <= m; j += 2) {
        if (!k) {
          return 0;
        }
        --k;
      }
      n--;
    }
    for (long long int j = 1; j <= m and k > 0; j += 2) {
      long long int canTake = min(n, k);
      if (canTake & 1) {
        canTake--;
      }
      k -= canTake;
    }
    if (k) return 0;
    return 1;
  };
  cout << (check() ? "YES" : "NO") << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int T = 1;
  cin >> T;
  for (long long int i = 1; i <= T; ++i) {
    solve();
  }
  return 0;
}
