#include <bits/stdc++.h>
using namespace std;
int log_a_to_base_b(int a, int b) { return log(a) / log(b); }
void solve() {
  int n;
  cin >> n;
  cout << floor(pow(n, 1.0 / 2) + pow(n, 1.0 / 3) - pow(n, 1.0 / 6)) << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
