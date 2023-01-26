#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  if (n == 0) {
    cout << -1 << " " << 1 << "\n";
  }
  cout << -n + 1 << " " << n << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
