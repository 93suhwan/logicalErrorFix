#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, k, p = 1;
    long long ans = 0;
    cin >> n >> k;
    for (long long i = 0; i < 32; i++) {
      if (k >> i & 1) ans = (ans + p) % mod;
      p *= n;
      p %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}
