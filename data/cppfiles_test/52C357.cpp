#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long double t;
  cin >> t;
  while (t--) {
    long long k, n;
    cin >> n >> k;
    long long ans = 0, mod = 1e9 + 7, val = 1;
    for (int i = 0; i < 32; i++) {
      if ((k >> i) & 1) {
        ans += val;
        ans %= mod;
      }
      val *= n;
      val %= mod;
    }
    cout << ans << "\n";
  }
}
