#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007ll;
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0, base = 1;
    while (k) {
      if (k & 1) ans = (ans + base) % mod;
      base = (base * n) % mod;
      k >>= 1;
    }
    cout << ans << endl;
  }
  return 0;
}
