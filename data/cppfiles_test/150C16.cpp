#include <bits/stdc++.h>
using namespace std;
int n;
long long a[110], ans;
void solve() {
  int n;
  cin >> n;
  ans = 1e18;
  for (int i = 0; i < n; i++) cin >> a[i];
  long long coins = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 3 != 0) {
      coins = 1e17;
      break;
    }
    coins = max(coins, a[i] / 3);
  }
  ans = min(ans, coins);
  coins = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 3 == 2) {
      coins = 1e17;
      break;
    }
    coins = max(coins, a[i] / 3);
  }
  ans = min(ans, coins + 1);
  coins = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 3 == 1) {
      coins = 1e17;
      break;
    } else {
      coins = max(coins, a[i] / 3);
    }
  }
  ans = min(ans, coins + 1);
  coins = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      coins = 1e17;
      break;
    }
    if (a[i] % 3 == 1)
      coins = max(coins, (a[i] - 4) / 3);
    else
      coins = max(coins, a[i] / 3);
  }
  ans = min(ans, coins + 2);
  coins = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 3 == 0)
      coins = max(coins, a[i] / 3 - 1);
    else
      coins = max(coins, a[i] / 3);
  }
  ans = min(ans, coins + 2);
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
