#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    long long pw = 1;
    for (long long i = 0; i < 60; i++) {
      if (k & (1ll << i)) {
        ans += pw;
        ans %= 1000000007;
      }
      pw *= n;
      pw %= 1000000007;
    }
    cout << ans << "\n";
  }
  return 0;
}
