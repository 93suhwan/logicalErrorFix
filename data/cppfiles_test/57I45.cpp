#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long second, n, k;
  cin >> second >> n >> k;
  if (second >= (n / k * 2 * k + n - n / k)) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n = 1;
  cin >> n;
  while (n--) {
    solve();
  }
}
