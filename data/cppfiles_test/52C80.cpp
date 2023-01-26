#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long x = 1;
    long long ans = 0;
    while (k > 0) {
      if (k & 1) {
        ans = (ans + x) % 1000000007;
      }
      k >>= 1;
      x = x * n % 1000000007;
    }
    cout << ans << "\n";
  }
}
