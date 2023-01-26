#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int ans = floor(sqrt(n)) + floor(cbrt(n)) - floor(sqrt(cbrt(n)));
    cout << ans << endl;
  }
  return 0;
}
