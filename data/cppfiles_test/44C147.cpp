#include <bits/stdc++.h>
using namespace std;
const int mn = 1e6 + 7;
const int mm = 1e4 + 5;
const int mod = 1e9 + 7;
int main(int argc, char const *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int c, d;
    cin >> c >> d;
    if (c == d && c == 0) {
      cout << 0 << '\n';
      continue;
    }
    if (c == d)
      cout << 1 << '\n';
    else {
      if (c % 2 != d % 2)
        cout << -1 << '\n';
      else {
        cout << 2 << '\n';
      }
    }
  }
  return 0;
}
