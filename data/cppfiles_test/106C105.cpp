#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7ll;
inline void init_code() {}
void solve() {
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    cout << i + 2 << " ";
  }
  cout << '\n';
}
int32_t main() {
  init_code();
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
