#include <bits/stdc++.h>
using namespace std;
int main() {
  long long mod = 1e9 + 7;
  int t;
  cin >> t;
  while (t--) {
    long long n, ans = 1;
    cin >> n;
    for (int i = 3; i <= 2 * n; i++) {
      ans = (ans * i) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}
