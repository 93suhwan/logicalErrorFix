#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int res = (int)sqrt(n) + (int)cbrt(n) - (int)(sqrt(cbrt(n)));
    cout << res << endl;
  }
  return 0;
}
