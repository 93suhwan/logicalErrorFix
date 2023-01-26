#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, n;
    cin >> x >> n;
    long long ans;
    if (abs(x) % 2 == 0) {
      if (n % 4 == 0)
        ans = x;
      else if ((n - 1) % 4 == 0)
        ans = x - n;
      else if ((n - 2) % 4 == 0)
        ans = x + 1;
      else if ((n - 3) % 4 == 0)
        ans = x + n + 1;
    } else {
      if (n % 4 == 0)
        ans = x;
      else if ((n - 1) % 4 == 0)
        ans = x + n;
      else if ((n - 2) % 4 == 0)
        ans = x - 1;
      else if ((n - 3) % 4 == 0)
        ans = x - n - 1;
    }
    cout << ans << endl;
  }
}
