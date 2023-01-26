#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y) {
    if (y % 2) {
      res = (res * x) % 1000000007;
    }
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  long long int ans = 1;
  for (long long int i = 0; i < n; i++) {
    ans *= 2;
  }
  ans -= 2;
  ans = power(4, ans);
  ans *= 6;
  ans = ans % 1000000007;
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
