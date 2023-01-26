#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b;
  cin >> a;
  if (a == 5) {
    cout << 2 << " " << 4 << "\n";
    return;
  }
  cout << 2 << " " << (a / 2) << "\n";
  return;
}
signed main() {
  long long t = 1;
  cin >> t;
  while (t > 0) {
    t--;
    solve();
  }
}
