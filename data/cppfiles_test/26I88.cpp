#include <bits/stdc++.h>
using namespace std;
long long MOD = 10e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n, ans = 1;
    cin >> n;
    for (long long i = 1; i <= n + n; i++) {
      if (i != 2) {
        ans = ans * i;
        ans = ans % MOD;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
