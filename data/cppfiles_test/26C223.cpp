#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long ans = 1, mod = 1e9 + 7;
    for (int i = 2 * n; i >= 3; i--) {
      ans = (ans * i) % mod;
    }
    ans %= mod;
    cout << ans << "\n";
  }
  return 0;
}
