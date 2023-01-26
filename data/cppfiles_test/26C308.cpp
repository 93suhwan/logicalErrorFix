#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, i, n, ans, r;
  long long m = 1e9 + 7;
  cin.tie(0)->sync_with_stdio(0);
  cin >> t;
  for (i = 0; i < t; i++) {
    cin >> n;
    r = n;
    n *= 2;
    n--;
    ans = 1;
    while (n > 0) {
      ans *= n;
      ans %= m;
      n--;
    }
    ans *= r;
    ans %= m;
    cout << ans << "\n";
  }
  return 0;
}
