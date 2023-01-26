#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int tests;
  cin >> tests;
  while (tests--) {
    int n;
    cin >> n;
    long long ans = 1;
    int mod = 1e9 + 7;
    for (int i = 1; i <= 2 * n; ++i) {
      if (i == 2) {
        continue;
      }
      ans *= 1LL * i;
      ans %= mod;
    }
    cout << ans << '\n';
  }
  return 0;
}
