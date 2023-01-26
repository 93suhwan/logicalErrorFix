#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int ans = 0;
    int a, b;
    cin >> a >> b;
    if (a == b && b == 0)
      ans = 0;
    else if (a == b)
      ans = 1;
    else {
      if (abs(a - b) & 1)
        ans = -1;
      else
        ans = 2;
    }
    cout << ans << endl;
  }
}
