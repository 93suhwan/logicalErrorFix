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
        cout << i << " " << n << " " << i + 1 << " " << n << endl;
        f = 1;
        break;
      }
    }
    if (f == 1)
      continue;
    else {
      f = 0;
      for (int i = 1; i <= n; ++i) {
        if (s[i] == '0') {
          f = i;
          break;
        }
      }
      if (f != 0)
        cout << 1 << " " << f << " " << 1 << " " << f - 1 << endl;
      else
        cout << 1 << " " << n - 1 << " " << 2 << " " << n << endl;
    }
  }
  return 0;
}
