#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  if (n <= 8) {
    cout << "0\n";
  } else if (n == 9) {
    cout << "1\n";
  } else if (n % 10 == 9)
    cout << (n / 10) + 1 << "\n";
  else
    cout << n / 10 << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
