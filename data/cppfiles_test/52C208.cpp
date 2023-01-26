#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void solve() {
  long long n, k;
  cin >> n >> k;
  long long ans = 0, pow = 1;
  while (k > 1) {
    if (k % 2 == 1) ans += pow;
    ans %= M;
    pow *= n;
    pow %= M;
    k /= 2;
  }
  if (k == 1) ans += pow;
  cout << ans % M << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
