#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    long long int x, n;
    cin >> x >> n;
    long long int ans;
    if (x % 2 == 0) {
      if (n % 4 == 0)
        ans = x;
      else if (n % 4 == 1)
        ans = x - n;
      else if (n % 4 == 2)
        ans = x + 1;
      else if (n % 4 == 3)
        ans = x + 1 + n;
      cout << ans << "\n";
    } else {
      if (n % 4 == 0)
        ans = x;
      else if (n % 4 == 1)
        ans = x + n;
      else if (n % 4 == 2)
        ans = x - 1;
      else if (n % 4 == 3)
        ans = x - 1 - n;
      cout << ans << "\n";
    }
  }
}
