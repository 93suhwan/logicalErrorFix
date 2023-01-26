#include <bits/stdc++.h>
using namespace std;
const long long M = 1e6 + 5;
const long long mod = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  long long a = n / 10;
  long long b = n % 10;
  long long ans = a + (b == 9);
  cout << ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long T = 1;
  cin >> T;
  while (T-- > 0) {
    solve();
    cout << '\n';
  }
  return 0;
}
