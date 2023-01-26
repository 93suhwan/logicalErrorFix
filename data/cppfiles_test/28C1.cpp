#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
      cout << 0 << "\n";
    else {
      int total = a * 1 + b * 2 + c * 3;
      int avgtime = total / 2;
      int ans = total - avgtime;
      cout << abs(ans - avgtime) << "\n";
    }
  }
  return 0;
}
