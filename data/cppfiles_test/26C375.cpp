#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  long long fact = 1;
  for (long long i = 3; i <= 2 * n; i++) {
    fact = (fact * i) % M;
  }
  cout << fact << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
