#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, t, n, m, s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    if ((n + 1) / 2 > s) {
      cout << "0" << endl;
    } else if (n == 1) {
      cout << s << endl;
    } else {
      m = (n + 1) / 2;
      x = n - m + 1;
      cout << s / x << endl;
    }
  }
}
