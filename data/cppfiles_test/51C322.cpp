#include <bits/stdc++.h>
using namespace std;
void Fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
void solve() {
  long long n;
  cin >> n;
  if (n == 1) {
    cout << "0 1";
  } else {
    cout << -1 * (n - 1) << " " << n;
  }
  cout << "\n";
}
int main() {
  Fast();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
