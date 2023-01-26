#include <bits/stdc++.h>
using namespace std;
const long long int g_inf{long long int(1e9 + 7)};
void solve() {
  int n{0}, k{0};
  cin >> n >> k;
  long long int ans{0};
  long long int pow{1};
  for (int i{0}; i <= 9; i++) {
    if (k & (1 << i)) {
      ans = (ans + pow) % g_inf;
    }
    pow = (pow * n) % g_inf;
  }
  cout << ans;
}
int main() {
  int t{0};
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  cout << '\n';
  return 0;
}
