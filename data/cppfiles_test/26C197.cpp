#include <bits/stdc++.h>
using namespace std;
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
        ans = ans % 1000000007;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
