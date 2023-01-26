#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
long long pw(long long x, long long y) {
  long long ans = 1;
  while (y > 0) {
    if (y % 2) ans = (ans * x) % 1000000007;
    x = (x * x) % 1000000007;
    y = y / 2;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    for (long long i = 0; i < 32; i++) {
      if ((1LL << i) & k) {
        ans = (ans + pw(n, i)) % 1000000007;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
