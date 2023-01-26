#include <bits/stdc++.h>
using namespace std;
const long long k1 = 1e9 + 7;
long long ans;
int main() {
  int n, t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> n;
    ans = 1;
    for (int j = 3; j <= 2 * n; j++) {
      ans *= j;
      ans = ans % k1;
    }
    cout << ans << endl;
  }
  return 0;
}
