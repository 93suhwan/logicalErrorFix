#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> n;
    long long ans = -1;
    for (int i = 1; i <= n; i++) {
      cin >> x;
      ans = max(ans, abs(x - i));
    }
    cout << ans << endl;
  }
  return 0;
}
