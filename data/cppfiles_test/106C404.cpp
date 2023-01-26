#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
using ii = pair<long long, long long>;
long long power(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    y = y / 2, x = (x * x) % mod;
  }
  return res % mod;
}
void solve() {
  long long n;
  cin >> n;
  for (long long i = 2; i <= n + 1; i++) {
    cout << i << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
