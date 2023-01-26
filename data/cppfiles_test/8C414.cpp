#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n % 3 == 0) {
    cout << n / 3 << ' ' << n / 3;
    cout << '\n';
    return;
  }
  if (n % 3 == 2) {
    cout << n / 3 << ' ' << n / 3 + 1;
    cout << '\n';
    return;
  }
  cout << n / 3 + 1 << ' ' << n / 3;
  cout << '\n';
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long _ = 1;
  cin >> _;
  for (long long i = 1; i <= _; i++) {
    solve();
  }
  return 0;
}
