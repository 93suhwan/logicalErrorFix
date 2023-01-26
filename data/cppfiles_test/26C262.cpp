#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    unsigned long long ans = 1;
    cin >> n;
    n += n;
    for (int i = 3; i <= n; i++) {
      ans *= i;
      ans %= 1000000007;
    }
    cout << ans << endl;
  }
  return 0;
}
