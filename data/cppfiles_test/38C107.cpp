#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long int n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long int ans;
    if (n <= 6)
      cout << 15 << endl;
    else if (n <= 8)
      cout << 20 << endl;
    else if (n <= 10)
      cout << 25 << endl;
    else {
      ans = 5 * ((n + 1) / 2);
      cout << ans << endl;
    }
  }
  return 0;
}
