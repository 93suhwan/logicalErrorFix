#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n % 3 == 0) {
    cout << n / 3 << ' ' << n / 3;
  } else if (n % 3 == 1) {
    cout << n / 3 + 1 << ' ' << n / 3;
  } else {
    cout << n / 3 << ' ' << n / 3 + 1;
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
}
