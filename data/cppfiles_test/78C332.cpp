#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
const int M = 1e9 + 7;
void solve() {
  long long l, r;
  cin >> l >> r;
  long long b = (r + 1) / 2;
  b = max(b, l);
  cout << ((min(r, 2 * b - 1)) % b) << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
