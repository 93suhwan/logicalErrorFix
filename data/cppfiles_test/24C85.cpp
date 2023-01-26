#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n < 9) {
      cout << "0\n";
    } else if (n == 9) {
      cout << "1\n";
    } else {
      int ans = n / 10;
      if (n % 10 == 9) ans++;
      cout << ans << "\n";
    }
  }
  return 0;
}
