#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
long long multiply(long long x, long long y) {
  int mod = (1e9 + 7);
  return (x * 1ll * y) % mod;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int res = 1;
    for (int i = 3; i <= 2 * n; i++) {
      res = multiply(res, i);
    }
    cout << res << endl;
  }
}
