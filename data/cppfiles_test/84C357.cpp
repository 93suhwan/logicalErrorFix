#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i, j, d, s;
  cin >> t;
  while (t--) {
    d = 0;
    cin >> n >> s;
    if (n == 1)
      cout << s << endl;
    else if (n == 2)
      cout << s / 2 << endl;
    else {
      if (n % 2 == 0) {
        d = n - ((n / 2) - 1);
        cout << s / d << endl;
      } else {
        d = n - (n / 2);
        cout << s / d << endl;
      }
    }
  }
  return 0;
}
