#include <bits/stdc++.h>
using namespace std;
string s;
int n, f;
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> s;
    s = "0" + s;
    int x = n + 1 - n / 2;
    f = 0;
    for (int i = 1; i < x; ++i) {
      if (s[i] == '0') {
        cout << i << " " << n << " " << x << " " << n << endl;
        f = 1;
        break;
      }
    }
    if (f == 1)
      continue;
    else {
      cout << 1 << " " << int(n / 2) << " " << 2 << " " << int(n / 2) + 1
           << endl;
    }
  }
  return 0;
}
