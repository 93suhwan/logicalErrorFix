#include <bits/stdc++.h>
using namespace std;
long long a, b, p;
void solve() {
  cin >> p;
  if (p == 5)
    cout << 2 << ' ' << 4 << '\n';
  else {
    p--;
    cout << 2 << ' ' << p / 2 << '\n';
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
