#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x0, t;
    cin >> x0 >> t;
    if (x0 % 2 == 0) {
      int temp = t % 4;
      long long ans = 0;
      if (temp == 3)
        ans = (-1) * (t - 2) + (t - 1) + t;
      else if (temp == 2)
        ans = (-1) * (t - 1) + t;
      else if (temp == 1)
        ans = (-1) * t;
      ans += x0;
      cout << ans << endl;
    } else {
      int temp = t % 4;
      long long ans = 0;
      if (temp == 3)
        ans = (t - 2) - (t - 1) - t;
      else if (temp == 2)
        ans = (t - 1) - t;
      else if (temp == 1)
        ans = t;
      ans += x0;
      cout << ans << endl;
    }
  }
}
