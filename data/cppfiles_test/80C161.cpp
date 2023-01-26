#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, i, j, f, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    f = 0;
    for (i = 0; i < n; i++)
      if (s[i] == '0') {
        f = 1;
        if (i >= n / 2)
          cout << 1 << ' ' << i + 1 << ' ' << 1 << ' ' << i << endl;
        else
          cout << i + 1 << ' ' << n << ' ' << i + 2 << ' ' << n << endl;
        break;
      }
    if (!f) cout << 1 << ' ' << n - 1 << ' ' << 2 << ' ' << n << endl;
  }
  return 0;
}
