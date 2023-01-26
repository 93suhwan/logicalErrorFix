#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, s, n;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    if (n > s)
      cout << 0 << endl;
    else if (n % 2 == 0)
      cout << (2 * s) / (n + 2) << endl;
    else
      cout << (2 * s) / (n + 1) << endl;
  }
  return 0;
}
