#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    if (n > s) {
      cout << "0" << endl;
    } else if (n == 1) {
      cout << s << endl;
    } else {
      m = (n + 1) / 2;
      int x = n - m + 1;
      cout << s / x << endl;
    }
  }
}
