#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    long long int num = 2 * abs(a - b);
    if (a > num || b > num || c > num) {
      cout << "-1" << endl;
    } else {
      long long int ans = c - min(a, b) + max(a, b);
      if (ans < 0) {
        ans = num + ans;
      } else if (ans > num) {
        ans = ans - num;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
