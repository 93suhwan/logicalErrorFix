#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
void solve() {
  long long n;
  cin >> n;
  if (n % 2 == 0) {
    cout << n - 3 << " " << 2 << " " << 1 << endl;
  } else {
    cout << n / 2 + 1 << " " << n / 2 - 1 << " " << 1 << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
