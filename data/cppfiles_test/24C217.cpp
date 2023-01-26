#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  cout << n / 10 + (n % 10 == 9 ? 1 : 0) << endl;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) solve();
}
